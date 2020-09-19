#ifndef SERIAL_H
#define SERIAL_H

#include <ti/drivers/UART.h>
#include <unistd.h>

#include <stdint.h>

extern uint8_t aRXbuffer[2];
extern UART_Handle uart;
// connects the internal peripheral in the processor and configures it
//void beginSerial(long baud,UART_HandleTypeDef *huart);
// disconnects the internal peripheral in the processor
void closeSerial();
//write the single charatcter in desigerd port
void serialWrite(unsigned char c);
//check wheather the data is available in deisgnerd port or not
int serialAvailable();
//writing the single bytes in to desigred port
void serialWrite(unsigned char c);
//read the perticular port
char serialRead();
//flush the port data
 void UART_readCallBack(UART_Handle uartHandle, void *ptr, size_t size);
void serialFlush();
void Serial_Print( char *txt);
unsigned char Serial_ReadBytes(char *buf, unsigned char len);
void printByte(unsigned char c);
void printNewline();
void printString(const char *s);
void printStringln(const char *s);
void printIntegerInBase(unsigned long n, unsigned long base);
void puthex(char ch);
void printInteger(long n);
void printHex(unsigned long n);
void printOctal(unsigned long n);
void printBinary(unsigned long n);
void delay_ms(uint32_t i);
void delay_ms_new(uint32_t mSDelay);

#endif

