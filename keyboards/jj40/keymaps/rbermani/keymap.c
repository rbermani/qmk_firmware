/*
Copyright 2017 Robert Bermani <bobbermani@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "jj40.h"
#include "action_layer.h"

#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   `  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  OS  | Alt  |Shift |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,    KC_Y, KC_U,       KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,       KC_G,    KC_H, KC_J,       KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_GRV,  KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,    KC_N, KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT, \
  KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, TT(_LOWER), KC_SPC,        KC_DEL,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |      |      | Enter|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |PrScr |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      | Mute | Vol- | Vol+ | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | nkro |      |Lock  |Lower |             |      | Prev | Stop | Play | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, _______, KC_ENT, \
  KC_PSCR,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL, \
  _______, MAGIC_TOGGLE_NKRO, _______, KC_LOCK, _______, _______, _______, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Caps |   &  |   *  |   _  |   (  |   )  |   7  |   8  |   9  |   =  |   |  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   $  |   %  |   ^  |   [  |   ]  |   4  |   5  |   6  |   -  |   +  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   {  |   }  |   1  |   2  |   3  |   ~  |   \  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  OS  | Alt  |Shift |      |      0      |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_CAPS, KC_AMPR, KC_ASTR, KC_UNDS, KC_LPRN, KC_RPRN, KC_7,    KC_8,    KC_9,    KC_EQL,  KC_PIPE, KC_BSPC, \
  KC_TAB,  KC_DLR,  KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_4,    KC_5,    KC_6,    KC_MINS, KC_PLUS, KC_ENT, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_LCBR, KC_RCBR, KC_1,    KC_2,    KC_3,    _______, KC_BSLS, KC_DEL, \
  KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, _______, KC_0,             _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END \
)
};
