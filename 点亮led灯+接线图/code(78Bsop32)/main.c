#define __main_c
#include "includeAll.h"
//=============================================================================
void main() {
  SysInit();  //初始化
  VarsInit();  //初始化
  while (1) {
    //使能看门狗
    F_turnOnWDT(); 
    // user coding
    F_ledOff();  //灯灭
    delayMs(500);
    F_ledOn();  //灯亮
    delayMs(500);
  }
}
//=============================================================================
//延时函数
void delayMs(uint16_t msCount) {
  uint16_t i, j;  //定义变量（C51的for中不能定义局部变量，所以在这里定义）
  for (i = 0; i < msCount; i++) {
    for (j = 0; j < 1000; j++) {
      /* code */
    }
  }
}