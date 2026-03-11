/***************************************************************************************
 * File_name:    mb_config.h
 * Author:       li
 * Description:  This file contains configuration parameters for Modbus communication.
 * License:      MIT License
 * Copyright (c) 2026 Your Name
 ***************************************************************************************/

#ifndef __MB_CONFIG_H
#define __MB_CONFIG_H

#include <stdint.h>

//****************** Debug Configuration ******************
#define MB_DEBUG     1          // Enable debug mode for Modbus communication (0: Disable, 1: Enable)

//****************** Buffer Configuration ******************
#define MB_MAX_BUFFER_SIZE 256  // Maximum buffer size for Modbus communication

//****************** FreeRTOS Enable ******************
#define MB_FREERTOS_ENABLE 0    // Enable FreeRTOS support for Modbus communication (0: Disable, 1: Enable)

//******************* DMA Configuration *******************
#define DMA_ENABLE   0          // Enable DMA support for Modbus communication (0: Disable, 1: Enable)

//******************* USB Configuration *******************
#define USB_ENABLE   1          // Enable USB support for Modbus communication (0: Disable, 1: Enable)

#endif // __MB_CONFIG_H
