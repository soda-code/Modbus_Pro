/****************************************************************
 * Modbus Library for C
 * Author: li
 * Description: This library provides a unified interface for Modbus communication in RTU, ASCII, and TCP modes.
 * License: MIT License
 * Copyright (c) 2026 Your Name
 *  
 *****************************************************************/
#ifndef __MB_CONFIG_H
#define __MB_CONFIG_H

#include <stdint.h>

// Configuration parameters for Modbus communication
#define DMA_ENABLE   0          // Enable DMA support for Modbus communication (0: Disable, 1: Enable)
#define MB_DEBUG     1          // Enable debug mode for Modbus communication (0: Disable, 1: Enable)
#define MB_MAX_BUFFER_SIZE 256  // Maximum buffer size for Modbus communication



#endif // __MB_CONFIG_H