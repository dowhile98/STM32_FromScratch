/*
 * display.h
 *
 *  Created on: 19 jun. 2023
 *      Author: jeffr
 */

#ifndef BSP_DISPLAY_H_
#define BSP_DISPLAY_H_

/*Includes ----------------------------------------------------*/
#include <stdint.h>
/*Include s----------------------------------------------------*/
#define DP_ON		1
#define DP_OFF		0
#define DISPLAy_NUMBER_OF_DIGITS	2
#define DISPLAY_VAL		0
#define DISPLAY_CUSTOM	1
/*Typedef -----------------------------------------------------*/
typedef enum{
	DIGIT1,
	DIGIT2
}Digit_t;
typedef enum{
	DISPLAY_DP_DIGIT1 = 0x1,
	DISPLAy_DP_DIGIT2 = 0x2
}DP_Pos_t;


typedef struct{
	uint8_t *pframe;
	uint8_t state;
	DP_Pos_t dp;
}Display_t;
/*Function prototype ------------------------------------------*/
void display_write(uint8_t data, uint8_t digit, uint8_t dp);

void display_custom(Display_t *obj, uint8_t val);

void display_init(Display_t *obj, uint8_t *frame);

void display_setVal_ex(Display_t *obj, uint8_t val, DP_Pos_t dp, uint8_t custom);

void display_update(Display_t *obj);

#endif /* BSP_DISPLAY_H_ */
