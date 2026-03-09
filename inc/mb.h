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
#include <stdint.h>

typedef enum 
{
    MB_MODE_RTU,    // Modbus RTU mode
    MB_MODE_ASCII,  // Modbus ASCII mode
    MB_MODE_TCP     // Modbus TCP mode   
} mb_mode_t;

typedef struct 
{
    mb_mode_t mode;             // Modbus mode (RTU, ASCII, TCP)
    void (*init)(void); // Function pointer for initialization
    void (*send)(const uint8_t *data, uint16_t length); // Function pointer for sending data
    void (*receive)(uint8_t *buffer, uint16_t buffer_length); // Function pointer for receiving data
} mb_t;

void mb_init(mb_t *mb, mb_mode_t mode); // Function prototype for initializing the Modbus context
#endif // __MB_H