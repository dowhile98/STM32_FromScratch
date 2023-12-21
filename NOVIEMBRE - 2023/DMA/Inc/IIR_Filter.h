/*
 * IIR_Filter.h
 *
 *  Created on: Nov 10, 2023
 *      Author: eplim
 */

#ifndef INC_IIR_FILTER_H_
#define INC_IIR_FILTER_H_

/* Includes .--------------------------------------------------------------*/
#include "main.h"
#include "arm_math.h"


/**
 * Fc = 2HZ
 * Fp = 12Hz
 * chevishev ii
 */
#define NUM_SECTIONS 3

float b[NUM_SECTIONS][3] = {
{6.72194465E-02, -1.24039980E-01, 6.72194465E-02},
{2.70520499E-02, -4.37929352E-02, 2.70520499E-02},
{5.09281647E-02, 5.09281647E-02, 0.00000000E+00} };

float a[NUM_SECTIONS][3] = {
{1.00000000E+00, -1.92971701E+00, 9.40115921E-01},
{1.00000000E+00, -1.83423322E+00, 8.44544382E-01},
{1.00000000E+00, -8.98143671E-01, 0.00000000E+00} };



__STATIC_INLINE void iir_coeff_reorder(float32_t b[][3],float32_t a[][3], float32_t h[], uint32_t numStage){
	uint32_t i, j;
	uint32_t n = 0;
	//reordena los coeficientes bn0, bn1,b2
	for( i = 0; i<numStage; i++){
		for(j = 0; j<3;j++){
			h[n] = b[i][j];
			n++;
		}
		//reordena los coeficientes an1,an2   -> se obvia an0
		for(j = 1; j<3;j++){
			h[n] = -1 * a[i][j];  //se niega los coeficientes
			n++;
		}
	}
}
#endif /* INC_IIR_FILTER_H_ */
