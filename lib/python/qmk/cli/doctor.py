"""QMK Doctor

Check out the user's QMK environment and make sure it's ready to compile.
"""
import platform
from subprocess import DEVNULL

from milc import cli
from milc.questions import yesno
from qmk import submodules
from qmk.questions import yesno
from qmk.commands import run


def os_tests():
    """Determine our OS and run platform specific tests
    """
    ok = True
    udev_dir = Path("/etc/udev/rules.d/")
    desired_rules = {
        'dfu': {_udev_rule("03eb", "2ff4"), _udev_rule("03eb", "2ffb"), _udev_rule("03eb", "2ff0")},
        'tmk': {_udev_rule("feed")},
        'input_club': {_udev_rule("1c11")},
        'stm32': {_udev_rule("1eaf", "0003"), _udev_rule("0483", "df11")},
        'caterina': {'ATTRS{idVendor}=="2a03", ENV{ID_MM_DEVICE_IGNORE}="1"', 'ATTRS{idVendor}=="2341", ENV{ID_MM_DEVICE_IGNORE}="1"'},
    }

    if udev_dir.exists():
        udev_rules = [str(rule_file) for rule_file in udev_dir.glob('*.rules')]
        current_rules = set()

        # Collect all rules from the config files
        for rule_file in udev_rules:
            with open(rule_file, "r") as fd:
                for line in fd.readlines():
                    line = line.strip()
                    if not line.startswith("#") and len(line):
                        current_rules.add(line)

        # Check if the desired rules are among the currently present rules
        for bootloader, rules in desired_rules.items():
            if not rules.issubset(current_rules):
                # If the rules for catalina are not present, check if ModemManager is running
                if bootloader == "caterina":
                    if check_modem_manager():
                        ok = False
                        cli.log.warn("{bg_yellow}Detected ModemManager without udev rules. Please either disable it or set the appropriate udev rules if you are using a Pro Micro.")
                else:
                    cli.log.warn("{bg_yellow}Missing udev rules for '%s' boards. You'll need to use `sudo` in order to flash them.", bootloader)

    return ok


def check_modem_manager():
    """Returns True if ModemManager is running.
    """
    if shutil.which("systemctl"):
        mm_check = run(["systemctl", "--quiet", "is-active", "ModemManager.service"], timeout=10)
        if mm_check.returncode == 0:
            return True

    else:
        cli.log.warn("Can't find systemctl to check for ModemManager.")


def is_executable(command):
    """Returns True if command exists and can be executed.
    """
    # Make sure the command is in the path.
    res = shutil.which(command)
    if res is None:
        cli.log.error("{fg_red}Can't find %s in your path.", command)
        return False

    # Make sure the command can be executed
    check = run([command, '--version'], stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=5, universal_newlines=True)
    ESSENTIAL_BINARIES[command]['output'] = check.stdout

    if check.returncode in [0, 1]:  # Older versions of dfu-programmer exit 1
        cli.log.debug('Found {fg_cyan}%s', command)
        return True

    cli.log.error("{fg_red}Can't run `%s --version`", command)
    return False


def os_test_linux():
    """Run the Linux specific tests.
    """
    # Don't bother with udev on WSL, for now
    if 'microsoft' in platform.uname().release.lower():
        cli.log.info("Detected {fg_cyan}Linux (WSL){fg_reset}.")

        # https://github.com/microsoft/WSL/issues/4197
        if QMK_FIRMWARE.as_posix().startswith("/mnt"):
            cli.log.warning("I/O performance on /mnt may be extremely slow.")
            return CheckStatus.WARNING

        return CheckStatus.OK
    else:
        cli.log.info("Detected {fg_cyan}Linux{fg_reset}.")
        from qmk.os_helpers.linux import check_udev_rules

        return check_udev_rules()


def os_test_macos():
    """Run the Mac specific tests.
    """
    cli.log.info("Detected {fg_cyan}macOS %s{fg_reset}.", platform.mac_ver()[0])

    return CheckStatus.OK


def os_test_windows():
    """Run the Windows specific tests.
    """
    win32_ver = platform.win32_ver()
    cli.log.info("Detected {fg_cyan}Windows %s (%s){fg_reset}.", win32_ver[0], win32_ver[1])

    return CheckStatus.OK


@cli.argument('-y', '--yes', action='store_true', arg_only=True, help='Answer yes to all questions.')
@cli.argument('-n', '--no', action='store_true', arg_only=True, help='Answer no to all questions.')
@cli.subcommand('Basic QMK environment checks')
def doctor(cli):
    """Basic QMK environment checks.

    This is currently very simple, it just checks that all the expected binaries are on your system.

    TODO(unclaimed):
        * [ ] Compile a trivial program with each compiler
    """
    cli.log.info('QMK Doctor is checking your environment.')
    cli.log.info('CLI version: %s', cli.version)
    cli.log.info('QMK home: {fg_cyan}%s', QMK_FIRMWARE)

    # Determine our OS and run platform specific tests
    platform_id = platform.platform().lower()

    if 'darwin' in platform_id or 'macos' in platform_id:
        if not os_test_macos():
            ok = False
    elif 'linux' in platform_id:
        if not os_test_linux():
            ok = False
    elif 'windows' in platform_id:
        if not os_test_windows():
            ok = False
    else:
        cli.log.error('Unsupported OS detected: %s', platform_id)
        ok = False

    # Make sure the basic CLI tools we need are available and can be executed.
    bin_ok = check_binaries()

    if not bin_ok:
        if yesno('Would you like to install dependencies?', default=True):
            run(['util/qmk_install.sh'])
            bin_ok = check_binaries()

    if bin_ok:
        cli.log.info('All dependencies are installed.')
    else:
        status = CheckStatus.ERROR

    # Make sure the tools are at the correct version
    ver_ok = check_binary_versions()
    if CheckStatus.ERROR in ver_ok:
        status = CheckStatus.ERROR
    elif CheckStatus.WARNING in ver_ok and status == CheckStatus.OK:
        status = CheckStatus.WARNING

    # Check out the QMK submodules
    sub_ok = check_submodules()

    if sub_ok == CheckStatus.OK:
        cli.log.info('Submodules are up to date.')
    else:
        if yesno('Would you like to clone the submodules?', default=True):
            submodules.update()
            sub_ok = check_submodules()

        if sub_ok == CheckStatus.ERROR:
            status = CheckStatus.ERROR
        elif sub_ok == CheckStatus.WARNING and status == CheckStatus.OK:
            status = CheckStatus.WARNING

    # Report a summary of our findings to the user
    if status == CheckStatus.OK:
        cli.log.info('{fg_green}QMK is ready to go')
        return 0
    elif status == CheckStatus.WARNING:
        cli.log.info('{fg_yellow}QMK is ready to go, but minor problems were found')
        return 1
    else:
        cli.log.info('{fg_red}Major problems detected, please fix these problems before proceeding.')
        cli.log.info('{fg_blue}Check out the FAQ (https://docs.qmk.fm/#/faq_build) or join the QMK Discord (https://discord.gg/Uq7gcHh) for help.')
        return 2
