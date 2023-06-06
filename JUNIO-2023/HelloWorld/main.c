/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct{
    uint32_t ODR;
    uint32_t IDR;
    uint32_t MODER;
}GPIO_t;


typedef uint8_t (*cmd_write_ptr)(uint8_t);
typedef uint8_t (*data_write_ptr)(uint8_t);



typedef struct
{
    uint8_t row;
    uint8_t col;
    /**
     * @brief 
     * 
     */
    cmd_write_ptr cmd;      //low level layer
    data_write_ptr data;    //low level layer
}LCD_TypeDef_t;

/**
 * @brief 
 * 
 * @param byte 
 * @return uint8_t 
 */
uint8_t cmd_write(uint8_t byte){
    
    printf("cmd->0x%X\r\n", byte);
    return 0;
}
uint8_t data_write(uint8_t byte){
    printf("data->0x%X\r\n", byte);
    return 0;
}
/**
 * OPERADORES A NIVEL DE BITS
 * AND -> &   
 * OR  -> |
 * XOR -> ^
 * NOT -> ~
 * SHIFT -> <<  >>
 */
/**
 * int  (2bytes)   (4bytes)
 * float
 * char
 */

/**
 * uint8_t int8_t  (1byte)
 * uint16_t int16_t (2byte)
 * uint32_t int32_t (4bytes)
 * uint64_t int64_t (8bytes)
 * 
 */
LCD_TypeDef_t LCD = {.cmd = cmd_write, .data = data_write, .col =16, .row = 2};
int main(void){
    GPIO_t GPIOA =  {0};
    //el bit 3 del registro ODR en 1
    // GPIOA.ODR = GPIOA.ODR | 1<<3;
    GPIOA.ODR |= 1<<4;


    // if(GPIOA.ODR & 1U<<3){
    //     printf("bit 3 establecido\r\n");
    // }else{
    //     printf("bit 3 clear\r\n");
    // }
    LCD.cmd(0x03);
    LCD.cmd(0x2);
    LCD.data(0x23);
    return EXIT_SUCCESS;
}