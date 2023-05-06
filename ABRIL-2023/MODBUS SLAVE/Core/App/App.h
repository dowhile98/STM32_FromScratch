/*
 * App.h
 *
 *  Created on: Apr 22, 2023
 *      Author: jeffr
 */

#ifndef APP_APP_H_
#define APP_APP_H_

#include "rbuart.h"
/*Extern variables ---------------------------------------*/
extern rbuart_t rb_rx;
extern rbuart_t rb_tx;
/*
 * @brief
 */
void app_init(void);

#endif /* APP_APP_H_ */
