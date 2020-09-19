
#ifndef __NEXCONFIG_H__
#define __NEXCONFIG_H__
#include <Nextion-Library/nextion/Serial.h>
#include <unistd.h>

#define nexSerial_init(b,u)      beginSerial(b,u)
#define nexSerial_available()    serialAvailable()
#define nexSerial_read()         serialRead()
#define nexSerial_write(d)       serialWrite(d)
#define nexSerial_print(p)       Serial_Print(p) 
#define nexSerial_readBytes(b,l) Serial_ReadBytes(b, l)
#define nexDelay(d)              delay_ms(d)

#endif /* #ifndef __NEXCONFIG_H__ */
