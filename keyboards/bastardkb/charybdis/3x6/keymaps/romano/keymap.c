#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "sendstring_german.h"

enum charybdis_keymap_layers {
    Qwerty = 0,
    Nav,
    Mouse,
    Button,
    Fun,
    Sym,
    Media,
    Num,
    Emoji,
};

#define CHARYBDIS_AUTO_SNIPING_ON_LAYER Mouse

enum custom_keycodes {
    SS_CRYPT = SAFE_RANGE,
    SS_CIRC,
};

enum unicode_names {
    // German keycodes
    AUM,
    OUM,
    UUM,
    AUM_S,
    OUM_S,
    UUM_S,
    ESZ,
    EUR,
    // Emoticons
    BANG,
    IRONY,
    SNEK,
    LARGE_SMILE,
    GRIN,
    BIG_GRIN,
    SWEAT,
    ROFL,
    SMILE,
    WINK,
    PLEASED,
    LOVE,
    WINK_TONGUE,
    UNPLEASANT,
    SAD,
    VOMIT,
    COOL,
    FROWN,
    FEAR,
    CRY,
    SCREAM,
    CURSE,
    DEVIL_HAPPY,
    SHIT,
    CLOWN,
    SEE_NO_EVIL,
    THUMBS_UP,
    FOLDED_HANDS,
    BICEPS,
};

const uint32_t PROGMEM unicode_map[] = {
    [AUM]          = 0x00E4,
    [OUM]          = 0x00F6,
    [UUM]          = 0x00FC,
    [AUM_S]        = 0x00C4,
    [OUM_S]        = 0x00D6,
    [UUM_S]        = 0x00DC,
    [ESZ]          = 0x00DF,
    [EUR]          = 0x20AC,
    [BANG]         = 0x203D,
    [LARGE_SMILE]  = 0x1F603,
    [GRIN]         = 0x1F604,
    [BIG_GRIN]     = 0x1F601,
    [SWEAT]        = 0x1F605,
    [ROFL]         = 0x1F602,
    [SMILE]        = 0x1F642,
    [WINK]         = 0x1F609,
    [PLEASED]      = 0x1F60A,
    [LOVE]         = 0x1F60D,
    [WINK_TONGUE]  = 0x1F61C,
    [UNPLEASANT]   = 0x1F62C,
    [SAD]          = 0x1F614,
    [VOMIT]        = 0x1F922,
    [COOL]         = 0x1F60E,
    [FROWN]        = 0x1F641,
    [FEAR]         = 0x1F628,
    [CRY]          = 0x1F62D,
    [SCREAM]       = 0x1F631,
    [CURSE]        = 0x1F92C,
    [DEVIL_HAPPY]  = 0x1F608,
    [SHIT]         = 0x1F4A9,
    [CLOWN]        = 0x1F921,
    [SEE_NO_EVIL]  = 0x1F649,
    [THUMBS_UP]    = 0x1F44D,
    [FOLDED_HANDS] = 0x1F64F,
    [BICEPS]       = 0x1F4AA,
};

enum { TD_LOWER_EMOJI, TD_LOCK_LAYER };

void lock_layer(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 2:
            if (IS_LAYER_ON(Num)) {
                layer_clear();
            } else {
                layer_move(Num);
            }
            break;
        case 3:
            if (IS_LAYER_ON(Sym)) {
                layer_clear();
            } else {
                layer_move(Sym);
            }
            break;
        case 5:
            reset_keyboard();
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_LOCK_LAYER] = ACTION_TAP_DANCE_FN(lock_layer),
};

const uint16_t PROGMEM lprn_combo[] = {LSFT_T(KC_F), LCTL_T(KC_D), COMBO_END};
const uint16_t PROGMEM rprn_combo[] = {LSFT_T(KC_J), LCTL_T(KC_K), COMBO_END};

const uint16_t PROGMEM lcbr_combo[] = {KC_R, KC_E, COMBO_END};
const uint16_t PROGMEM rcbr_combo[] = {KC_U, KC_I, COMBO_END};

const uint16_t PROGMEM lbrc_combo[] = {KC_V, KC_C, COMBO_END};
const uint16_t PROGMEM rbrc_combo[] = {KC_M, DE_COMM, COMBO_END};

combo_t key_combos[] = {
    COMBO(lprn_combo, DE_LPRN),
    COMBO(rprn_combo, DE_RPRN),
    COMBO(lcbr_combo, DE_LCBR),
    COMBO(rcbr_combo, DE_RCBR),
    COMBO(lbrc_combo, DE_LBRC),
    COMBO(rbrc_combo, DE_RBRC),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Charybdis layout: 3 rows × 6 cols per half, left thumb 3 keys, right thumb 2 keys.
  // Outer column follows original Corne mapping (col 0 / col 11).
  // Right middle-row outermost key (KC_RCTL position) gets the key that was
  // lost from the right thumb cluster (LT(Fun, KC_DEL) from Corne).
  //
  // Left thumb:  LT(Media,ESC)  |  LT(Nav,ENT)  |  LT(Mouse,TAB)
  // Right thumb: LT(Sym,SPC)    |  LT(Num,BSPC)
  // Lost keys (no physical home on new board):
  //   TD(TD_SWITCH_LAYER), KC_LALT (thumb), KC_RGUI (thumb) — removed
  //   LT(Fun,DEL) — moved to right outer middle-row key

  // ╭──────────────────────────────────────────────────────────────────────╮
  // │  Qwerty (base)                                                        │
  // ╰──────────────────────────────────────────────────────────────────────╯
  [Qwerty] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_ESC,            KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         DE_Y,    KC_U,    KC_I,    RALT_T(KC_O),        KC_P,    SS_CRYPT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       DRGSCRL,           LGUI_T(KC_A),    LALT_T(KC_S),    LCTL_T(KC_D), LSFT_T(KC_F), KC_G,   KC_H, LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), DE_QUOT, LT(Fun, KC_DEL),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       SS_CIRC,  LT(Mouse, DE_Z), KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    DE_COMM,    DE_DOT,  DE_SLSH, KC_DLR,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                               LT(Media, KC_ESC), LT(Nav, KC_ENT), LT(Mouse, KC_TAB),   LT(Sym, KC_BSPC), LT(Num, KC_SPC)
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  // ╭──────────────────────────────────────────────────────────────────────╮
  // │  Nav                                                                  │
  // ╰──────────────────────────────────────────────────────────────────────╯
  [Nav] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_ESC,   LGUI_T(KC_Q), KC_W,    OSM(MOD_LCTL), OSM(MOD_LSFT),    KC_PSCR,      DE_Y,    DE_UDIA,    KC_I,    DE_ODIA,    KC_P,    KC_ESC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       SS_CIRC,  DE_ADIA,    DE_SS,    LCTL_T(KC_D), LSFT_T(KC_F), KC_G,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, DE_QUOT, KC_DLR,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_ESC,   LT(Mouse, DE_Z), LALT_T(KC_X), KC_C, KC_V, KC_B,     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_ESC,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                               LT(Media, KC_ESC), LT(Nav, KC_ENT), LT(Mouse, KC_TAB),   KC_DEL, KC_BSPC
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  // ╭──────────────────────────────────────────────────────────────────────╮
  // │  Mouse                                                                │
  // ╰──────────────────────────────────────────────────────────────────────╯
  [Mouse] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_ESC,   LGUI_T(KC_Q), KC_W,    KC_E,    KC_R,    KC_T,         DPI_MOD,    DE_UDIA, KC_WH_U, DE_ODIA, KC_P,    KC_ESC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       DRG_TOG,  DE_ADIA, DE_SS,   KC_BTN2, KC_BTN1, KC_G,   DPI_RMOD, KC_MS_D, KC_WH_U, KC_MS_R, DE_QUOT, KC_DLR,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_ESC,   KC_X, LALT_T(KC_X), KC_BTN3, DRGSCRL, KC_B,     KC_WH_L, KC_BTN1, KC_WH_D, KC_WH_R, KC_INS,  KC_ESC,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                               KC_BTN2, KC_BTN1, KC_BTN3,   KC_BTN2, KC_ESC
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  // ╭──────────────────────────────────────────────────────────────────────╮
  // │  Button                                                               │
  // ╰──────────────────────────────────────────────────────────────────────╯
  [Button] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_ESC,   KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       SS_CIRC,  KC_F11,  C(KC_X), C(KC_C), C(KC_V), C(DE_Y),      KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_ESC,  KC_ESC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_ESC,   KC_F10,  C(DE_Z), KC_F2,   C(DE_Y), KC_PAUS,      KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_INS,  KC_ESC,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                               LT(Media, KC_ESC), LT(Nav, KC_ENT), LT(Mouse, KC_TAB),   KC_MSTP, KC_MPLY
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  // ╭──────────────────────────────────────────────────────────────────────╮
  // │  Fun                                                                  │
  // ╰──────────────────────────────────────────────────────────────────────╯
  [Fun] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_ESC,   KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       SS_CIRC,  KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCROLL_LOCK, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_ESC, KC_ESC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_ESC,   KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,      KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_INS,  KC_ESC,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                               LT(Media, KC_ESC), KC_APP, KC_TAB,   KC_MSTP, KC_MPLY
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  // ╭──────────────────────────────────────────────────────────────────────╮
  // │  Sym                                                                  │
  // ╰──────────────────────────────────────────────────────────────────────╯
  [Sym] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       SS_CIRC,  DE_LCBR, DE_AMPR, DE_ASTR, DE_LPRN, DE_RCBR,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_ESC,   DE_COLN, DE_DLR,  DE_PERC, DE_CIRC, DE_PLUS,      KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_ESC,  KC_ESC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_ESC,   DE_TILD, DE_EXLM, DE_AT,   DE_HASH, DE_PIPE,      KC_WH_L, KC_BTN1, KC_BTN2, KC_BTN3, KC_INS,  KC_ESC,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                               TD(TD_LOCK_LAYER), DE_RPRN, DE_UNDS,   KC_MSTP, KC_MPLY
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  // ╭──────────────────────────────────────────────────────────────────────╮
  // │  Media                                                                │
  // ╰──────────────────────────────────────────────────────────────────────╯
  [Media] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_ESC,   LGUI_T(KC_Q), KC_W,    KC_E,    KC_R,    KC_T,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       SS_CIRC,  DE_ADIA, DE_SS,   LCTL_T(KC_D), LSFT_T(KC_F), KC_G,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_ESC,  KC_ESC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_ESC,   LT(Button, DE_Z), LALT_T(KC_X), KC_C, KC_V, KC_B,     KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_INS,  KC_ESC,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                               LT(Media, KC_ESC), LT(Nav, KC_ENT), LT(Mouse, KC_TAB),   KC_MSTP, KC_MPLY
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  // ╭──────────────────────────────────────────────────────────────────────╮
  // │  Num                                                                  │
  // ╰──────────────────────────────────────────────────────────────────────╯
  [Num] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_ESC,   DE_LBRC, KC_7,    KC_8,    KC_9,    DE_RBRC,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SS_CRYPT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       SS_CIRC,  DE_SCLN, KC_4,    KC_5,    KC_6,    DE_EQL,       DM_RSTP, DM_REC1, DM_REC2, KC_MNXT, KC_ESC,  KC_ESC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_ESC,   DE_GRV,  KC_1,    KC_2,    KC_3,    DE_BSLS,      KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_INS,  KC_ESC,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                               TD(TD_LOCK_LAYER), KC_0, DE_MINS,   KC_BSPC, KC_SPC
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  // ╭──────────────────────────────────────────────────────────────────────╮
  // │  Emoji                                                                │
  // ╰──────────────────────────────────────────────────────────────────────╯
  // [Emoji] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       // KC_GRV,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         DE_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       // KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    X(SWEAT), X(GRIN), X(THUMBS_UP), X(ROFL), KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       // KC_LSFT,  DE_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                               // KC_LCTL, _______, MT(MOD_LSFT, KC_ENT),   KC_SPC, KC_BSPC
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  // ),
};
// clang-format on


const key_override_t slsh_ques_override = ko_make_basic(MOD_MASK_SHIFT, DE_SLSH, DE_QUES);
const key_override_t slsh_scln_coln     = ko_make_basic(MOD_MASK_SHIFT, DE_SCLN, DE_COLN);
const key_override_t slsh_comm_labk     = ko_make_basic(MOD_MASK_SHIFT, DE_COMM, DE_LABK);
const key_override_t slsh_dot_rabk      = ko_make_basic(MOD_MASK_SHIFT, DE_DOT,  DE_RABK);
const key_override_t slsh_quot_dquo     = ko_make_basic(MOD_MASK_SHIFT, DE_QUOT, DE_DQUO);

const key_override_t * const key_overrides[] = {
    &slsh_ques_override,
    &slsh_scln_coln,
    &slsh_comm_labk,
    &slsh_dot_rabk,
    &slsh_quot_dquo,
    NULL,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SS_CRYPT:
            if (record->event.pressed) {
                SEND_STRING("3NV1jY~-PO@n70J=");
            }
            return false;
        case SS_CIRC:
            if (record->event.pressed) {
                SEND_STRING("^");
            }
            return false;
    }
    return true;
}

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(Mouse);
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(Mouse);
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE
