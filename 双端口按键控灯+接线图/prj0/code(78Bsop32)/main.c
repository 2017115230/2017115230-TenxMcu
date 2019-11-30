#define __main_c
#include "includeAll.h"
//=============================================================================
void main() {
  SysInit();
  VarsInit();
  F_ledOn();
  delayMs(500);
  //使能看门狗
  F_turnOnWDT();
  while (1) {
    //喂狗
    F_clearWDT();
    // user coding
    delayMs(20);
    GetKeys();
    if (D_keyValue1 == keyValue) {
      F_ledNeg();  //按键每按一次led则取反
    }
    keyValue = D_keyNull;
  }
}
//=============================================================================
void delayMs(uint16_t msCount) {
  uint16_t i, j;
  for (i = 0; i < msCount; i++) {
    for (j = 0; j < 1000; j++) {
      /* code */
      F_clearWDT();
    }
  }
}
