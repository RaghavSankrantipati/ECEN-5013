/*
 * Message.h
 *
 *  Created on: Nov 1, 2016
 *      Author: moed4346
 */

#ifndef SOURCES_MESSAGE_H_
#define SOURCES_MESSAGE_H_
#include <Stdint.h>
#define MAX_DATA_SIZE 4
typedef enum Cmds_t
{
	GET_TEMP = 0x01,
	SET_SPEED= 0x02,
	LED_CONFIG= 0x33,
	SET_LPM=0x04,
} Cmds;
typedef struct CI_Msg_t
{
Cmds command;   // Command operation
uint8_t length;    // Size of message
uint8_t data[MAX_DATA_SIZE];   // Generic data payload
uint16_t checksum;   // Error detection checksum
}CI_Msg;

void Decode_Msg(CI_Msg *s);
uint16_t cal_check();
CI_Msg z;
//CI_Msg* Color;
//Color=&z;
#endif /* SOURCES_MESSAGE_H_ */
