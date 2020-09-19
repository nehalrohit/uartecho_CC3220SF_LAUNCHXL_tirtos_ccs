/*
 * NexPicture.h
 *
 *  Created on: Jul 1, 2020
 *      Author: dnk125
 */

#ifndef NEXTION_LIBRARY_NEXTION_NEXPICTURE_H_
#define NEXTION_LIBRARY_NEXTION_NEXPICTURE_H_

#include <Nextion-Library/nextion/NexHardware.h>
#include <Nextion-Library/nextion/NexTouch.h>
#include <Nextion-Library/util/Utilities.h>


/**
     * Get the value of picture.
     *
     * @param number - an output parameter to save the value of variable.
     *
     * @retval true - success.
     * @retval false - failed.
     */
uint8_t Nexpicture_getpic(struct NexObject *picture, uint32_t *number);

/**
     * Set the value of picture.
     *
     * @param number - the value of variable.
     *
     * @retval true - success.
     * @retval false - failed.
     */
uint8_t Nexpicture_setpic(struct NexObject *picture, uint32_t number);


#endif /* NEXTION_LIBRARY_NEXTION_NEXPICTURE_H_ */
