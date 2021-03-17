/*
 * display7seg.h
 *
 *  Created on: 17 mar. 2021
 *      Author: ealegremendoza
 */

#ifndef DISPLAY7SEG_H_
#define DISPLAY7SEG_H_
#include "headers.h"

#define TABLE7SEG_DP_POS	7
#define TABLE7SEG_A_POS		6
#define TABLE7SEG_B_POS		5
#define TABLE7SEG_C_POS		4
#define TABLE7SEG_D_POS		3
#define TABLE7SEG_E_POS		2
#define TABLE7SEG_F_POS		1
#define TABLE7SEG_G_POS		0

#define	PIN_7SEG_B	0,4
#define	PIN_7SEG_A	0,5
#define	PIN_7SEG_F	0,10
#define	PIN_7SEG_G	0,11
#define	PIN_7SEG_E	2,0
#define	PIN_7SEG_D	2,1
#define	PIN_7SEG_C	2,2
#define	PIN_7SEG_DP	2,3

#define CANT_DIGITOS	2
#define PIN_7SEG_D1	2,4
#define PIN_7SEG_D0 2,5


#define	COMMON_CATHODE	0
#define	COMMON_ANODE	1
#define DISP7SEG_TYPE	COMMON_CATHODE

#if DISP7SEG_TYPE == COMMON_CATHODE
#define	DISP7SEG_LED_OFF	0
#define	DISP7SEG_LED_ON		1
#define DISP7SEG_DIG_OFF	1
#define DISP7SEG_DIG_ON		0
#elif DISP7SEG_TYPE == COMMON_ANODE
#define	DISP7SEG_LED_OFF	1
#define	DISP7SEG_LED_ON		0
#define DISP7SEG_DIG_OFF	0
#define DISP7SEG_DIG_ON		1
#endif


void DISPLAY7SEG_Init(void);
void DISPLAY7SEG_Convertir(uint32_t Numero);
void DISPLAY7SEG_Barrido(void);
void DISPLAY7SEG_Mostrar(uint32_t Numero);

#endif /* DISPLAY7SEG_H_ */
