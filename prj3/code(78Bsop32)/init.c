#define __init_c
#include "includeAll.h"
//=============================================================================
void SysInit() {
	F_clearWDT();
  //时钟初始化
  CLKCON = 0x03; // Clock div 1  7.3728Mhz
  STPPCK = 0;
  STPFCK = 0;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  SELFCK = 1;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  // IO 模式初始化
	
  P3MODH = 0x2a;
	P1MODL = 0xaa;		//将模式置为推挽输出
	P1MODH = 0xaa;
	P3MODL = 0xa4;
	//P1MODL = 0xa8;		//将模式置为上拉输入
	
	//P_smgcom1 = 0;
  // IO 状态初始化
	  // IO 状态初始化
  P3_4 = 1;
  P3_2 = 1;
  P1_7 = 1;
	//F_ledOff();		//初始化为低电位（不亮）
	
	  
  F_ledOn();
  F_led2Off();
  F_led1On();
	
	//T2初始化
	TH2 = (65536 - 3686) / 256;
  RCP2H = TH2;
  TL2 = (65536 - 3686) % 256;
  RCP2L = TL2;
  TR2 = 1;
  ET2 = 1;
	
	  TH0 = (65536 - 3686) / 256;

  TL0 = (65536 - 3686) % 256;

  TR0 = 0;
  ET0 = 1;
  EA = 1; 
}
//=============================================================================
void VarsInit() {}