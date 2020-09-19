/*
 * NexVariable.c
 *
 *  Created on: Jun 6, 2020
 *      Author: dnk125
 */
//#include "NexVariable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "../util/Utilities.h"
#include <Nextion-Library/nextion/NexHardware.h>
#include <Nextion-Library/nextion/NexVariable.h>
#include <Nextion-Library/util/Utilities.h>
extern char buf[12];
extern char cmd[64];
uint8_t NexVariable_getValue(struct NexObject *variable, uint32_t *number) {
	ClearString(cmd);
	strcat(cmd, "get ");
	strcat(cmd, variable->__name);
	strcat(cmd, ".val");
	sendCommand(cmd);
	return recvRetNumber(number);
}

uint8_t NexVariable_setValue(struct NexObject *variable, uint32_t number) {
	ClearString(buf);
	ClearString(cmd);

	utoa(buf,number, 10);
	strcat(cmd, variable->__name);
	strcat(cmd, ".val=");
	strcat(cmd, buf);

	sendCommand(cmd);
	return recvRetCommandFinished();
}
