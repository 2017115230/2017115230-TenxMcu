#define __keys_c
#include "includeAll.h"
//=============================================================================
//按键改为一次完成的按下与松开
void GetKeys() {
  static uint8_t tempKeyValue = D_keyNull;

  if (P_key1 == 0) {
    tempKeyValue = D_keyValue1;
  } else {
    keyValue = tempKeyValue;
    tempKeyValue = D_keyNull;
  }

}