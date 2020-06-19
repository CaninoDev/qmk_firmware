/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _FUNCTION,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define CA_F1 LCA_T(KC_F1)
#define CA_F2 LCA_T(KC_F2)
#define CA_F3 LCA_T(KC_F3)
#define CA_F4 LCA_T(KC_F4)
#define CA_F5 LCA_T(KC_F5)
#define CA_F6 LCA_T(KC_F6)
#define CA_F6 LCA_T(KC_F6)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LS/( |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | LGUI | Alt  |   [  |Lower |    Space    |Raise |   ]  | RGUI |   \  | RS/) |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,  KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,  KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,  KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_LBRC, LOWER, KC_SPC,KC_SPC, RAISE,   KC_RBRC, KC_RGUI, KC_BSLS, KC_RSPC),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LS/( |   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | LGUI | Alt  |   [  |Lower |    Space    |Raise |   ]  | RGUI |   \  | RS/) |
 * `-----------------------------------------------------------------------------------'
 */

[_COLEMAK] = LAYOUT_planck_mit(
        KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,  KC_G,   KC_J,   KC_L,    KC_U,     KC_Y,   KC_SCLN, KC_BSPC,
        KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,  KC_D,   KC_H,   KC_N,    KC_E,     KC_I,   KC_O,    KC_QUOT,
        KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_K,   KC_M,    KC_COMM,  KC_DOT, KC_SLSH, KC_ENT,
        KC_LCTL, KC_RALT, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_RBRC, KC_RGUI, KC_BSLS, KC_RSPC),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | LGUI | Alt  |   [  |Lower |    Space    |Raise |   ]  | RGUI |   \  | RS/) |
 * `-----------------------------------------------------------------------------------'
 */

[_DVORAK] = LAYOUT_planck_mit(
        KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,  KC_Y,   KC_F,   KC_G,  KC_C,    KC_R,    KC_L,    KC_BSPC,
        KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,  KC_I,   KC_D,   KC_H,  KC_T,    KC_N,    KC_S,    KC_SLSH,
        KC_LSPO, KC_SCLN, KC_Q,    KC_J,    KC_K,  KC_X,   KC_B,   KC_M,  KC_W,    KC_V,    KC_Z,    KC_ENT,
        KC_LCTL, KC_RALT, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_RBRC, KC_RGUI, KC_BSLS, KC_RSPC),

/* LOWER
 * ,----------------------------------------------------------------------------.
 * |      |      | MPRV | MPLY | MNXT |     |     |     | PGUP| UP  | PGDN|PSCR |
 * |------+------+------+------+------+-----+-----+-----+-----+-----------+-----+
 * |      |      | MUTE | VOLD | VOLU |     |     |     | LEFT| DOWN|RIGHT|     |
 * |------+------+------+------+------+-----+-----+-----+-----+-----+-----+-----+
 * |      |      | MAIL | WBAK | WFWD |     |     |     | HOME|     | END |     |
 * |------+------+------+------+------+-----+-----+-----+-----+-----------+-----+
 * |      |      |      |      |      |    DEL    |     |     |     |     |     |
 * `----------------------------------------------------------------------------'
 */

[_LOWER] = LAYOUT_planck_mit(
        KC_NO, KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,  KC_NO,  KC_NO, KC_PGUP, KC_UP,   KC_PGDN, KC_PSCR,
        KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,  KC_NO,  KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,
        KC_NO, KC_NO, KC_MAIL, KC_WBAK, KC_WFWD, KC_NO,  KC_NO,  KC_NO, KC_HOME, KC_NO,   KC_END,  KC_NO,
        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_DEL, KC_DEL, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO),

/* RAISE
 * ,--------------------------------------------------------------------------------.
 * | NLCK |  1   |  2   |  3   |  -   |     |     |     |  !   |  #   |  $   |  +   |
 * |------+------+------+------+------+-----+-----+-----+------+------+------+------+
 * |   /  |  4   |  5   |  6   |  +   |     |     |     |  %   |  !   |  !   |  =   |
 * |------+------+------+------+------+-----+-----+-----+------+------+------+------+
 * |   *  |  7   |  8   |  9   |  ,   |     |     |     |  _   |  -   |  @   |  ~   |
 * |------+------+------+------+------+-----+-----+-----+------+------+------+------+
 * |      |  0   |  .   | Ent  |  =   |           |     |      |      |      |  `   |
 * `--------------------------------------------------------------------------------'
 */

[_RAISE] = LAYOUT_planck_mit(
        KC_NLCK, KC_P1, KC_P2,   KC_P3,   KC_PMNS, KC_NO, KC_NO, KC_NO, KC_EXLM, KC_HASH, KC_DLR,  KC_PLUS,
        KC_PSLS, KC_P4, KC_P5,   KC_P6,   KC_PPLS, KC_NO, KC_NO, KC_NO, KC_PERC, KC_ASTR, KC_AMPR, KC_EQL,
        KC_PAST, KC_P7, KC_P8,   KC_P9,   KC_PCMM, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_MINS, KC_AT,   KC_TILDE,
        KC_NO,   KC_P0, KC_PDOT, KC_PENT, KC_PEQL, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_GRV),

/* Function (Lower + Raise)
 * ,-----------------------------------------------------------------------------------------------------------------------.
 * | RESET   | CA_F1   | CA_F2   | CA_F3   | CA_F4   | CA_F5   | CA_F6   |   CA_F7 |         |         |         |         |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |         |         |         |         |         | QWERTY  | DVORAK  | COLEMAK |         |         |         |         |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |         |         |         |         |         |         |         |         |         |         |         |         |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |         |         |         |         |         |          LED      |         |         |         |         |         |
 * `-----------------------------------------------------------------------------------------------------------------------'
 */

[_FUNCTION] = LAYOUT_planck_mit(
        RESET, CA_F1, CA_F2, CA_F3, CA_F4, CA_F5,  CA_F6,  CA_F7,   KC_NO, KC_NO, KC_NO, KC_NO,
        DEBUG, KC_NO, KC_NO, KC_NO, KC_NO, QWERTY, DVORAK, COLEMAK, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LED,    LED,    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO)};

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |     LED     |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK,  DVORAK,  PLOVER,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
