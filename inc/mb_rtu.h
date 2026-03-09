/****************************************************************
 * Modbus Library for C
 * Author: li
 * Description: This library provides a unified interface for Modbus communication in RTU, ASCII, and TCP modes.
 * License: MIT License
 * Copyright (c) 2026 Your Name
 *  
 *****************************************************************/
#ifndef __MB_RTU_H
#define __MB_RTU_H
#include <stdint.h>
#include "mb_serial.h"



void mb_rtu_init(void);  // Function prototype for initializing Modbus RTU mode
void mb_rtu_send(const uint8_t *data, uint16_t length);         // Function prototype for sending data in Modbus RTU mode
void mb_rtu_receive(uint8_t *buffer, uint16_t buffer_length);   // Function prototype for receiving data in Modbus RTU mode

#endif // __MB_RTU_H