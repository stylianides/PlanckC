
#include QMK_KEYBOARD_H

// Debugging Keybindings
#define DB_BREAK KC_F9			// Breakpoint
#define DB_START KC_F5			// Program Start
#define DB_STOP  LSFT(KC_F5)	// Program Stop
#define DB_STPIN KC_F11			// Step In
#define DB_STPOV KC_F10			// Step Over
#define DB_STPCR LCTL(KC_F10)	// Step to cursor
#define DB_BRKW  0 				// Break  Window
#define DB_WTCW  1 				// Watch  Window
#define DB_OUTW  2 				// Output Window

// -----Navigation Keybindings-----
#define TAB_BCK RCS(KC_TAB)		// Tab Backwards
#define TAB_FRW LCTL(KC_TAB)	// Tab Forwards

// ------Drawing Keybindings-------
#define DR_BRSH KC_B			// Brush
#define DR_BRSZ KC_D			// Brush size
#define DR_CLRP KC_I        	// Colour picker
#define DR_COPY KC_C			// Copy
#define DR_ERSR KC_E			// Eraser
#define DR_FILL KC_U			// Fill
#define DR_FLIP KC_F			// Flip
#define DR_GRID LCTL(KC_G)		// Show grid lines
#define DR_HAND KC_SPACE		// Hand tool
#define DR_LASO KC_L			// Lasso tool
#define DR_LAYR KC_V			// Layer select
#define DR_ROTA KC_O			// Rotate
#define DR_SMDG KC_S			// Smudge
#define DR_SNAP KC_X			// Zoom snap out
#define DR_RECT KC_K			// Rectangle Select
#define DR_RULR KC_R			// Ruler
#define DR_ZOOM KC_Z			// Zoom

enum planck_layers {
  QWERTY,
  NAV_DBG,
  SYMBL,
  FUNCT,
  DRAW,
  MACRO,
};

     
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	if (record->event.pressed) {
		switch(id) {
			case DB_WTCW:
				return MACRO(D(LCTL), T(L), T(K), U(LCTL), END);
			case DB_OUTW:
				return MACRO(D(LCTL), T(L), T(O), U(LCTL), END);
			case DB_BRKW:
				return MACRO(D(LCTL), T(L), T(B), U(LCTL), END);
		}
	}
	return MACRO_NONE;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/*-------------------------------------------------------------------------------------------------------------------------------
			Qwerty
 * 			,-----------------------------------------------------------------------------------.
 * 			| Del  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * 			|------+------+------+------+------+------+------+------+------+------+------+------|
 * 			| Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * 			|------+------+------+------+------+------+------+------+------+------+------+------|
 * 			| LS/{ |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   _  | RS/} |
 * 			|------+------+------+------+------+------+------+------+------+------+------+------|
 * 			| LC/( |MO(FU)|  Win | LA/[ |MO(SY)|    Space    |MO(NA)| RA/] |      |TO(DR)| RC/) |
 * 			`-----------------------------------------------------------------------------------'
 */
 
 
[QWERTY] = LAYOUT_planck_grid(
    KC_DEL,  KC_Q,  	   KC_W,    KC_E,    KC_R,       KC_T,   KC_Y,   KC_U,        KC_I,    KC_O,   KC_P,     KC_BSPC,
    KC_TAB,	 KC_A,  	   KC_S,    KC_D,    KC_F,       KC_G,   KC_H,   KC_J,        KC_K,    KC_L,   KC_SCLN,  KC_ENT,
    KC_LSPO, KC_Z,  	   KC_X,    KC_C,    KC_V,       KC_B,   KC_N,   KC_M,        KC_COMM, KC_DOT, KC_UNDS,  KC_RSPC,
    KC_LCPO, MO(FUNCT),    KC_LGUI, KC_LAPO, MO(SYMBL),  KC_SPC, KC_SPC, MO(NAV_DBG), KC_RAPC, KC_NO,  TO(DRAW), KC_RCPC
),






/*-------------------------------------------------------------------------------------------------------------------------------
 *			Navigation_Debug																						 
 * 			,-----------------------------------------------------------------------------------.					 
 * 			| Esc  |AltF4 |      |Pg Up |Pg Dn |      |OutWin|WtcWin|  Up  |BrkWin|RghtCl| Bksp |					 										 
 * 			|------+------+------+------+------+------+------+------+------+------+------+------|					 
 * 			| Tab  |      |      | Home | End  |      |StepCs| Left | Down |Right |Break |Enter |					 
 * 			|------+------+------+------+------+------+------+------+------+------+------+------|					 
 * 			|LShift|      |      |TabBck|TabFrw|      |Start |StepOv|      |StepIn| Stop |RShift|					 
 * 			|------+------+------+------+------+------+------+------+------+------+------+------|					 
 * 			| LCtl |      |  Win | LAlt | Caps |    Space    |      | RAlt |      |      | RCtl |					 
 * 			`-----------------------------------------------------------------------------------'					 
 */

 
[NAV_DBG] = LAYOUT_planck_grid(
    KC_ESC,  LALT(KC_F4), KC_NO,   KC_PGUP, KC_PGDN, KC_NO,  M(DB_OUTW),  M(DB_WTCW),  KC_UP,    M(DB_BRKW),  KC_APP,   KC_BSPC,
    KC_TAB,  KC_NO,       KC_NO,   KC_HOME, KC_END,  KC_NO,  DB_STPCR, 	  KC_LEFT,     KC_DOWN,  KC_RGHT,     DB_BREAK, KC_ENT,
    KC_LSFT, KC_NO,       KC_NO,   TAB_BCK, TAB_FRW, KC_NO,  DB_START, 	  DB_STPOV,    KC_NO,    DB_STPIN,    DB_STOP,  KC_RSFT,
    KC_LCTL, KC_NO,       KC_LGUI, KC_LALT, KC_CAPS, KC_SPC, KC_SPC,   	  KC_NO,       KC_RALT,  KC_NO,       KC_NO,    KC_RCTL
),






/*-------------------------------------------------------------------------------------------------------------------------------
			Symbol
 * 			,-----------------------------------------------------------------------------------.
 * 			| Esc  |   !  |   @  |  #   |   $  |   %  |   ^  |   7  |   8  |   9  |   &  | Bksp |
 * 			|------+------+------+------+------+------+------+------+------+------+------+------|
 * 			| Tab  |   ~  |   `  |  -   |   >  |   =  |   +  |   4  |   5  |   6  |   "  |Enter |
 * 			|------+------+------+------+------+------+------+------+------+------+------+------|
 * 			|LShift|   ?  |   \  |  |   |   /  |   *  |   *  |   1  |   2  |   3  |   '  |RShift|
 * 			|------+------+------+------+------+------+------+------+------+------+------+------|
 * 			| LCtl |      |  Win | LAlt |  LT2 |    Space    |   0  | RAlt |      |      | RCtl |
 * 			`-----------------------------------------------------------------------------------'
 */
 
 
[SYMBL] = LAYOUT_planck_grid(
    KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_7, KC_8,    KC_9,  KC_AMPR, KC_BSPC,
    KC_TAB,  KC_GRV,  KC_TILD, KC_MINS, KC_GT,   KC_EQL,  KC_PLUS, KC_4, KC_5,    KC_6,  KC_DQUO, KC_ENT,
    KC_LSFT, KC_QUES, KC_BSLS, KC_PIPE, KC_SLSH, KC_ASTR, KC_ASTR, KC_1, KC_2,    KC_3,  KC_QUOT, KC_RSFT,
    KC_LCTL, KC_NO,   KC_LGUI, KC_LALT, KC_NO,   KC_SPC,  KC_SPC,  KC_0, KC_RALT, KC_NO, KC_NO,   KC_RCTL
),




/*-------------------------------------------------------------------------------------------------------------------------------
			Function
 * 			,-----------------------------------------------------------------------------------.
 * 			|Reset |  F1  |  F2  |  F3  |  F4  |      |      |      | Vol+ |      |      |PrtSrc|
 * 			|------+------+------+------+------+------+------+------+------+------+------+------|
 * 			| Tab  |  F5  |  F6  |  F7  |  F8  |      |      | Mute | Vol- | Play |      |Enter |
 * 			|------+------+------+------+------+------+------+------+------+------+------+------|
 * 			|LShift|  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |      |RShift|
 * 			|------+------+------+------+------+------+------+------+------+------+------+------|
 * 			| LCtl |  LT3 |  Win | LAlt |      |    Sleep    |      | RAlt |      |      | RCtl |
 * 			`-----------------------------------------------------------------------------------'
 */
 
 
[FUNCT] = LAYOUT_planck_grid(
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_NO,   KC_NO,   KC_NO,   KC_VOLU,  KC_NO,   KC_NO,   KC_PSCR,
    KC_TAB,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_NO,   KC_NO,   KC_MUTE, KC_VOLD,  KC_MPLY, KC_NO,   KC_ENT,
    KC_LSFT, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_RSFT,
    KC_LCTL, KC_NO,   KC_LGUI, KC_LALT, KC_NO,   KC_SLEP, KC_SLEP, KC_NO,   KC_RALT,  KC_NO,   KC_NO,   KC_RCTL
), 





/*-------------------------------------------------------------------------------------------------------------------------------
			Drawing
 * 			,-----------------------------------------------------------------------------------.
 * 			| Esc  |Lasso | Rect |Eraser| Ruler|Delete|      |      |      |      |      |      |
 * 			|------+------+------+------+------+------+------+------+------+------+------+------|
 * 			| Tab  |Rotate|Smudge|BrSize| Flip |Grid  |      |      |      |      |      |
 * 			|------+------+------+------+------+------+------+------+------+------+------+------|
 * 			|LShift| Zoom |ZmSnap| Copy |Layer |Brush |      |      |      |      |      |      |
 * 			|------+------+------+------+------+------+------+------+------+------+------+------|
 * 			| LCtl |      |      | LAlt |ClrPck|     Hand    |      |      |      |TO(QW)|      |
 * 			`-----------------------------------------------------------------------------------'
 */ 


[DRAW] = LAYOUT_planck_grid(
    KC_ESC,  DR_LASO, DR_RECT, DR_ERSR, DR_RULR, KC_DEL,   	 KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, 	   KC_NO,
    KC_TAB,  DR_ROTA, DR_SMDG, DR_BRSZ, DR_FLIP, LCTL(KC_G), KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, 	   KC_NO,
    KC_LSFT, DR_ZOOM, DR_SNAP, DR_COPY, DR_LAYR, DR_BRSH,    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, 	   KC_NO,
    KC_LCTL, KC_NO,   KC_NO,   KC_LALT, DR_CLRP, DR_HAND, 	 DR_HAND, KC_NO, KC_NO, KC_NO, TO(QWERTY), KC_NO
)

};