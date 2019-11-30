#define __main_c
#include "includeAll.h"
//=============================================================================
void main() {
  SysInit();
  VarsInit();
  //使能看门狗
  F_turnOnWDT();
  while (1) {
    //喂狗
    F_clearWDT();
    delayMs(20);
    GetKeys();
    if(D_keyValue1==keyValue){
      F_ledNeg();  //按键每按下一次则led取反一次
    }
  }
}
void delayMs(uint16_t msCount) {
  uint16_t i,j;
  for(i=0;i<=msCount;i++){
    for(j=0;j<=1000;j++){
      F_clearWDT();
    }
  }
}
   