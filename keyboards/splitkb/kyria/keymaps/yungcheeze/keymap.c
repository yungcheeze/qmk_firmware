/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _WORKMAN = 0,
    _ZEN,
    _QWERTY,
    _NAV,
    _NUM,
    _FN,
};

// Aliases for readability
#define QWERTY DF(_QWERTY)
#define WORKMAN DF(_WORKMAN)
#define ZEN DF(_ZEN)
#define NUM MO(_NUM)
#define FN MO(_FN)

#define ALT_RPRN MT(MOD_LALT, KC_RPRN)
#define CTL_LPRN MT(MOD_LCTL, KC_LPRN)
#define LSFT_LT MT(MOD_LSFT, KC_LT)
#define LSFT_RGHT MT(MOD_LSFT, KC_RGHT)
#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT MT(MOD_LALT, KC_ENT)
#define LSFT_SPC LSFT_T(KC_SPC)
#define LSFT_ENT MT(MOD_LSFT, KC_ENT)
#define LSFT_TAB MT(MOD_LSFT, KC_TAB)
#define LSFT_CAP MT(MOD_LSFT, KC_CAPS)
#define LSFT_S MT(MOD_LSFT, KC_S)
#define LSFT_L MT(MOD_LSFT, KC_L)
#define LSFT_O MT(MOD_LSFT, KC_O)
#define NUM_CAPS LT(_NUM, KC_CAPS)
#define NUM_ENT LT(_NUM, KC_ENT)
#define NUM_SPC LT(_NUM, KC_SPC)
#define NUM_TAB LT(_NUM, KC_TAB)
#define NAV_G LT(_NAV, KC_G)
#define NAV_V LT(_NAV, KC_V)
#define NAV_B LT(_NAV, KC_B)
#define FN_Y LT(_FN, KC_Y)
#define FN_H LT(_FN, KC_H)
#define TMUX LALT(KC_SEMICOLON)
#define EMACS LALT(KC_SPACE)
#define MA_D LALT_T(KC_D)
#define MA_H LALT_T(KC_H)
#define MC_F LCTL_T(KC_F)
#define MC_T LCTL_T(KC_T)
#define MC_J LCTL_T(KC_J)
#define MC_N LCTL_T(KC_N)
#define MC_6 LCTL_T(KC_6)
#define MA_K LALT_T(KC_K)
#define MA_E LALT_T(KC_E)
#define MA_5 LALT_T(KC_5)
#define SC_A LSFT_T(KC_A)
#define SC_4 LSFT_T(KC_4)
#define SC_SCLN LSFT_T(KC_SCLN)
#define SC_S LSFT_T(KC_S)
#define CTL_DOWN LCTL_T(KC_DOWN)
#define ALT_UP LALT_T(KC_UP)
#define WIN_CAPS MT(MOD_LGUI, KC_CAPS)
#define WIN_ENT MT(MOD_LGUI, KC_ENT)
#define WIN_TAB MT(MOD_LGUI, KC_TAB)
#define KC_DOL LSFT(KC_4)
// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |      |  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
     _______ , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                         KC_Y   ,  KC_U  ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
     KC_TAB  , KC_A ,  LSFT_S ,  MA_D  ,   MC_F , NAV_G  ,                                         FN_H   ,  MC_J  ,  MA_K ,  LSFT_L,KC_SCLN, KC_QUOT,
     KC_ESC  , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,  KC_B  , KC_CAPS ,WORKMAN,     _______, KC_CAPS,  KC_N   ,  KC_M  ,KC_COMM, KC_DOT ,KC_SLSH, KC_GRV,
                                _______,KC_LGUI ,NUM_SPC , TMUX    , TMUX  ,     TMUX   , TMUX   , NUM_ENT ,KC_LGUI , _______
    ),

    [_WORKMAN] = LAYOUT(
     _______ , KC_Q ,  KC_D   ,  KC_R  ,   KC_W ,   KC_B ,                                         KC_J   ,  KC_F  ,  KC_U ,   KC_P ,KC_SCLN, KC_BSPC,
     KC_TAB  , KC_A ,  LSFT_S   ,  MA_H  ,   MC_T , NAV_G  ,                                         FN_Y   ,  MC_N  ,  MA_E ,  LSFT_O,KC_I   , KC_QUOT,
     KC_ESC  , KC_Z ,  KC_X   ,  KC_M  ,   KC_C ,  KC_V  , KC_CAPS ,ZEN    ,     _______, KC_CAPS,  KC_K   ,  KC_L  ,KC_COMM, KC_DOT ,KC_SLSH, KC_GRV,
                                _______,KC_LGUI ,NUM_SPC , TMUX    , TMUX  ,     TMUX   , TMUX   , NUM_ENT ,KC_LGUI , _______
    ),

    [_ZEN] = LAYOUT(
     _______ , KC_Q ,  KC_D   ,  KC_R  ,   KC_W ,   KC_B ,                                         KC_J   ,  KC_F  ,  KC_U ,   KC_P ,KC_SCLN, KC_BSPC,
     KC_TAB  , KC_A ,  KC_S   ,  KC_H  ,   KC_T ,  KC_G  ,                                         KC_Y   ,  KC_N  ,  KC_E ,   KC_O ,KC_I   , KC_QUOT,
     KC_ESC  , KC_Z ,  KC_X   ,  KC_M  ,   KC_C ,  KC_V  , KC_CAPS ,WORKMAN ,     _______, KC_CAPS, KC_K   ,  KC_L  ,KC_COMM, KC_DOT ,KC_SLSH, KC_GRV,
                                _______,_______ , KC_SPC , _______ ,_______ ,    _______, _______, KC_ENT  ,_______ , _______
    ),
 /*
  * Layer template
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
     [_NAV] = LAYOUT(
       _______, _______, _______, _______, _______, _______,                                     _______, KC_PGUP, KC_HOME, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,                                     KC_LEFT, CTL_DOWN, ALT_UP, LSFT_RGHT, _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, KC_END, _______, _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, KC_TAB, _______, _______
     ),


 /*
  * Layer template
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
     [_NUM] = LAYOUT(
       _______ , KC_HASH, KC_1   , KC_2   , KC_3   ,KC_0    ,                                     KC_PIPE, KC_LCBR, KC_RCBR, KC_CIRC, KC_HASH, _______,
       KC_PLUS , KC_ASTR, SC_4   , MA_5   , MC_6   ,KC_EQL  ,                                    KC_MINUS,CTL_LPRN,ALT_RPRN,LSFT_LT , KC_GT  , KC_AT  ,
       KC_MINUS, KC_SLSH, KC_7   , KC_8   , KC_9   ,KC_DOL  , _______, _______, _______, _______, KC_UNDS, KC_LBRC, KC_RBRC, _______, _______, KC_BSLS,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
     ),

     [_FN] = LAYOUT(
       _______ , _______, KC_F1   , KC_F2   , KC_F3   ,KC_F10    ,                                     _______, _______, _______, _______, _______, _______,
       _______ , _______, KC_F4   , KC_F5   , KC_F6   ,KC_F11  ,                                    _______,_______,_______,_______ , _______  , _______  ,
       _______, _______ , KC_F7   , KC_F8   , KC_F9   ,KC_F12    , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
     ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case ALT_RPRN:
  case CTL_LPRN:
  case LSFT_LT:
    if (record->event.pressed && record->tap.count > 0) {
      register_code(KC_LSFT);
    } else {
      unregister_code(KC_LSFT);
    }
    return true;
  }
  return true; // We didn't handle other keypresses
}


/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _WORKMAN:
                oled_write_P(PSTR("WORKMAN\n"), false);
                break;
            case _ZEN:
                oled_write_P(PSTR("ZEN\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("NAV\n"), false);
                break;
            case _NUM:
                oled_write_P(PSTR("NUM\n"), false);
                break;
            case _FN:
                oled_write_P(PSTR("FN\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif
