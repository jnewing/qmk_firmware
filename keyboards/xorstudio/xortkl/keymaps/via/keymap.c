// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// NULL Binding
enum layers {
    BASE,
    FN1,
    FN2,
};

enum custom_keycodes {
    SOCD_W,
    SOCD_A,
    SOCD_S,
    SOCD_D
};

bool w_down = false;
bool a_down = false;
bool s_down = false;
bool d_down = false;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┐ ┌───┬───┬───┐
     * │Esc│ │F1 │F2 │F3 │F4 │ │F5 │F6 │F7 │F8 │ │F9 │F10│F11│F12│ │F13│ │PSc│Scr│Pse│
     * └───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┘ └───┴───┴───┘
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│ │Ins│Hom│PgU│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │ │Del│End│PgD│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤     ┌───┐
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ Fn│     │ ↑ │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴─────┬┴───┤ ┌───┼───┼───┐
     * │Ctrl│    │Alt │                        │ Alt│         │Ctrl│ │ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴────┴─────────┴────┘ └───┴───┴───┘
     */
    // [0] = LAYOUT_tkl_ansi(
    //     KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,     KC_PSCR, KC_SCRL, KC_PAUS,

    //     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,
    //     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN,
    //     KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    //     KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RGUI,             KC_UP,
    //     KC_LCTL, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RCTL,                              KC_LEFT, KC_DOWN, KC_RGHT
    // ),

    [0] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,     KC_PSCR, KC_SCRL, KC_PAUS,

        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    SOCD_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, SOCD_A,  SOCD_S,    SOCD_D,  KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RGUI,             KC_UP,
        KC_LCTL, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RCTL,                              KC_LEFT, KC_DOWN, KC_RGHT
    ),


    [1] = LAYOUT_tkl_ansi(
        _______,  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______,     _______, _______, _______,

        _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______,    _______,  _______, _______,
        _______,  _______,    _______,    _______,    QK_BOOT,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______,    _______,  _______,  _______,
        _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,          _______,
        _______,          _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______, _______, _______,             _______,
        _______, _______,                            _______,                             _______, _______,                              _______, _______, _______
    ),

    [2] = LAYOUT_tkl_ansi(
        _______,  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______,     _______, _______, _______,

        _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______,    _______,  _______, _______,
        _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______,    _______,  _______,  _______,
        _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,          _______,
        _______,          _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______, _______, _______,             _______,
        _______, _______,                            _______,                             _______, _______,                              _______, _______, _______
    ),
};

// NULL Binding Code
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SOCD_W:
            if (record->event.pressed) {
                if (s_down) {
                    unregister_code(KC_S);
                }
                register_code(KC_W);
                w_down = true;
            } else {
                unregister_code(KC_W);
                w_down = false;
                if (s_down) {
                    register_code(KC_S);
                }
            }

            return false;
            break;

        case SOCD_A:
            if (record->event.pressed) {
                if (d_down) {
                    unregister_code(KC_D);
                }
                register_code(KC_A);
                a_down = true;
            } else {
                unregister_code(KC_A);
                a_down = false;
                if (d_down) {
                    register_code(KC_D);
                }
            }
            return false;
            break;

        case SOCD_S:
            if (record->event.pressed) {
                if (w_down) {
                    unregister_code(KC_W);
                }
                register_code(KC_S);
                s_down = true;
            } else {
                unregister_code(KC_S);
                s_down = false;
                if (w_down) {
                    register_code(KC_W);
                }
            }
            return false;
            break;

        case SOCD_D:
            if (record->event.pressed) {
                if (a_down) {
                    unregister_code(KC_A);
                }
                register_code(KC_D);
                d_down = true;
            } else {
                unregister_code(KC_D);
                d_down = false;
                if (a_down) {
                    register_code(KC_A);
                }
            }
            return false;
            break;
        }
        return true;
}
