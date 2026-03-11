/****************************************************************
 * Modbus Library for C
 * Author: li
 * Description: This library provides a unified interface for Modbus communication in RTU, ASCII, and TCP modes.
 * License: MIT License
 * Copyright (c) 2026 Your Name
 *  
 *****************************************************************/
#ifndef __MB_H
#define __MB_H

#include "mb_rtu.h"
#include "mb_ascii.h"
#include "mb_tcp.h"

typedef enum 
{
    MB_MODE_RTU,    // Modbus RTU mode
    MB_MODE_ASCII,  // Modbus ASCII mode
    MB_MODE_TCP     // Modbus TCP mode   
} mb_mode_t;

typedef struct 
{
    mb_mode_t mode;     // Modbus mode (RTU, ASCII, TCP)
    void (*init)        (void); // Function pointer for initialization
    void (* RtuSend)    (uint8_t device_addr, uint8_t function_code, uint8_t *data, uint16_t length); // Function pointer for sending data
    void (* AsciiSend)  (const uint8_t *data, uint16_t length); // Function pointer for sending data
    void (* TcpSend)    (const uint8_t *data, uint16_t length); // Function pointer for sending data
    void (* RtuReceive) (uint8_t *buffer, uint16_t buffer_length); // Function pointer for receiving data
    void (* AsciiReceive) (uint8_t *buffer, uint16_t buffer_length); // Function pointer for receiving data
    void (* TcpReceive) (uint8_t *buffer, uint16_t buffer_length); // Function pointer for receiving data
} mb_t;

void mb_init(mb_mode_t mode); // Function prototype for initializing the Modbus context
void mb_send(mb_mode_t mode, const uint8_t *data, uint16_t length); // Function prototype for sending data using the Modbus context
void mb_receive(mb_mode_t mode, uint8_t *buffer, uint16_t buffer_length); // Function prototype for receiving data using the Modbus context
#endif // __MB_H
