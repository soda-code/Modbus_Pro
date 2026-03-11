/****************************************************************
 * Modbus Library for RTU,
 * Author: li
 * Description: This library provides a unified interface for Modbus communication in RTU, ASCII, and TCP modes.
 * License: MIT License
 * Copyright (c) 2026 Your Name
 *  
 *****************************************************************/
#ifndef __MB_PORT_H
#define __MB_PORT_H

#include <stdint.h>

#include "mb_config.h"

void PORT_Init(void); // Function prototype for initializing the port (e.g., UART, Ethernet)
void PORT_Send(const uint8_t *data, uint16_t length); // Function prototype for sending data through the port
void PORT_Receive(uint8_t *buffer, uint16_t buffer_length); // Function prototype for receiving data through the port

#endif // __MB_PORT_H
