#include "i2c.h"
#include <ti/sysbios/knl/Task.h>


uint8_t RX_Buffer[64];
uint8_t TX_Buffer[64];

/*
void delay_ms(uint32_t period)
{
    usleep(period * 1000);  //  1ms delay
}
*/
//
//void delay_ms_new(uint32_t mSDelay)
//
//{
//
//   uint8_t restore_key = Task_disable(); /* Disable TASKS so our checking of Clock_getTicks() is accurate. */
//
//    uint32_t Timestamp = Clock_getTicks();
//
//    uint64_t OverflowCheck = Timestamp + mSDelay; /* How close are we to rolling over the U32 system clock? */
//
//    if( OverflowCheck >= 0x00000000FFFFFFF0 )
//
//    {
//    while( Clock_getTicks() > 0x00000100 )    {
//
//   /* Do nothing while we wait for the clock to roll over. */
//    }
//
//   }
//
//    Timestamp = Clock_getTicks();
//
//    while( Clock_getTicks() < (Timestamp + mSDelay) )
//
//    {
//
//    /* Do nothing while we wait for the delay to expire. */
//
//    }
//
//Task_restore(restore_key); /* Restore TASK's to their previous state. */
//
//}
/******************************************************************************
 @brief HAL_I2C_Mem_Read
// *****************************************************************************/

int8_t  HAL_I2C_Mem_Read(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len)
{
    int index;

        memset(TX_Buffer,NULL,sizeof(TX_Buffer));
        memset(RX_Buffer,NULL,sizeof(RX_Buffer));

        /* get temperature value from sensor */
        TX_Buffer[0] = reg_addr;
        i2cTransaction.slaveAddress = dev_id;
        i2cTransaction.writeBuf = TX_Buffer;
        i2cTransaction.writeCount = 1;
        i2cTransaction.readBuf = RX_Buffer;
        i2cTransaction.readCount = len;

        if (I2C_transfer(i2c, &i2cTransaction))
        {
            for (index = 0; index < len; index++)
            {
                reg_data[index] = RX_Buffer[index];
            }
            return 0;
        }
        else
        {
         //   PRINTF("I2C failed!\r\n");
            i2cErrorHandler(&i2cTransaction);
            return 1;
        }

}
//**************************************************************************
// * @brief HAL_I2C_Mem_Write
//*****************************************************************************/
int8_t HAL_I2C_Mem_Write(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len)
{
    int index;

        memset(TX_Buffer,NULL,sizeof(TX_Buffer));

        TX_Buffer[0] = reg_addr;

        for (index = 0; index < len; index++)
        {
            TX_Buffer[index + 1] = reg_data[index];
        }

        i2cTransaction.slaveAddress = dev_id;
        i2cTransaction.writeBuf = TX_Buffer;
        i2cTransaction.writeCount = len+1;
        i2cTransaction.readBuf = NULL;
        i2cTransaction.readCount = 0;

        if (I2C_transfer(i2c, &i2cTransaction))
        {
            return 0;
        }
        else
        {
          //  PRINTF("I2C failed!\r\n");
            return 1;
        }

}


void i2cErrorHandler(I2C_Transaction *transaction)
{
    switch (transaction->status) {
    case I2C_STATUS_TIMEOUT:
        //Display_printf(display, 0, 0, "I2C transaction timed out!");
        break;
    case I2C_STATUS_CLOCK_TIMEOUT:
        //Display_printf(display, 0, 0, "I2C serial clock line timed out!");
        break;
    case I2C_STATUS_ADDR_NACK:
        //Display_printf(display, 0, 0, "I2C slave address 0x%x not"
          //  " acknowledged!", transaction->slaveAddress);
        break;
    case I2C_STATUS_DATA_NACK:
     //   Display_printf(display, 0, 0, "I2C data byte not acknowledged!");
        break;
    case I2C_STATUS_ARB_LOST:
      //  Display_printf(display, 0, 0, "I2C arbitration to another master!");
        break;
    case I2C_STATUS_INCOMPLETE:
        //Display_printf(display, 0, 0, "I2C transaction returned before completion!");

        break;
    case I2C_STATUS_BUS_BUSY:
      //  Display_printf(display, 0, 0, "I2C bus is already in use!");
       I2C_cancel(i2c);
       I2C_close(i2c);
       I2C_Init();
        break;
    case I2C_STATUS_CANCEL:
      //  Display_printf(display, 0, 0, "I2C transaction cancelled!");
        break;
    case I2C_STATUS_INVALID_TRANS:
     //   Display_printf(display, 0, 0, "I2C transaction invalid!");
        break;
    case I2C_STATUS_ERROR:
     //   Display_printf(display, 0, 0, "I2C generic error!");
        break;
    default:
 //       Display_printf(display, 0, 0, "I2C undefined error case!");
        break;
    }
}
