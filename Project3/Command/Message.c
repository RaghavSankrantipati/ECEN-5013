/*
 * Message.c
 *
 *  Created on: Nov 1, 2016
 *      Author: moed4346
 */
#include "Message.h"
#include "uart.h"
#include "led_config.h"
#include "MKL25Z4.h"
#include <string.h>
#include "led.h"
int i=0;

void Decode_Msg(CI_Msg *s)
{

		if(s->command==LED_CONFIG)
		{
			Led_config(s);
		}

}


