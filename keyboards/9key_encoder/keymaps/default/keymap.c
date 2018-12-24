#include QMK_KEYBOARD_H

// Tap Dance Declarations
enum {
  ENT_5 = 0,
  ZERO_1
};

// Macro Declarations
enum {
  DBL_0 = 0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYER 0
 * ,-----------------------.
 * |   7   |   8   |   9   |
 * |-------+-------+-------|
 * |   4   | 5/ENT |   6   | Dbl Tap 5 for Enter
 * |-------+-------+-------|
 * |  1/0  |   2   | 3/FN  | 1/0 = Dbl Tap 1 for 0  -  3/FN = Hold 3 for FN
 * `---------------+-------|
 *                 | PLAY  | Clicking the Encoder - Play/Pause
 *                 |-------|
 *                 |  VOL  | Rotating the Encoder - Volume
 *                 `-------'
 */

[0] = LAYOUT( \
  KC_KP_7,    KC_KP_8,   KC_KP_9,     KC_NO,   \
  KC_KP_4,    TD(ENT_5), KC_KP_6,     KC_NO,   \
  TD(ZERO_1), KC_KP_2,   LT(2, KC_KP_3), KC_NO,   \
  KC_NO,      KC_NO,     KC_NO,       KC_MPLY, \
  KC_NO,      KC_NO,     KC_NO,       KC_VOLU, \
  KC_NO,      KC_NO,     KC_NO,       MO(1)    \
),

[1] = LAYOUT( \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,   \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,   \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,   \
  KC_NO,    KC_NO,    KC_NO,    KC_MPLY, \
  KC_NO,    KC_NO,    KC_NO,    KC_VOLD, \
  KC_NO,    KC_NO,    KC_NO,    MO(1)    \
),

/* LAYER 1 - FN
 * ,-----------------------.
 * |  ESC  |   +   |   -   |
 * |-------+-------+-------|
 * |  BSPC |   *   |   /   |
 * |-------+-------+-------|
 * |numlock|   .   |       |
 * `-----------------------|
 *                 | NEXT  | Clicking the Encoder - Next Track
 *                 |-------|
 *                 | SCROLL| Rotating the Encoder - Scroll Wheel
 *                 `-------'
 */

[2] = LAYOUT( \
  KC_ESC,   KC_KP_PLUS,  KC_KP_MINS,  KC_NO,   \
  KC_BSPC,  KC_PAST,  KC_PSLS,  KC_NO,   \
  KC_NLCK, KC_PDOT,   KC_TRNS,  KC_NO,   \
  KC_NO,    KC_NO,    KC_NO,    KC_MNXT, \
  KC_NO,    KC_NO,    KC_NO,    KC_WH_U, \
  KC_NO,    KC_NO,    KC_NO,    MO(3)    \
),

[3] = LAYOUT( \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,   \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,   \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,   \
  KC_NO,    KC_NO,    KC_NO,    KC_MNXT, \
  KC_NO,    KC_NO,    KC_NO,    KC_WH_D, \
  KC_NO,    KC_NO,    KC_NO,    MO(2)    \
)
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [ENT_5] = ACTION_TAP_DANCE_DOUBLE(KC_KP_5, KC_KP_ENT),
  [ZERO_1] = ACTION_TAP_DANCE_DOUBLE(KC_KP_1, KC_KP_0)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
      switch(id) {
          case DBL_0:
              SEND_STRING("00");
              return false;
      }
  }
  return MACRO_NONE;
};

void matrix_init_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}
