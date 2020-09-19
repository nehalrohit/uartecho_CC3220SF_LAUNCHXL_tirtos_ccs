/*
 * mlx90614.h
 *
 *  Created on: 13-Jun-2020
 *      Author: dnk121
 */

#ifndef MLX90614_H_
#define MLX90614_H_
#include "i2c.h"
//#include "main.h"
#define MLX90614_I2CADDR 0x5A
//extern I2C_HandleTypeDef hi2c1;
// RAM
#define MLX90614_RAWIR1 0x04
#define MLX90614_RAWIR2 0x05
#define MLX90614_TA 0x06
#define MLX90614_TOBJ1 0x07
#define MLX90614_TOBJ2 0x08
// EEPROM
#define MLX90614_TOMAX 0x20
#define MLX90614_TOMIN 0x21
#define MLX90614_PWMCTRL 0x22
#define MLX90614_TARANGE 0x23
#define MLX90614_EMISS 0x24
#define MLX90614_CONFIG 0x25
#define MLX90614_ADDR 0x2E
#define MLX90614_ID1 0x3C
#define MLX90614_ID2 0x3D
#define MLX90614_ID3 0x3E
#define MLX90614_ID4 0x3F

/**
 * @brief Class to read from and control a MLX90614 Temp Sensor
 *
 */
//void MLX90614(uint8_t addr = MLX90614_I2CADDR);

float mlx90614_readObjectTempC(void);
float mlx90614_readAmbientTempC(void);
float mlx90614_readObjectTempF(void);
float mlx90614_readAmbientTempF(void);
uint16_t mlx90614_readEmissivityReg(void);
void mlx90614_writeEmissivityReg(uint16_t ereg);
float mlx90614_readEmissivity(void);
void mlx90614_writeEmissivity(double emissivity);

float mlx90614_readTemp(uint8_t reg);

uint16_t mlx90614_read16(uint8_t addr);
void mlx90614_write16(uint8_t addr, uint16_t data);
uint8_t mlx90614_crc8(uint8_t *addr, uint8_t len);

#endif /* MLX90614_H_ */
