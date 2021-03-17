/*
 * display7seg.c
 *
 *  Created on: 17 mar. 2021
 *      Author: ealegremendoza
 */
#include "display7seg.h"
#if DISP7SEG_TYPE == COMMON_CATHODE
/* CONSIDERACIONES:
 * Display 7seg catodo comun
 * Tiempo de barrido << 1/25Hz (ojo humano)
 * Tabla:
 * n°	dp	a	b	c	d	e	f	g	code
 * 0	0	1	1	1	1	1	1	0	0x7e
 * 1	0	0	1	1	0	0	0	0	0x30
 * 2	0	1	1	0	1	1	0	1	0x6d
 * 3	0	1	1	1	1	0	0	1	0x79
 * 4	0	0	1	1	0	0	1	1	0x33
 * 5	0	1	0	1	1	0	1	1	0x5b
 * 6	0	1	0	1	1	1	1	1	0x5f
 * 7	0	1	1	1	0	0	0	0	0x70
 * 8	0	1	1	1	1	1	1	1	0x7f
 * 9	0	1	1	1	0	0	1	1	0x73
 * */
const uint8_t	Codigo_7seg[]={	0x7e,	/* 0 */
								0x30,	/* 1 */
								0x6d,	/* 2 */
								0x79,	/* 3 */
								0x33,	/* 4 */
								0x5b,	/* 5 */
								0x5f,	/* 6 */
								0x70,	/* 7 */
								0x7f,	/* 8 */
								0x73};	/* 9 */
#elif DISP7SEG_TYPE == COMMON_ANODE
/* CONSIDERACIONES:
 * Display 7seg anodo comun
 * Tiempo de barrido << 1/25Hz (ojo humano)
 * Tabla:
 * n°	dp	a	b	c	d	e	f	g	code
 * 0	1	0	0	0	0	0	0	1	0x81
 * 1	1	1	0	0	1	1	1	1	0xcf
 * 2	1	0	0	1	0	0	1	0	0x92
 * 3	1	0	0	1	0	1	1	0	0x96
 * 4	1	1	0	1	1	1	0	0	0xdc
 * 5	1	0	1	1	0	1	0	0	0xb4
 * 6	1	0	1	1	0	0	0	0	0xb0
 * 7	1	0	0	1	1	1	1	1	0x9f
 * 8	1	0	0	0	0	0	0	0	0x00
 * 9	1	0	0	1	1	1	0	0	0x9c
 * */
const uint8_t	Codigo_7seg[]={	0x81,	/* 0 */
								0xcf,	/* 1 */
								0x92,	/* 2 */
								0x96,	/* 3 */
								0xdc,	/* 4 */
								0xb4,	/* 5 */
								0xb0,	/* 6 */
								0x9f,	/* 7 */
								0x00,	/* 8 */
								0x9c};	/* 9 */
#endif
/* Puedo poner hasta 10 displays en paralelo aproximadamente.
 * Pongo 2 display 7seg en paralelo comandados por 2 pines D0 y D1.
 * */
uint8_t Indice_Display=0;
uint8_t	Buffer_7seg[CANT_DIGITOS]={0};

void DISPLAY7SEG_Init(void)/* Driver */
{
	GPIO_Func(PIN_7SEG_A,FUNC_GPIO);
	GPIO_Func(PIN_7SEG_B,FUNC_GPIO);
	GPIO_Func(PIN_7SEG_C,FUNC_GPIO);
	GPIO_Func(PIN_7SEG_D,FUNC_GPIO);
	GPIO_Func(PIN_7SEG_E,FUNC_GPIO);
	GPIO_Func(PIN_7SEG_F,FUNC_GPIO);
	GPIO_Func(PIN_7SEG_G,FUNC_GPIO);
	GPIO_Func(PIN_7SEG_DP,FUNC_GPIO);

	GPIO_Dir(PIN_7SEG_A,DIR_SALIDA);
	GPIO_Dir(PIN_7SEG_B,DIR_SALIDA);
	GPIO_Dir(PIN_7SEG_C,DIR_SALIDA);
	GPIO_Dir(PIN_7SEG_D,DIR_SALIDA);
	GPIO_Dir(PIN_7SEG_E,DIR_SALIDA);
	GPIO_Dir(PIN_7SEG_F,DIR_SALIDA);
	GPIO_Dir(PIN_7SEG_G,DIR_SALIDA);
	GPIO_Dir(PIN_7SEG_DP,DIR_SALIDA);

	GPIO_Set(PIN_7SEG_A,DISP7SEG_LED_OFF);
	GPIO_Set(PIN_7SEG_B,DISP7SEG_LED_OFF);
	GPIO_Set(PIN_7SEG_C,DISP7SEG_LED_OFF);
	GPIO_Set(PIN_7SEG_D,DISP7SEG_LED_OFF);
	GPIO_Set(PIN_7SEG_E,DISP7SEG_LED_OFF);
	GPIO_Set(PIN_7SEG_F,DISP7SEG_LED_OFF);
	GPIO_Set(PIN_7SEG_G,DISP7SEG_LED_OFF);
	GPIO_Set(PIN_7SEG_DP,DISP7SEG_LED_ON);

	/*	PARA CONTROLAR 2 DIGITOS	*/
	GPIO_Func(PIN_7SEG_D0,FUNC_GPIO);
	GPIO_Func(PIN_7SEG_D1,FUNC_GPIO);
	GPIO_Dir(PIN_7SEG_D0,DIR_SALIDA);
	GPIO_Dir(PIN_7SEG_D1,DIR_SALIDA);
	GPIO_Set(PIN_7SEG_D0,DISP7SEG_DIG_OFF);
	GPIO_Set(PIN_7SEG_D1,DISP7SEG_DIG_OFF);
}

void DISPLAY7SEG_Convertir(uint32_t Numero)/* Driver */
{
	uint8_t codigo;
	if(Numero>9)
		return;
	codigo = Codigo_7seg[Numero];

	GPIO_Set(PIN_7SEG_A,(codigo>>TABLE7SEG_A_POS)&0x01);
	GPIO_Set(PIN_7SEG_B,(codigo>>TABLE7SEG_B_POS)&0x01);
	GPIO_Set(PIN_7SEG_C,(codigo>>TABLE7SEG_C_POS)&0x01);
	GPIO_Set(PIN_7SEG_D,(codigo>>TABLE7SEG_D_POS)&0x01);
	GPIO_Set(PIN_7SEG_E,(codigo>>TABLE7SEG_E_POS)&0x01);
	GPIO_Set(PIN_7SEG_F,(codigo>>TABLE7SEG_F_POS)&0x01);
	GPIO_Set(PIN_7SEG_G,(codigo>>TABLE7SEG_G_POS)&0x01);
	GPIO_Set(PIN_7SEG_DP,(codigo>>TABLE7SEG_DP_POS)&0x01);
}

void DISPLAY7SEG_Barrido(void)/* Driver */
{
	/*	APAGO DISPLAY	*/
	GPIO_Set(PIN_7SEG_D0,DISP7SEG_DIG_OFF);
	GPIO_Set(PIN_7SEG_D1,DISP7SEG_DIG_OFF);

	/*	ENVIO EL CODIGO, ESTAN EN PARALELO LOS 7SEG	*/
	DISPLAY7SEG_Convertir(Buffer_7seg[Indice_Display]);


	/*	ENCIENDO UNO A LA VEZ	*/
	switch(Indice_Display)
	{
	/*	Notar que el barrido se hace en orden inverso.	*/
		case 0:
			GPIO_Set(PIN_7SEG_D1,DISP7SEG_DIG_ON);
			break;
		case 1:
			GPIO_Set(PIN_7SEG_D0,DISP7SEG_DIG_ON);
			break;
		default:
			break;
	}
	Indice_Display++;
	Indice_Display%=CANT_DIGITOS;
}

void DISPLAY7SEG_Mostrar(uint32_t Numero)/* Primitiva */
{
	uint32_t i;
	for(i=0;i<CANT_DIGITOS;i++)
	{
		/* cuidado que esto carga los numeros al reves! Se debe modigicar
		 * el orden del barrido para solventar este problema.
		 */
		Buffer_7seg[i]=Numero%10;
		Numero/=10;
	}
}
