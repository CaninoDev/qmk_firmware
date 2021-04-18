/* Copyright 2019 Ian Canino (ian@thecommittedbug.io)
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

#define CON_F1 LCA_T(KC_F1)
#define CON_F2 LCA_T(KC_F2)
#define CON_F3 LCA_T(KC_F3)
#define CON_F4 LCA_T(KC_F4)
#define CON_F5 LCA_T(KC_F5)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    * ,-------------------------------------------------------------------------------------------.
    * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  | BkSpc |
    * |------+------+------+------+------+-------------+------+------+------+------+--------------|
    * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   '  |    Enter     |
    * |------+------+------+------+------+------|------+------+------+------+------+--------------|
    * | LS/( |   Z  |   X  |   C  |   V  |   B  | MO(3)|   N  |   M  |   ,  |   .  |   /  | RS/)  |
    * |------+------+------+------+------+------+------+------+------+------+------+------+-------|
    * | Ctrl |L(GUI)|      |L_ALT |    MO(1)    |    Space    |    R_ALT    |      | MO(2)| R(GUI)  |
    * `-------------------------------------------------------------------------------------------'
    */
    LAYOUT(
            KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R, KC_T,            KC_Y, KC_U, KC_I, KC_O, KC_P,    KC_DEL, KC_BSPC,
            KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F, KC_G,            KC_H, KC_J, KC_K, KC_L, KC_QUOT,         KC_ENT,
            KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V, KC_B,    MO(3),  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,
            KC_LCTL, KC_LGUI,          KC_LALT, LT(1, KC_DEL), KC_SPC,       KC_RALT,               LT(2, KC_RGUI),   KC_RGUI
    ),
    /*
    * ,-------------------------------------------------------------------------------------------.
    * |NumLk |   1  |   2  |   3  |   -  |      | Home | PgUp |   Up | PgDn | PrtSc|      |       |
    * |------+------+------+------+------+-------------+------+------+------+------+--------------|
    * |   /  |   4  |   5  |   6  |   +  |      |  End | Left | Down | Right|   ;  |      Ins     |
    * |------+------+------+------+------+------|------+------+------+------+------+--------------|
    * |   *  |   7  |   8  |   9  |   0  |      |      |      |      |   [  |   ]  |  \   |       |
    * |------+------+------+------+------+------+------+------+------+------+------+------+-------|
    * |BlTgle|BlCycl|      |      |             |             |             |      |      |       |
    * `-------------------------------------------------------------------------------------------'
    */
    LAYOUT(
            KC_NLCK, KC_P1, KC_P2, KC_P3, KC_PMNS, KC_TRNS, KC_HOME, KC_PGUP, KC_UP, KC_PGDN, KC_PSCR, KC_TRNS, KC_TRNS,
            KC_PSLS, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_TRNS, KC_END, KC_LEFT, KC_DOWN, KC_RIGHT, KC_SCLN, KC_INS,
            KC_PAST, KC_P7, KC_P8, KC_P9, KC_P0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS,
            BL_TOGG, BL_STEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    /*
    * ,-------------------------------------------------------------------------------------------.
    * |      | Prev | Play | Next |      |      |      |      |      |      |      |      |       |
    * |------+------+------+------+------+-------------+------+------+------+------+--------------|
    * |      | Mute | VolU | VolD |      |      |      |      |      |      |      |              |
    * |------+------+------+------+------+------|------+------+------+------+------+--------------|
    * |      | Mail | BBack| BFwd |      |      |      |      |      |      |      |      |       |
    * |------+------+------+------+------+------+------+------+------+------+------+------+-------|
    * |      |      |      |      |             |             |             |      |      |       |
    * `-------------------------------------------------------------------------------------------'
    */
    LAYOUT(
            KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_MAIL, KC_WBAK, KC_WFWD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    /*
    * ,-------------------------------------------------------------------------------------------.
    * |      |CA(F1)|CA(F2)|CA(F3)|CA(F4)|CA(F5)|  `   |  !   |   #  |  $   |  +   |   ^   |      |
    * |------+------+------+------+------+-------------+------+------+------+------+--------------|
    * |      | F1   | F2   | F3   | F4   | F5   |      |  %   |  *   |   &  |   =  |              |
    * |------+------+------+------+------+------|------+------+------+------+------+--------------|
    * |      | F6   | F7   | F8   | F9   | F10  |      |  _   |  -   |  @   |   ~  |  |   |
    * |------+------+------+------+------+------+------+------+------+------+------+------+-------|
    * |      |      |      |      |             |             |             |      |      |       |
    * `-------------------------------------------------------------------------------------------'
    */
    LAYOUT(
            KC_TRNS       , CON_F1      , CON_F2      , CON_F3      , CON_F4      , CON_F5      , KC_GRV,  KC_EXLM, KC_HASH, KC_DLR,  KC_PLUS, KC_CIRC,
            KC_TRNS       , KC_F1       , KC_F2				, KC_F3       , KC_F4       , KC_F5       , KC_TRNS, KC_TRNS, KC_PERC, KC_ASTR, KC_AMPR, KC_EQL,   KC_TRNS,
            KC_TRNS       , KC_F6       , KC_F7       , KC_F8       , KC_F9       , KC_F10      , KC_TRNS, KC_UNDS, KC_MINS, KC_AT,   KC_TILDE, KC_PIPE,
            KC_TRNS       , KC_TRNS     , KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS     , KC_TRNS, KC_TRNS, KC_TRNS
    )
};

void matrix_init_user(void) {
    // set top LED to output and low
    setPinOutput(B1);
    writePinLow(B1);
    // set middle LED to output and low
    setPinOutput(B2);
    writePinLow(B2);
    // set bottom LED to output and low
    setPinOutput(B3);
    writePinLow(B3);
}

void matrix_scan_user(void) {}

// define the insert mode state
static bool ins_mode = false;

bool process_record_user (uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_INS:
            if (record->event.pressed) {
                // When kc_ins is pressed
                // toggle insert mode state
                ins_mode = (ins_mode) ? false : true;
                tap_code (KC_INS);
                if (ins_mode) {
                    writePinHigh(B1);
                    writePinHigh(B2);
                    writePinHigh(B3);
                }
            }
            return false;
        default:
            return true;
    }
}

// function for layer indicator LED
uint32_t layer_state_set_user(uint32_t state) {
    if (biton32(state) == 1) {
        writePinHigh(B1);
    } else {
        if (!(ins_mode)) {
            writePinLow(B1);
        }
    }
    if (biton32(state) == 2) {
        writePinHigh(B2);
    } else {
        if (!(ins_mode)) {
            writePinLow(B2);
        }
    }
    if (biton32(state) == 3) {
        writePinHigh(B3);
    } else {
        if (!(ins_mode)) {
            writePinLow(B3);
        }
    }
    return state;
}

