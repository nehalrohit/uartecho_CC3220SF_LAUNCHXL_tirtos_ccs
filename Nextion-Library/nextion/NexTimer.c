/*
 * NexTimer.c
 *
 *  Created on: 18-Aug-2020
 *      Author: acer
 */


#include "NexTimer.h"

extern char buf[12];
extern char cmd[64];

uint8_t enable(struct NexObject *timer)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, 1, 10);
    strcat(cmd, timer->__name);
    strcat(cmd, ".en=");
    strcat(cmd, buf);

    sendCommand(cmd);
    return recvRetCommandFinished();
}

uint8_t disable(struct NexObject *timer)
{
    ClearString(buf);
    ClearString(cmd);

      utoa(buf, 0, 10);
      strcat(cmd, timer->__name);
      strcat(cmd, ".en=");
      strcat(cmd, buf);

      sendCommand(cmd);
      return recvRetCommandFinished();
}
