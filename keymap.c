#include QMK_KEYBOARD_H

#ifdef LAYOUT_PRINTER
#include "layout.h"
#endif



bool is_mac = true;
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _MAIN,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MISC,
    _MODS,
    _DOCMD,
    _NAV
};

enum custom_keycodes {
  MAIN = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  MISC,
  MODS,
  DOCMD,
  NAV,
  RTRN,
  HM,
  ED,
  DEL,
  CUTLN,
  CPLN,
  PSTUP,
  PSTDN,
  UNDO,
  REDO,
  ALL,
  CUT,
  COPY,
  PASTE,
  SAVE,
  FIND,
  DELLN,
  MVLNDN,
  MVLNUP,
  JUMPUP,
  JUMPDN,
  JUMPLT,
  JUMPRT,
  MVBAK,
  MVFWD,
  HLTBAK,
  HLTFWD,
  CUTBAK,
  CUTFWD,
  DELBAK,
  DELFWD,
  RBTNEWVAR,
  RBTVAR,
  SCRSHT,
  SCRSHTSV
};

// Tap dance enums
/*
enum {
    CM_BRAK
};
*/


/* tap dance */
/*
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(tap_dance_state_t *state);

void cm_finished(tap_dance_state_t *state, void *user_data);
void cm_reset(tap_dance_state_t *state, void *user_data);
*/



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* MAIN
,-------------------------------------------------.                        ,-------------------------------------------------.
|    Q    |    W    |    F    |    P    |    G    |                        |    J    |    M    |    U    |    Y    |  BSPC   |
|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|
|    A    |    R    |    S    |    T    |    D    |                        |    H    |    N    |    E    |    I    |    O    |
|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|
|  MISC   |    X    |    C    |    V    |    B    |                        |    Z    |    L    |    K    |   TAB   |   ENT   |
`---------------------------------------+---------+---------.    ,---------+---------+---------------------------------------'
                                        |  LOWER  |   SPC   |    |  LSFT   |  RAISE  |
                                        `-------------------'    `-------------------' 
*/
[_MAIN] = LAYOUT_ortho_4x12(
  KC_Q,      KC_W,         KC_F,         KC_P,         KC_G,    _______,  _______,      KC_J,  KC_M,         KC_U,         KC_Y,            KC_BSPC,
  KC_A,      KC_R,         KC_S,         KC_T,         KC_D,    _______,  _______,      KC_H,  KC_N,         KC_E,         KC_I,            KC_O,
  MO(_MISC), LCTL_T(KC_X), LALT_T(KC_C), LGUI_T(KC_V), KC_B,    _______,  _______,      KC_Z,  LGUI_T(KC_L), LALT_T(KC_K), LCTL_T(KC_TAB),  KC_ENT,
  _______,   _______,      _______,      _______,      LOWER,   KC_SPC,   KC_LSFT,      RAISE, _______,      _______,      _______,         _______
),

/* LOWER
,-------------------------------------------------.                        ,-------------------------------------------------.
|   ENT   |  CAPS   |  LCTL   |  LALT   |  LGUI   |                        |         |         |         |         |  BSPC   |
|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|
|   ESC   |   HM    |   UP    |   ED    |         |                        |    _    |    (    |    )    |    {    |    }    |
|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|
|         |  LEFT   |  DOWN   |  RGHT   |         |                        |         |    <    |    >    |    [    |    ]    |
`---------------------------------------+---------+---------.    ,---------+---------+---------------------------------------'
                                        |         |   SPC   |    |  LSFT   |         |
                                        `-------------------'    `-------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
  KC_ENT,  KC_CAPS,  KC_LCTL,  KC_LALT, KC_LGUI,       _______,  _______,        _______,  _______, KC_LBRC, KC_RBRC,  KC_BSPC,
  KC_ESC,  HM,       KC_UP,    ED,      _______,       _______,  _______,        KC_UNDS,  KC_LPRN, KC_RPRN, KC_LCBR,  KC_RCBR,
  _______, KC_LEFT,  KC_DOWN,  KC_RGHT, _______,       _______,  _______,        _______,  KC_SLSH, KC_BSLS, _______,  _______,
  _______, _______,  _______,  _______, _______,       KC_SPC,   KC_LSFT,        _______,  _______, _______, _______,  _______
),


/* RAISE
,-------------------------------------------------.                        ,-------------------------------------------------.
|    `    |    &    |    *    |    ~    |         |                        |         |    7    |    8    |    9    |  BSPC   |
|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|
|   ESC   |    $    |    %    |    ^    |         |                        |    +    |    4    |    5    |    6    |    0    |
|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|
|         |    !    |    @    |    #    |    =    |                        |    -    |    1    |    2    |    3    |    =    |
`---------------------------------------+---------+---------.    ,---------+---------+---------------------------------------'
                                        |         |   SPC   |    |  LSFT   |         |
                                        `-------------------'    `-------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
  KC_GRV,  KC_AMPR,  KC_ASTR,  KC_TILD, KC_COMM,     _______,  _______,      _______,     KC_7,     KC_8,    KC_9,    KC_BSPC,
  KC_ESC,  KC_DLR,   KC_PERC,  KC_CIRC, KC_DOT,      _______,  _______,      KC_PLUS,     KC_4,     KC_5,    KC_6,    KC_0,
  _______, KC_EXLM,  KC_AT,    KC_HASH, KC_EQUAL,    _______,  _______,      KC_MINUS,    KC_1,     KC_2,    KC_3,    DEL,
  _______, _______,  _______,  _______, _______,     KC_SPC,   KC_LSFT,      _______,     _______,  _______, _______, _______
),

/* ADJUST
,-------------------------------------------------.                        ,-------------------------------------------------.
|         |   F1    |   F2    |   F3    |   F4    |                        |  VOLD   |  VOLU   |  MUTE   | CG_SWAP | CG_NORM |
|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|
|         |   F5    |   F6    |   F7    |   F8    |                        | RBTVAR  |         |         | SCRSHT  |  MOUSE  |
|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|
|         |   F9    |   F10   |   F11   |   F12   |                        |RBTNEWVAR|         |         |SCRSHTSV |  DOCMD  |
`---------------------------------------+---------+---------.    ,---------+---------+---------------------------------------'
                                        |         |         |    |         |         |
                                        `-------------------'    `-------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12(
  KC_F1,   KC_F2,     KC_F3,   KC_F4,   _______,    _______, _______,         KC_VOLD,   KC_VOLU,  KC_MUTE,  CG_SWAP,    CG_NORM,
  KC_F5,   KC_F6,     KC_F7,   KC_F8,   _______,    _______, _______,         RBTVAR,    _______,  _______,  SCRSHT,     _______,
  KC_F9,   KC_F10,    KC_F11,  KC_F12,  _______,    _______, _______,         RBTNEWVAR, _______,  _______,  SCRSHTSV,   DOCMD,
  _______, _______, _______,   _______, _______,    _______, _______,         _______,   _______,  _______,  _______,    _______
),



/* MISC
,-------------------------------------------------.                        ,-------------------------------------------------.
|         |         | QK_LEAD |  MODS   |  REDO   |                        |         |    ?    |    |    |         |  BSPC   |
|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|
|   ALL   |         |  SAVE   |         |  FIND   |                        |         |    /    |    \    |    ;    |    '    |
|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|
|         |  UNDO   |   CUT   |  COPY   |  PASTE  |                        |         |    ,    |    .    |    :    |    "    |
`---------------------------------------+---------+---------.    ,---------+---------+---------------------------------------'
                                        |         |   SPC   |    |  LSFT   |         |
                                        `-------------------'    `-------------------'
 */
[_MISC] =  LAYOUT_ortho_4x12(
  _______, _______, QK_LEAD, _______,  REDO,        _______, _______,       _______,   KC_QUES,  KC_PIPE,  KC_DQUO,  KC_BSPC,
  ALL,     _______, SAVE,    _______,  FIND,        _______, _______,       _______,   KC_LABK,  KC_RABK,  KC_SCLN,  KC_QUOT,
  _______, UNDO,    CUT,     COPY,     PASTE,       _______, _______,       _______,   KC_COMM,  KC_DOT,   KC_COLN,  _______,
  _______, _______, _______, _______,  _______,     KC_SPC,  KC_LSFT,       _______,   _______,  _______,  _______,  _______
),


/* DOCMD
,-------------------------------------------------.                        ,-------------------------------------------------.
|         |  DELLN  |  CPLN   |  PSTUP  |         |                        |  REDO   | DELBAK  |         | DELFWD  |  UNDO   |
|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|
|  RTRN   |  CUTLN  | JUMPUP  |  PSTDN  |         |                        |         | CUTBAK  | MVLNUP  | CUTFWD  |   CUT   |
|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|
|         | JUMPLT  | JUMPDN  | JUMPRT  |         |                        |  COPY   | HLTBAK  | MVLNDN  | HLTFWD  |  PASTE  |
`---------------------------------------+---------+---------.    ,---------+---------+---------------------------------------'
                                        |   NAV   |  LSFT   |    |  LSFT   |  RTRN   |
                                        `-------------------'    `-------------------'
 */
[_DOCMD] =  LAYOUT_ortho_4x12(
  _______, DELLN,   CPLN,      PSTUP,   _______,       _______,  _______,       REDO,    DELBAK,  _______,   DELFWD,   UNDO,
  RTRN,    CUTLN,   KC_PGUP,   PSTDN,   _______,       _______,  _______,       _______, CUTBAK,  MVLNUP,    CUTFWD,   CUT,
  _______, JUMPLT,  KC_PGDN,   JUMPRT,  _______,       _______,  _______,       COPY,    HLTBAK,  MVLNDN,    HLTFWD,   PASTE,
  _______, _______, _______,   _______, NAV,           KC_LSFT,  KC_LSFT,       RTRN,    _______,  _______,  _______,  _______
),


/* NAV
,-------------------------------------------------.                        ,-------------------------------------------------.
|         |  DELLN  |  CPLN   |  PSTUP  |         |                        |         | DELBAK  |         | DELFWD  |         |
|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|
|  RTRN   |   HM    |   UP    |   ED    |         |                        |         | CUTBAK  | MVLNUP  | CUTFWD  |         |
|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|
|         |  LEFT   |  DOWN   |  RGHT   |         |                        |         | HLTBAK  | MVLNDN  | HLTFWD  |         |
`---------------------------------------+---------+---------.    ,---------+---------+---------------------------------------'
                                        |         |  LSFT   |    |  LSFT   |  RTRN   |
                                        `-------------------'    `-------------------'
 */
[_NAV] =  LAYOUT_ortho_4x12(
  _______, DELLN,     CPLN,      PSTUP,   _______,      _______, _______,         _______,  DELBAK,  _______,  DELFWD,  _______,
  RTRN,    HM,        KC_UP,     ED,      _______,      _______, _______,         _______,  CUTBAK,  MVLNUP,   CUTFWD,  _______,
  _______, KC_LEFT,   KC_DOWN,   KC_RGHT, _______,      _______, _______,         _______,  HLTBAK,  MVLNDN,   HLTFWD,  _______,
  _______, _______,   _______,   _______, _______,      KC_LSFT, KC_LSFT,         RTRN,    _______,  _______,  _______,  _______
)


};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}


void send_home(void){
  if (is_mac){
    SEND_STRING(SS_DOWN(X_LGUI));
    SEND_STRING(SS_DOWN(X_LEFT));
    SEND_STRING(SS_UP(X_LGUI));
    SEND_STRING(SS_UP(X_LEFT));
    //mac = false;
  }
  else {
    SEND_STRING(SS_TAP(X_HOME));
  }
}

void send_end(void){
  if (is_mac){
    SEND_STRING(SS_DOWN(X_LGUI));
    SEND_STRING(SS_DOWN(X_RIGHT));
    SEND_STRING(SS_UP(X_LGUI));
    SEND_STRING(SS_UP(X_RIGHT));
  }
  else {
    SEND_STRING(SS_TAP(X_END));
  }
}

void send_undo(bool down){
  if (down){
    if (is_mac){
      register_code16(G(KC_Z));
    }
    else {
      register_code16(C(KC_Z));
    }
  }
  else {
    if (is_mac){
      unregister_code16(G(KC_Z));
    }
    else {
      unregister_code16(C(KC_Z));
    } 
  }
}
void send_redo(bool down){
  if (down){
    if (is_mac){
      register_code16(S(G(KC_Z)));
    }
    else {
      register_code16(S(C(KC_Z)));
    }
  }
  else {
    if (is_mac){
      unregister_code16(S(G(KC_Z)));
    }
    else {
      unregister_code16(S(C(KC_Z)));
    } 
  }
}

void send_copy(void){
  if (is_mac){
    SEND_STRING(SS_LGUI("c"));
  }
  else {
    SEND_STRING(SS_LCTL("c"));
  }
}

void send_cut(void){
  if (is_mac){
    SEND_STRING(SS_LGUI("x"));
  }
  else {
    SEND_STRING(SS_LCTL("x"));
  }
}

void send_paste(void){
  if (is_mac){
    SEND_STRING(SS_LGUI("v"));
  }
  else {
    SEND_STRING(SS_LCTL("v"));
  }
}

void send_find(void){
  if (is_mac) {
    SEND_STRING(SS_LGUI("f"));
  }
  else {
    SEND_STRING(SS_LCTL("f"));
  }
}

void send_save(void){
  if (is_mac) {
    SEND_STRING(SS_LGUI("s"));
  }
  else {
    SEND_STRING(SS_LCTL("s"));
  }
}

void select_all(void){
  if (is_mac) {
    SEND_STRING(SS_LGUI("a"));
  }
  else {
    SEND_STRING(SS_LCTL("a"));
  }
}

void word_back(void){
  if (is_mac){
    SEND_STRING(SS_DOWN(X_LALT));
    SEND_STRING(SS_TAP(X_LEFT));
    SEND_STRING(SS_UP(X_LALT));
  }
  else {
    SEND_STRING(SS_DOWN(X_LCTL));
    SEND_STRING(SS_TAP(X_LEFT));
    SEND_STRING(SS_UP(X_LCTL));
  }
}

void word_forward(void){
  if (is_mac){
    SEND_STRING(SS_DOWN(X_LALT));
    SEND_STRING(SS_TAP(X_RIGHT));
    SEND_STRING(SS_UP(X_LALT));
  }
  else {
    SEND_STRING(SS_DOWN(X_LCTL));
    SEND_STRING(SS_TAP(X_RIGHT));
    SEND_STRING(SS_UP(X_LCTL));
  }
}

void cut_line(void){
  send_end();
  SEND_STRING(SS_DOWN(X_LSFT));
  send_home();
  SEND_STRING(SS_UP(X_LSFT));
  send_cut();
  SEND_STRING(SS_TAP(X_BSPC));
}

void copy_line(void){
  send_end();
  SEND_STRING(SS_DOWN(X_LSFT));
  send_home();
  SEND_STRING(SS_UP(X_LSFT));
  send_copy();
  send_end();
}

/*
void print_layout_pretty(void){
    #ifdef LAYOUT_PRINTER
    for (int i=0; i<layout_length; i++){
        send_unicode_string(my_layout[i]);
        SEND_STRING("\n");
    }
    #endif
}
*/

void print_layout(void){
    #ifdef LAYOUT_PRINTER
    SEND_STRING(basic_layout);
    #endif
}


/* Leader key config */
void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_C, KC_T)) {
      cut_line();
    }
    else if (leader_sequence_two_keys(KC_C, KC_Y)){
      copy_line();       
    }
    else if (leader_sequence_one_key(KC_L)) {
      SEND_STRING("Log to Console    ");
    }
    else if (leader_sequence_two_keys(KC_S, KC_E)) {
      SEND_STRING("Set Test Variable    ${}    ${}");
      for (int j = 0; j < 8; j++){
        tap_code(KC_LEFT);
      }
    }
    else if (leader_sequence_two_keys(KC_C, KC_O)) {
      SEND_STRING("Control Window    ${}");
      tap_code(KC_LEFT);
    }
    else if (leader_sequence_one_key(KC_S)) {
        for (int i = 0; i < 20; i++){
          SEND_STRING(SS_TAP(X_UP));
        }
    }
    else if (leader_sequence_two_keys(KC_S, KC_S)) {
        for (int i = 0; i < 100; i++){
          SEND_STRING(SS_TAP(X_UP));
        }
    }
    else if (leader_sequence_three_keys(KC_S, KC_S, KC_S)) {
        for (int i = 0; i < 250; i++){
          SEND_STRING(SS_TAP(X_UP));
        }
    } 
    else if (leader_sequence_one_key(KC_C)) {
        for (int i = 0; i < 20; i++){
          SEND_STRING(SS_TAP(X_DOWN));
        }
    }
    else if (leader_sequence_two_keys(KC_C, KC_C)) {
        for (int i = 0; i < 100; i++){
          SEND_STRING(SS_TAP(X_DOWN));
        }
    } 
    else if (leader_sequence_three_keys(KC_C, KC_C, KC_C)) {
        for (int i = 0; i < 250; i++){
          SEND_STRING(SS_TAP(X_DOWN));
        }
    } 
    else if (leader_sequence_three_keys(KC_L, KC_A, KC_Y)) {
        print_layout();
    }
    /*
    else if (leader_sequence_four_keys(KC_L, KC_A, KC_Y, KC_P)) {
        print_layout_pretty();
    }
    */
}



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CG_SWAP:
      if (record->event.pressed) {
        is_mac = true;
      }
      return true;
    case CG_NORM:
      if (record->event.pressed) {
        is_mac = false;
      }
      return true;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case DOCMD:
      if (record->event.pressed) {
        layer_on(_DOCMD);
      }
      return false;
      break;
    case RTRN:
      if (record->event.pressed) {
        layer_clear();
        layer_on(_MAIN);
      }
      return false;
      break;
    case NAV:
      if (record->event.pressed) {
        layer_on(_NAV);
      } else {
        layer_off(_NAV);
      }
      return false;
      break;
    case HM:
      if (record->event.pressed) {
        send_home();
      }
      return false;
      break;
    case ED:
      if (record->event.pressed) {
        send_end();
      }
      return false;
      break;
    case UNDO:
      if (record->event.pressed) {
        send_undo(1);
      }
      else {
        send_undo(0);
      }
      return false;
      break;
    case  REDO:
      if (record->event.pressed) {
        send_redo(1);
      }
      else {
        send_redo(0);
      }
      return false;
      break;
    case CUT:
      if (record->event.pressed) {
        send_cut();
      }
      return false;
      break;
    case COPY:
      if (record->event.pressed) {
        send_copy();
      }
      return false;
      break;
    case PASTE:
      if (record->event.pressed) {
        send_paste();
      }
      return false;
      break;
    case FIND:
      if (record->event.pressed) {
        send_find();
      }
      return false;
      break;
    case SAVE:
      if (record->event.pressed) {
        send_save();
      }
      return false;
      break;
    case ALL:
      if (record->event.pressed) {
        select_all();
      }
      return false;
      break;

    case MVBAK:
      if (record->event.pressed) {
        word_back();
      }
      return false;
      break;
    case MVFWD:
      if (record->event.pressed) {
        word_forward();
      }
      return false;
      break;
    case  CPLN:
      if (record->event.pressed) {
        copy_line();
      }
      return false;
      break;
    case  CUTLN:
      if (record->event.pressed) {
        cut_line();
      }
      return false;
      break;
    case PSTUP:
      if (record->event.pressed) {
        send_home();
        SEND_STRING(SS_TAP(X_ENTER));
        SEND_STRING(SS_TAP(X_UP));
        send_end();
        send_paste();
      }
      return false;
      break;
    case  PSTDN:
      if (record->event.pressed) {
        send_end();
        SEND_STRING(SS_TAP(X_ENTER));
        send_paste();
      }
      return false;
      break;
    case  DELLN:
      if (record->event.pressed) {
        send_end();
        SEND_STRING(SS_DOWN(X_LSFT));
        send_home();
        send_home();
        SEND_STRING(SS_UP(X_LSFT));
        SEND_STRING(SS_TAP(X_BSPC));
        SEND_STRING(SS_TAP(X_BSPC));
      }
      return false;
      break;
    case DEL:
      if (record->event.pressed) {
        if (is_mac) {
          SEND_STRING(SS_DOWN(X_LCTL));
          SEND_STRING(SS_DOWN(X_D));
          //SEND_STRING(SS_LCTL("d"));
        }
        else {
          SEND_STRING(SS_DOWN(X_DEL));
        }
      }
      else {
        if (is_mac){
          SEND_STRING(SS_UP(X_LCTL));
          SEND_STRING(SS_UP(X_D));
        }
        else {
          SEND_STRING(SS_UP(X_DEL));
        }
      }
      return false;
      break;
    case  MVLNDN:
      if (record->event.pressed) {
        send_end();
        SEND_STRING(SS_DOWN(X_LSFT));
        send_home();
        send_home();
        SEND_STRING(SS_UP(X_LSFT));
        send_cut();
        SEND_STRING(SS_TAP(X_BSPC));
        SEND_STRING(SS_TAP(X_DOWN));
        send_end();
        SEND_STRING(SS_DOWN(X_ENT));
        SEND_STRING(SS_DOWN(X_LSFT));
        send_home();
        SEND_STRING(SS_UP(X_LSFT));
        send_paste();
      }
      return false;
      break;
    case  MVLNUP:
      if (record->event.pressed) {
        send_end();
        SEND_STRING(SS_DOWN(X_LSFT));
        send_home();
        send_home();
        SEND_STRING(SS_UP(X_LSFT));
        send_cut();
        SEND_STRING(SS_TAP(X_BSPC));
        SEND_STRING(SS_TAP(X_UP));
        send_end();
        SEND_STRING(SS_DOWN(X_ENT));
        SEND_STRING(SS_DOWN(X_LSFT));
        send_home();
        SEND_STRING(SS_UP(X_LSFT));
        send_paste();
      }
      return false;
      break;
    case JUMPUP:
      if (record->event.pressed) {
        for (int i = 0; i < 15; i++){
          SEND_STRING(SS_TAP(X_UP));
        }
      }
      return false;
      break;
    case JUMPDN:
      if (record->event.pressed) {
        for (int i = 0; i < 15; i++){
          SEND_STRING(SS_TAP(X_DOWN));
        }
      }
      return false;
      break;
    case JUMPLT:
      if (record->event.pressed) {
        for (int i = 0; i < 15; i++){
          SEND_STRING(SS_TAP(X_LEFT));
        }
      }
      return false;
      break;
    case JUMPRT:
      if (record->event.pressed) {
        for (int i = 0; i < 15; i++){
          SEND_STRING(SS_TAP(X_RIGHT));
        }
      }
      return false;
      break;
    case HLTBAK:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSFT));
        word_back();
        SEND_STRING(SS_UP(X_LSFT));
      }
      return false;
      break;
    case HLTFWD:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSFT));
        word_forward();
        SEND_STRING(SS_UP(X_LSFT));
      }
      return false;
      break;
    case CUTBAK:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSFT));
        word_back();
        SEND_STRING(SS_UP(X_LSFT));
        send_cut();
      }
      return false;
      break;
    case CUTFWD:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSFT));
        word_forward();
        SEND_STRING(SS_UP(X_LSFT));
        send_cut();
      }
      return false;
      break;
    case DELBAK:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSFT));
        word_back();
        SEND_STRING(SS_UP(X_LSFT));
        SEND_STRING(SS_TAP(X_BSPC));
      }
      return false;
      break;
    case DELFWD:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSFT));
        word_forward();
        SEND_STRING(SS_UP(X_LSFT));
        SEND_STRING(SS_TAP(X_BSPC));
      }
      return false;
      break;
    case  RBTNEWVAR:
      if (record->event.pressed) {
        SEND_STRING("${} =    ");
        for (int i =0; i < 7; i++){
          SEND_STRING(SS_TAP(X_LEFT));
        }
      }
      return false;
      break;
    case  RBTVAR:
      if (record->event.pressed) {
        SEND_STRING("${}");
        SEND_STRING(SS_TAP(X_LEFT));
      }
      return false;
      break;
    case  SCRSHT:
      if (record->event.pressed) {
        // ctrl + cmd + shift + 4
        SEND_STRING(SS_DOWN(X_LGUI));
        SEND_STRING(SS_DOWN(X_LSFT));
        SEND_STRING(SS_LCTL("4"));
        SEND_STRING(SS_UP(X_LGUI));
        SEND_STRING(SS_UP(X_LSFT));
      }
      return false;
      break;
    case  SCRSHTSV:
      if (record->event.pressed) {
        // ctrl + cmd + shift + 4
        SEND_STRING(SS_DOWN(X_LSFT));
        SEND_STRING(SS_LGUI("4"));
        SEND_STRING(SS_UP(X_LSFT));
      }
      return false;
      break;

  }
  return true;
}


/*
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t cmtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void cm_finished(tap_dance_state_t *state, void *user_data) {
    cmtap_state.state = cur_dance(state);
    switch (cmtap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_COMM); break;
        case TD_SINGLE_HOLD: register_code16(S(KC_COMM)); break;
        default: break;
    }
}

void cm_reset(tap_dance_state_t *state, void *user_data) {
    switch (cmtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_COMM); break;
        case TD_SINGLE_HOLD: unregister_code16(S(KC_COMM)); break;
        default: break;
    }
    cmtap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [CM_BRAK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, cm_finished, cm_reset),
};
*/