/*
 * i2c.h
 *
 *  Created on: May 27, 2020
 *      Author: dnk125
 */

#ifndef I2C_H_
#define I2C_H_
/**** Includes ****************************************************************/
#include <ti/drivers/I2C.h>
#include <ti/display/Display.h>
#include <ti/sysbios/knl/Clock.h>
#include <time.h>

#include"string.h"
#include <stdio.h>
#include "stdint.h"
#include <unistd.h>

/**** Preprocessing directives (#define) **************************************/
#define HAL_OK  0

extern I2C_Handle      i2c;
extern I2C_Transaction i2cTransaction;
extern Display_Handle display;

/**** Global variables ********************************************************/

/**** Local constants  ********************************************************/
void delay_ms(uint32_t period);
void delay_ms_new(uint32_t mSDelay);
int8_t HAL_I2C_Mem_Read(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len);
int8_t HAL_I2C_Mem_Write(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len);
void I2C_Init();

void i2cErrorHandler(I2C_Transaction *transaction);




#endif /* I2C_H_ */
