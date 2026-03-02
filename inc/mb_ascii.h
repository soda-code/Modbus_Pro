/****************************************************************
 * Modbus Library for C
 * Author: li
 * Description: This library provides a unified interface for Modbus communication in RTU, ASCII, and TCP modes.
 * License: MIT License
 * Copyright (c) 2026 Your Name
 *  
 *****************************************************************/
#ifndef __MB_ASCII_H
#define __MB_ASCII_H
#include <stdint.h>

void mb_ascii_init(void);                                         // Function prototype for initializing Modbus ASCII mode
void mb_ascii_send(const uint8_t *data, uint16_t length);         // Function prototype for sending data in Modbus ASCII mode
void mb_ascii_receive(uint8_t *buffer, uint16_t buffer_length);   // Function prototype for receiving data in Modbus ASCII mode

#endif // __MB_ASCII_H