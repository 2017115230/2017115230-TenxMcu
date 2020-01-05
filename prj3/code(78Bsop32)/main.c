#define __main_c
#include "includeAll.h"


//=============================================================================
void main() {
  SysInit();
  VarsInit();
	//使能看门狗
	F_turnOnWDT();
	
	/*
	uint8_t n;
　uint8_t code duan_ma[]= { 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//共阴
	//uint8_t code duan_ma[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};//共阳
　　while(1) { 
	 P1=0xfe; 
	 for(i=1;i<=6;i++) { 
		P0=duan_ma[i];
　　	delay_ms(400);
　　	P1=(P1<<1)|0x01;
　　}
　　}
	*/
	
	while(1){
		//清看门狗
		F_clearWDT();
		//业务代码
		TimeProcess();
		TaskSetting();
		TaskProcess();
		DisplayProcess();
	}
}

//=============================================================================
void TimeProcess() {
  static uint8_t timer5ms = 0;
  static uint16_t second = 0;

  if (b1ms) {
    // 1ms 执行一次
    b1ms = 0;
    timer5ms++;
    second++;
  
  }
  if (timer5ms >= D_5ms) {
    // 5ms 执行一次
    timer5ms = 0;
    
    GetKeys();
    GetTemp();
  }
  if (second >= D_1000ms) {
    // 1s 执行一次
    second = 0;
 
  }
   
  

}
//=============================================================================
void TaskProcess() {}
//=============================================================================
void TaskSetting() {
  
  if (D_keyValue1 == keyValue1) {
    ledflg = ~ledflg;
    TR0 = 1;
    index++;
      if(index == 100)
      {
        index = 0;
      }
    
  }
  keyValue1 = D_keyNull;


  if (D_keyValue1 == keyValue2) {
    ledflg = ~ledflg;
    TR0 = 1;
    index++;
      if(index == 100)
      {
        index = 0;
      }
  }
  keyValue2 = D_keyNull;
   

  if (D_keyValue1 == keyValue3) {
    ledflg = ~ledflg;
    TR0 = 1;
    index++;
      if(index == 100)
      {
        index = 0;
      }
  }
  keyValue3 = D_keyNull;
  

  if (D_keyValue1 == keyValue4) {
    ledflg = ~ledflg;
    TR0 = 1;
    index--;
      if(index < 0)
      {
        index = 1;
      }
          
  }
 keyValue4 = D_keyNull;
}


//=============================================================================
void DisplayProcess() {

 
  if (ledflg) {
    
    F_led1Off();
    F_led2On();
    gewei = curTemp % 10;
    ten = (curTemp-gewei)/10;
    smg_control(gewei,2);
    smg_control(ten,1);


  }  
  else {
     F_led1On();
    F_led2Off();
    gewei = curTemp%10;
    ten = (curTemp-gewei)/10;
    smg_control(gewei,2);
    smg_control(ten,1);
  }
    

}