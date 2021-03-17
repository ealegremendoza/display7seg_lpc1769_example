/*
 * headers.h
 *
 *  Created on: 16 mar. 2021
 *      Author: ealegremendoza
 */

#ifndef HEADERS_H_
#define HEADERS_H_

typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

#include <cr_section_macros.h>
#include <stdio.h>
#include "Regs.h"
#include "Oscilador.h"
#include "GPIO.h"
#include "systick.h"
#include "display7seg.h"
/* Comment for stand-alone mode */
#include "debug.h"

#ifndef DEBUG_H_
#define DEBUGOUT(a);
#else
#define DEBUGOUT(a);  printf(a);
#endif


#endif /* HEADERS_H_ */
