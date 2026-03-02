/****************************************************************
 * Modbus Library for C
 * Author: li
 * Description: This library provides a unified interface for Modbus communication in RTU, ASCII, and TCP modes.
 * License: MIT License
 * Copyright (c) 2026 Your Name
 *  
 *****************************************************************/
#ifndef __MB_TCP_H
#define __MB_TCP_H
#include <stdint.h>

void mb_tcp_init(void);                                         // Function prototype for initializing Modbus TCP mode
void mb_tcp_send(const uint8_t *data, uint16_t length);         // Function prototype for sending data in Modbus TCP mode
void mb_tcp_receive(uint8_t *buffer, uint16_t buffer_length);   // Function prototype for receiving data in Modbus TCP mode

#endif // __MB_TCP_H