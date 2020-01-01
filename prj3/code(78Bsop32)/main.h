#ifndef __main_h
#define __main_h
// Hal: exp: #define P_led P10 -----------------

// Const: exp: #define D_data 1 ----------------

// Globle Var -----------------------------------------
#ifdef __main_c
uint8_t modeValue; //pin脚模式标志
#else
extern uint8_t modeValue;

#endif


// Action Macro: exp: #define F_getData() ------
#define Mode_Neg() modeValue = ~modeValue		//模式标志取反
// Function ------------------------------------
void delayMs(uint16_t time);
void TimeProcess();
void TaskSetting();
void TaskProcess();
void DisplayProcess();
void led_disp();
#endif