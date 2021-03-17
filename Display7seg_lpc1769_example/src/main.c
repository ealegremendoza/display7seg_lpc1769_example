/*
===============================================================================
 Name        : Display7seg_lpc1769_example.c
 Author      : ealegremendoza
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/
#include "headers.h"



void SystemInit(void)
{
	InitPLL();
	SysTick_Init(1000);
	/* Init display 7seg*/
	DISPLAY7SEG_Init();
}

int main(void) {
	SystemInit();

    while(1) {
    	/*	check systick	*/
    }
    return 0 ;
}
