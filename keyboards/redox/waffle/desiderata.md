* Activate `BOTH_SHIFTS_TURNS_ON_CAPS_WORD`.
* Activate `CAPS_WORD_ENABLE = yes` in rules.mk.
* Activate `SPLIT_LED_STATE_ENABLE` (?) and set `LED_CAPS_LOCK_PIN` to A3 or 5.
* Implement `led_update_user` for driving the led.
* Implement `layer_state_set_user` for driving the led.
* If too painful, solder the LED on master keyboard.
* Or use left LED for layer and righ LED for caps.
* Add a led on pin A3 or 5:
    * Off on layer 0
    * Solid on caps lock/word.
    * Blink faster as layer goes up. (500ms, 300, 200)
    * Follow [](https://docs.qmk.fm/custom_quantum_functions#deferred-execution).
* ESC near the A.
* Review the map before compiling.
