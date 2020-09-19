//#include "wiring_private.h"
//#include "PrkrutiConstant.h"
//#include "Wiring.h"
//#include "stm32l4xx_hal.h"
#include <string.h>
#include <stdio.h>
//#include "main.h"
#include "Serial.h"
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Task.h>
#include "../util/Utilities.h"
#include <time.h>
/* Private variables ---------------------------------------------------------*/
//UART_HandleTypeDef *uart;
extern uint8_t flag;

#define RX_BUFFER_SIZE 128
unsigned char rx_buffer2[RX_BUFFER_SIZE];
int rx_buffer_head2 = 0;
int rx_buffer_tail2 = 0;

uint8_t aTXbuffef[] = "STM32 UART Rx_Tx With interrupt\r\n";
uint8_t aRXdata[100];
uint8_t RXindex = 0;
uint8_t aRXbuffer[2];

//writing the single byte in to desigred port
void serialWrite(unsigned char c)
{
    UART_write(uart, &c, 1);
}

//check wheather the data is available in deisgnerd port or not
int serialAvailable()
{
    return ((RX_BUFFER_SIZE + rx_buffer_head2 - rx_buffer_tail2)
            % RX_BUFFER_SIZE);
}

//read the perticular port
char serialRead()
{

    unsigned char c;
    // if the head isn't ahead of the tail, we don't have any characters
    if (rx_buffer_head2 == rx_buffer_tail2)
    {
        return 0;
    }
    else
    {
        c = rx_buffer2[rx_buffer_tail2];
        rx_buffer_tail2 = (rx_buffer_tail2 + 1) % RX_BUFFER_SIZE;
        return c;
    }
}

//flush the port data
void serialFlush()
{

    rx_buffer_tail2 = 0;
    rx_buffer_head2 = rx_buffer_tail2;
}
/*******************************************************************************
 * @fn      UART_readCallBack
 *
 * @brief
 *
 * @param
 *
 * @return
 ******************************************************************************/
void UART_readCallBack(UART_Handle uartHandle, void *ptr, size_t size)
{
//    uRXFlag = 1;

    unsigned char c;
    c = aRXbuffer[0];
    int i = (rx_buffer_head2 + 1) % RX_BUFFER_SIZE;
    if (i != rx_buffer_tail2)
    {
        rx_buffer2[rx_buffer_head2] = c;
        rx_buffer_head2 = i;
    }
    int ret = UART_read(uart, aRXbuffer, 1);
}

void delay_ms_new(uint32_t mSDelay)
{
        uint8_t restore_key = Task_disable(); /* Disable TASKS so our checking of Clock_getTicks() is accurate. */
        uint32_t Timestamp = Clock_getTicks();
        uint64_t OverflowCheck = Timestamp + mSDelay; /* How close are we to rolling over the U32 system clock? */
        if( OverflowCheck >= 0x00000000FFFFFFF0 ) {
        while( Clock_getTicks() > 0x00000100 )    {
       /* Do nothing while we wait for the clock to roll over. */
             }

        }
        Timestamp = Clock_getTicks();
        while( Clock_getTicks() < (Timestamp + mSDelay) ) {
        /* Do nothing while we wait for the delay to expire. */
        }
        Task_restore(restore_key); /* Restore TASK's to their previous state. */

}

void delay_ms(uint32_t number_of_seconds)
{
    usleep(1000 * number_of_seconds);

    // Converting time into milli_seconds
    /* int milli_seconds = 1000 * number_of_seconds;

     // Storing start time
     clock_t start_time = clock();

     // looping till required time is not achieved
     while (clock() < start_time + milli_seconds)
     ;*/
}
void Serial_Print(char *txt)
{
    /* short i = strlen((char*) txt);
     while (1) {
     serialWrite(*txt);
     ++txt;
     --i;
     if (i == 0) {
     break;
     }
     }*/
    UART_write(uart, txt, strlen(txt));
}
/*
unsigned char Serial_ReadBytes(char *buf, unsigned char len)
{
    unsigned char cnt = 0;
    while (len--)
    {
        if (serialAvailable())
        {
            buf[cnt++] = serialRead();
        }
    }
    return cnt;
}
*/


unsigned char Serial_ReadBytes(char *buf, unsigned char len)
{
    unsigned char cnt = 0;
    if (len < rx_buffer_head2 - rx_buffer_tail2)
    {
        ArrayCopy(buf, &rx_buffer2[rx_buffer_tail2], len);
        rx_buffer_tail2 += len;
        cnt = len;
    }
    else if (len == rx_buffer_head2 - rx_buffer_tail2)
    {
        ArrayCopy(buf, &rx_buffer2[rx_buffer_tail2], len);
        rx_buffer_tail2 = 0;
        rx_buffer_head2 = 0;
        cnt = len;
    }
    else
    {   delay_ms(5);
        ArrayCopy(buf, &rx_buffer2[rx_buffer_tail2], rx_buffer_head2 - rx_buffer_tail2);
        cnt = rx_buffer_head2 - rx_buffer_tail2;
        rx_buffer_tail2 = 0;
        rx_buffer_head2 = 0;
    }
    return cnt;
}
