/*
 * main.h
 *
 *  Created on: Nov 29, 2023
 *      Author: jeffr
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "main.h"
#include <stdbool.h>
#include "arm_math.h"
typedef struct{
	uint8_t rx[256];
	uint8_t len;
}RxData_t;

extern RxData_t data;
extern bool  rxFlag;

extern uint16_t adcData[3];

extern arm_biquad_casd_df1_inst_f32 IIR0;
#endif /* MAIN_H_ */
