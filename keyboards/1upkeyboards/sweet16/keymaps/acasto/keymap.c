#include QMK_KEYBOARD_H

enum custom_keycodes {
  UP_URL = SAFE_RANGE,
  TD_7_NMLK = 0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_4x4(
        TD(TD_7_NMLK), KC_P8, KC_P9,   LT(2,KC_PAST),
        KC_P4, KC_P5, KC_P6,   KC_PSLS,
        KC_P1, KC_P2, KC_P3,   LT(1,KC_PPLS),
        LT(3,KC_P0), KC_PMNS, KC_PDOT, KC_PENT
    ),
    [1] = LAYOUT_ortho_4x4(
        KC_HOME,  XXXXXXX,   KC_END,  XXXXXXX,
        KC_PGUP, KC_UP, KC_PGDN, XXXXXXX,
        KC_LEFT, KC_DOWN, KC_RIGHT,  XXXXXXX,
        KC_WBAK, KC_WREF, KC_WFWD, XXXXXXX
    ),
    [2] = LAYOUT_ortho_4x4(
        KC_CALC, KC_ESC, KC_BSPC,  KC_ASTR,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [3] = LAYOUT_ortho_4x4(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE,
        XXXXXXX, KC_MPLY, KC_MPRV, KC_MNXT
    )
};

// Example custom key code
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case UP_URL:
            if (record->event.pressed) {
                SEND_STRING("http://1upkeyboards.com");
            }
            return false;
            break;
        case 0:
            register_code(KC_NLCK);
            break;
    }
    return true;
}

/***
void led_set_keymap(uint8_t usb_led) {
  if (!(usb_led & (1<<USB_LED_NUM_LOCK))) {
    register_code(KC_NUMLOCK);
    unregister_code(KC_NUMLOCK);
  }
}
***/

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for 7, twice for NumLock
  [TD_7_NMLK]  = ACTION_TAP_DANCE_DOUBLE(KC_P7, KC_NLCK)
};