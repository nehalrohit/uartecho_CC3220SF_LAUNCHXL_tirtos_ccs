/*
 * NexVariable.h
 *
 *  Created on: Jun 6, 2020
 *      Author: dnk125
 */

#ifndef NEXVARIABLE_H_
#define NEXVARIABLE_H_


//#include "Utilities.h"
//#include "NexTouch.h"
//#include "NexHardware.h"

#include <Nextion-Library/nextion/NexHardware.h>
#include <Nextion-Library/nextion/NexTouch.h>
#include <Nextion-Library/util/Utilities.h>
/**
     * Get the value of variable.
     *
     * @param number - an output parameter to save the value of variable.
     *
     * @retval true - success.
     * @retval false - failed.
     */
uint8_t NexVariable_getValue(struct NexObject *variable, uint32_t *number);

/**
     * Set the value of variable.
     *
     * @param number - the value of variable.
     *
     * @retval true - success.
     * @retval false - failed.
     */
uint8_t NexVariable_setValue(struct NexObject *variable, uint32_t number);




#endif /* NEXVARIABLE_H_ */
