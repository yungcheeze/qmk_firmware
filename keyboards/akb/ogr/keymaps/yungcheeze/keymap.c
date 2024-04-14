// Copyright 2018-2022 QMK (@qmk)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define MC_T LCTL_T(KC_T)
#define MC_N LCTL_T(KC_N)
#define MA_H LALT_T(KC_H)
#define MA_E LALT_T(KC_E)
#define SC_S MT(MOD_LSFT, KC_S)
#define SC_O MT(MOD_LSFT, KC_O)
#define NAV_G LT(_NAV, KC_G)
#define NAV_SPC LT(_NAV, KC_SPC)
#define TMUX LALT(KC_SEMICOLON)

enum layers {
    _WORKMAN = 0,
    _NAV,
    _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * ┌───┬───┐    ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │ F1│ F2│    │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│Hom│
     * ├───┼───┤    ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * | F3| F4|    │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │PgU│
     * ├───┼───┤    ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * | F5| F6|    │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │PgD│
     * ├───┼───┤    ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * | F7| F8|    │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ ↑ │End│
     * ├───┼───┤    ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * | F9|F10|    │Ctrl│GUI │Alt │                        │Alt│Ctl│   │ ← │ ↓ │ → │
     * └───┴───┘    └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
    [_WORKMAN] = LAYOUT_all(

       KC_F1, KC_F2,     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL, KC_HOME,
       KC_F3, KC_F4,     KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
       KC_F5, KC_F6,     KC_CAPS, KC_A,    SC_S,    MA_H,    MC_T,    NAV_G,   KC_Y,    MC_N,    MA_E,    SC_O,    KC_I,    KC_QUOT,          KC_ENT,  KC_PGDN,
       KC_F7, KC_F8,     KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,
       KC_F9, KC_F10,    KC_LGUI, KC_LCTL, KC_LCTL,                            NAV_SPC,                   KC_LALT, KC_LALT, KC_LEFT, KC_DOWN, KC_RGHT
    ),


    [_NAV] = LAYOUT_all(
        KC_F11 , KC_F12 , QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_HOME, _______, _______, _______, _______, KC_GRV , _______,
        KC_MPRV, KC_MNXT, _______, _______, _______, _______, TMUX   , _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,          _______, _______,
        KC_MSTP, KC_MPLY,  _______,          _______, _______, _______, _______, _______, KC_PGDN, KC_END , _______, _______, _______, _______, _______, _______,
       _______, _______,  _______, _______, _______,                            _______,                   TMUX   , TMUX   , _______, _______, _______, _______
    ),

};
