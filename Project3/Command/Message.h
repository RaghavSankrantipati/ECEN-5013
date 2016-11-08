/*
 * Message.h
 *
 *  Created on: Nov 1, 2016
 *      Author: moed4346
 */

#ifndef SOURCES_MESSAGE_H_
#define SOURCES_MESSAGE_H_
#include <Stdint.h>
#define MAX_DATA_SIZE 1
typedef enum Cmds_t
{
LED_RED=0x01,// LED red
LED_GREEN=0x02,// LED Green
LED_BLUE=0x33,// LED Blue
LED_VIOLET=0x04,// LED Violet
LED_CYAN=0x05,//LED Cyan
LED_WHITE=0x06,//LED White
LED_YELLOW=0x07//LED Yellow
} Cmds;
typedef struct CI_Msg_t
{
Cmds command;   // Command operation
uint8_t length;    // Size of message
uint8_t data[MAX_DATA_SIZE];   // Generic data payload
uint16_t checksum;   // Error detection checksum
}CI_Msg;
void message_tx(void);
uint16_t cal_check();
CI_Msg Bluep;


#endif /* SOURCES_MESSAGE_H_ */
