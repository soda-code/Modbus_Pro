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

typedef struct  // Structure to hold Modbus RTU configuration parameters
{
    void *usart;           // Serial port handle
    uint32_t baud_rate;    // Communication speed in bits per second
    uint8_t parity;        // Parity configuration (e.g., None, Even, Odd)
    uint8_t stop_bits;     // Number of stop bits (e.g., 1, 2)
} mb_rtu_config_t;
extern mb_rtu_config_t mb_rtu_inf ; // Global variable to hold Modbus RTU configuration parameters
void mb_rtu_init(mb_rtu_config_t *config);  // Function prototype for initializing Modbus RTU mode
void mb_rtu_send(const uint8_t *data, uint16_t length);         // Function prototype for sending data in Modbus RTU mode
void mb_rtu_receive(uint8_t *buffer, uint16_t buffer_length);   // Function prototype for receiving data in Modbus RTU mode

#endif // __MB_RTU_H