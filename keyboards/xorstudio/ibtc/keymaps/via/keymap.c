// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/*
* ┌───┬───┬───┐
* │ A │ B │ C │
* ├───┼───┼───┤
* │ D │ E │ F │
* ├───┼───┼───┤
* │ G │ H │ I │
* └───┴───┴───┘
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_3x3(
        KC_A,                   KC_B,               KC_AUDIO_MUTE,
        KC_D,                   KC_AUDIO_VOL_UP,    KC_MEDIA_PLAY_PAUSE,
        KC_MEDIA_PREV_TRACK,    KC_AUDIO_VOL_DOWN,  KC_MEDIA_NEXT_TRACK
    ),
    [1] = LAYOUT_ortho_3x3(
        _______,    _______,  _______,
        _______,    _______,  _______,
        _______,    _______,  _______
    ),
    [2] = LAYOUT_ortho_3x3(
        _______,    _______,  _______,
        _______,    _______,  _______,
        _______,    _______,  _______
    )
};
