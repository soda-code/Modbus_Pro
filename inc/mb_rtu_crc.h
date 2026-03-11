/****************************************************************
 * Modbus Library for C
 * Author: li
 * Description: This library provides a unified interface for Modbus communication in RTU, ASCII, and TCP modes.
 * License: MIT License
 * Copyright (c) 2026 Your Name
 *  
 *****************************************************************/
#ifndef __MB_RTU_CRC_H
#define __MB_RTU_CRC_H

#include "mb_port.h"

uint16_t mb_rtu_crc16(const uint8_t *data, uint16_t length); // Function prototype for calculating CRC16 for Modbus RTU

#endif // __MB_RTU_CRC_H
