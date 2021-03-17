/*
 * GPIO.h
 *
 *  Created on: 16 mar. 2021
 *      Author: ealegremendoza
 */

#ifndef GPIO_H_
#define GPIO_H_
#include "headers.h"

#define FUNC_GPIO	0
#define	DIR_ENTRADA	0
#define DIR_SALIDA	1

void GPIO_Func(uint32_t Port, uint32_t Pin, uint32_t Function);
void GPIO_Mode(uint32_t Port,uint32_t Pin, uint32_t Mode);
void GPIO_Dir(uint32_t Port, uint32_t Pin, uint32_t Dir);
void GPIO_Set(uint32_t Port, uint32_t Pin, uint32_t Estate);
uint32_t GPIO_Get (uint32_t Port, uint32_t Pin);

#endif /* GPIO_H_ */
