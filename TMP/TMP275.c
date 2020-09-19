#include "TMP275.h"
#include "i2c.h"

static int measurementDelay;    //28ms, 55ms, 110ms, 220ms


void Faults_que() {
    uint8_t config = readConfigRegister();
    config &= 0xe7;

    config |= 0x00;
    writeConfigRegister(config);

}

void set_ploarity()
{
    uint8_t config = readConfigRegister();
       config &= 0xFB;
        config |= 0x04;
        writeConfigRegister(config);
}
uint8_t TMP_init() {

  setResolution(12);
  Thermostat_mode();
return 0;
}


uint8_t readConfigRegister() {

	uint8_t config=0;
	HAL_I2C_Mem_Read(TMP275_ADDR, CONF_REG, &config,1);

	return config;
}

void writeConfigRegister(uint8_t config) {

    HAL_I2C_Mem_Write(TMP275_ADDR, CONF_REG, &config,1);
}

float getTemperature() {
	
    delay_ms_new(220);
	uint8_t rxBuffer[2];
	uint16_t result=0;
    HAL_I2C_Mem_Read(TMP275_ADDR, TEMP_REG,rxBuffer, 2);
    result = (rxBuffer[0] << 8 | rxBuffer[1]);
 return ((float)result/256);        //256 try
 //   return ((float)(int)result / 32) / 8;
}


void setResolution(uint8_t res) {
    uint8_t config = readConfigRegister() & 0x9F;   //Mask out the res bits
    config |= 3 << 5;    //12 bit

    writeConfigRegister(config);
    //Change measurement delay
    if (res == 10)
        measurementDelay = 28;
    else if (res == 11)
        measurementDelay = 55;
    else if (res == 12)
        measurementDelay = 110;
    else
        measurementDelay = 220;
}

void enableShutdownMode(bool enable) {
	uint8_t config = readConfigRegister();
	config &= 0xFE;		//Mask out LSB
	if (enable)
		config |= 0x01;
	writeConfigRegister(config);
}

void enableOS() {
	enableShutdownMode(false);
	delay_ms(measurementDelay);

	enableShutdownMode(true);
}

void enableComparatorMode() {
	uint8_t config =0;
	config=readConfigRegister();
     config &= 0xFD;

	writeConfigRegister(config);
}


void setHighTempThreshold(float  threshold) {
	
    uint8_t  buffer[2];
         uint16_t value= (uint16_t)((int)(threshold * 8) << 5);
          buffer[0]=(value) >> 8 ;
          buffer[1]=value &0x00FF;
          HAL_I2C_Mem_Write(TMP275_ADDR, THIGH_REG,buffer, 2);

}

void setLowTempThreshold(float threshold) {

	 uint8_t  buffer[2];
	  uint16_t value= (uint16_t)((int)(threshold * 8) << 5);

	   buffer[0]=(value) >> 8 ;
	   buffer[1]=value &0x00FF;
	   HAL_I2C_Mem_Write(TMP275_ADDR, TLOW_REG,buffer, 2);

}

float getHighTempThreshold() {

	uint8_t rxBuffer[2];
    uint16_t result=0;
    HAL_I2C_Mem_Read(TMP275_ADDR, THIGH_REG, rxBuffer, 2);
   
    result = (rxBuffer[0] << 8 | rxBuffer[1]);
    //   return ((float)(int)result / 32) / 8;
    return ((float)result/256);        //256 try

}

float getLowTempThreshold() {

    uint8_t rxBuffer[2];
        uint16_t result=0;

    HAL_I2C_Mem_Read(TMP275_ADDR, TLOW_REG, rxBuffer, 2);
    result = (rxBuffer[0] << 8 | rxBuffer[1]);
     //     return ((float)(int)result / 32) / 8;
          return ((float)result/256);        //256 try

}

int getFaults() {
	uint8_t config = readConfigRegister();
	config = (config >> 3) & 0x03;
	return config;
}




void Thermostat_mode(){

    uint8_t config =0;
        config=readConfigRegister();
         config &= 0xFD; //0xFD;
        config |= 0x02;   //intruppt mode
        writeConfigRegister(config);
}



