/****************************************************************
 * Modbus Library for RTU,
 * Author: li
 * Description: This library provides a unified interface for Modbus communication in RTU, ASCII, and TCP modes.
 * License: MIT License
 * Copyright (c) 2026 Your Name
 *  
 *****************************************************************/
#ifndef __MB_TIMER_H
#define __MB_TIMER_H

#include <stdint.h>

#include "mb_config.h"

void TIMER_Init(void); // Function prototype for initializing the timer
void TIMER_Start(uint32_t timeout); // Function prototype for starting the timer
void TIMER_Stop(void); // Function prototype for stopping the timer
uint8_t TIMER_IsExpired(void); // Function prototype for checking if the timer has expired

#endif // __MB_TIMER_H
