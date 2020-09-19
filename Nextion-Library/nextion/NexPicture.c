/*
 * NexPicture.c
 *
 *  Created on: Jul 1, 2020
 *      Author: dnk125
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Nextion-Library/nextion/NexHardware.h>
#include <Nextion-Library/nextion/NexPicture.h>
#include <Nextion-Library/util/Utilities.h>
extern char buf[12];
extern char cmd[64];
uint8_t Nexpicture_getpic(struct NexObject *picture, uint32_t *number)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, picture->__name);
    strcat(cmd, ".pic");
    sendCommand(cmd);
    return recvRetNumber(number);
}
uint8_t Nexpicture_setpic(struct NexObject *picture, uint32_t number){

    ClearString(buf);
    ClearString(cmd);

    utoa(buf,number, 10);
    strcat(cmd, picture->__name);
    strcat(cmd, ".pic=");
    strcat(cmd, buf);

    sendCommand(cmd);
    return recvRetCommandFinished();
}
