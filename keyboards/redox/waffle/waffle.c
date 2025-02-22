// Copyright 2025 Andrea Rossini (github.com/rossini-andrea)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "quantum.h"
#include "pin_defs.h"

#define LED_LAYER_PIN C6

static uint32_t blink_tick;

uint32_t layer_led_blink(uint32_t trigger_time, void *cb_arg) {
    uint32_t tick = blink_tick;

    if (tick) {
        gpio_toggle_pin(LED_LAYER_PIN);
    } else {
        gpio_write_pin(LED_LAYER_PIN, 0);
    }

    return tick;
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    static deferred_token my_token = 0;
    state = layer_state_set_user(state);

    switch (get_highest_layer(state)) {
        case 0:
            blink_tick = 0;
            my_token = 0;
            return state;
        case 1:
            blink_tick = 500;
            break;
        case 2:
            blink_tick = 300;
            break;
        default:
            blink_tick = 200;
            break;
    }

    if (!my_token) {
        my_token = defer_exec(blink_tick, layer_led_blink, NULL);
    }

    return state;
}

void keyboard_pre_init_kb(void) {
    // Call the user pre init code.
    keyboard_pre_init_user();

    // Set our LED pins as output
    gpio_set_pin_output(LED_LAYER_PIN);
}
