/*
 * mlx90614.c
 *
 *  Created on: 13-Jun-2020
 *      Author: dnk121
 */
#include "mlx90614.h"



/**
 * @brief Read the raw value from the emissivity register
 *
 * @return uint16_t The unscaled emissivity value
 */
uint16_t mlx90614_readEmissivityReg(void) {
	return mlx90614_read16(MLX90614_EMISS);
}
/**
 * @brief Write the raw unscaled emissivity value to the emissivity register
 *
 * @param ereg The unscaled emissivity value
 */
void mlx90614_writeEmissivityReg(uint16_t ereg) {
	mlx90614_write16(MLX90614_EMISS, 0); // erase
	delay_ms(10);
	mlx90614_write16(MLX90614_EMISS, ereg);
	delay_ms(10);
}
/**
 * @brief Read the emissivity value from the sensor's register and scale
 *
 * @return double The emissivity value, ranging from 0.1 - 1.0
 */
float mlx90614_readEmissivity(void) {
	uint16_t ereg = mlx90614_read16(MLX90614_EMISS);
	return ((double) ereg) / 65535.0;
}
/**
 * @brief Set the emissivity value
 *
 * @param emissivity The emissivity value to use, between 0.1 and 1.0
 */
void mlx90614_writeEmissivity(double emissivity) {
	uint16_t ereg = (int)(0xffff * emissivity);

	mlx90614_writeEmissivityReg(ereg);
}

/**
 * @brief Get the current temperature of an object in degrees Farenheit
 *
 * @return double The temperature in degrees Farenheit
 */
float mlx90614_readObjectTempF(void) {
	return (mlx90614_readTemp(MLX90614_TOBJ1) * 9 / 5) + 32;
}
/**
 * @brief Get the current ambient temperature in degrees Farenheit
 *
 * @return double The temperature in degrees Farenheit
 */
float mlx90614_readAmbientTempF(void) {
	return (mlx90614_readTemp(MLX90614_TA) * 9 / 5) + 32;
}

/**
 * @brief Get the current temperature of an object in degrees Celcius
 *
 * @return double The temperature in degrees Celcius
 */
float mlx90614_readObjectTempC(void) {
	return mlx90614_readTemp(MLX90614_TOBJ1);
}

/**
 * @brief Get the current ambient temperature in degrees Celcius
 *
 * @return double The temperature in degrees Celcius
 */
float mlx90614_readAmbientTempC(void) {
	return mlx90614_readTemp(MLX90614_TA);
}

float mlx90614_readTemp(uint8_t reg) {
	float temp;

	temp = mlx90614_read16(reg);
	temp *= .02;
	temp -= 273.15;
	return temp;
}

/*********************************************************************/

uint16_t mlx90614_read16(uint8_t a) {
	uint16_t ret;
	HAL_I2C_Mem_Read(MLX90614_I2CADDR,a,(uint8_t *)&ret,2);
	return ret;
}

uint8_t mlx90614_crc8(uint8_t *addr, uint8_t len)
// The PEC calculation includes all bits except the START, REPEATED START, STOP,
// ACK, and NACK bits. The PEC is a CRC-8 with polynomial X8+X2+X1+1.
{
	uint8_t crc = 0,i=8;
	while (len--) {
		uint8_t inuint8_t = *addr++;
		for ( i = 8; i; i--) {
			uint8_t carry = (crc ^ inuint8_t) & 0x80;
			crc <<= 1;
			if (carry)
				crc ^= 0x7;
			inuint8_t <<= 1;
		}
	}
	return crc;
}

void mlx90614_write16(uint8_t a, uint16_t v) {
//	uint8_t pec;
    HAL_I2C_Mem_Write(MLX90614_I2CADDR,a,(uint8_t*)&v,2);
}
