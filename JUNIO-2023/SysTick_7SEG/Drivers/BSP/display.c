/*
 * display.c
 *
 *  Created on: 19 jun. 2023
 *      Author: jeffr
 */
#include "display.h"
/*Private variables ----------------------------------------------*/
const uint8_t Table7Segment[] = {0x3F, 0x30, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};
/*Private function -----------------------------------------------*/
static uint8_t getNumberOfDigits(int32_t num){
	uint8_t count = 0;

	if(num == 0){
		return 1;
	}

	if(num < 0){
		num = -num;
	}
	while(num != 0){
		num /= 10;
		count++;
	}
	return count;
}

static void NumberDigits(int32_t val, uint8_t *hex, uint8_t digitNumber){
	uint8_t index = digitNumber - 1;
	uint8_t digit;
	while(val >0 && index >= 0){
		digit = val % 10;
		hex[index--] = digit;
		val /= 10;
	}
}

/*Function definition ---------------------------------------------*/
void display_init(Display_t *obj, uint8_t *frame){
	obj->pframe = frame;
	obj->state = 0;
}

void display_setVal_ex(Display_t *obj, uint8_t val, DP_Pos_t dp, uint8_t custom){

	uint8_t digitNumber;
	uint8_t index[DISPLAy_NUMBER_OF_DIGITS] = {0};
	//obtener cantidad de digitos
	if(custom == DISPLAY_CUSTOM){
		display_custom(obj, val);
	}else{
		digitNumber = getNumberOfDigits(val);
		//dividir el numero en digitos individuales
		NumberDigits(val, index, digitNumber);
		//establecer el valor del frame
		if(val < 10){
			obj->pframe[0] = 0;
			obj->pframe[1] = Table7Segment[index[0]];
		}else{
			obj->pframe[0] = Table7Segment[index[0]]; //10
			obj->pframe[1] = Table7Segment[index[1]]; //10
		}

		//dp
		obj->dp = dp;
	}


}

void display_update(Display_t *obj){
	uint8_t dp = obj->dp;
	switch(obj->state){
	case 0: //digito 1
		display_write(obj->pframe[0], DIGIT1, (dp & 0x1));
		obj->state = 2;
		break;
	case 1:
		display_write(0, DIGIT1, 0);
		obj->state = 2;
		break;
	case 2:
		display_write(obj->pframe[1], DIGIT2, (dp & 0x2));
		obj->state = 1;
		break;
	case 3:
	display_write(0, DIGIT2, 0);
	obj->state = 0;
	}
}
