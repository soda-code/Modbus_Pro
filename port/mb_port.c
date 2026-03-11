/*****************************************************************************************
 * FILE: mb_port.c
 * Description: This file contains the implementation for Modbus communication ports
 * Author: li
 * Description: This library provides a unified interface for Modbus communication in RTU, ASCII, and TCP modes.
 * License: MIT License
 * Copyright (c) 2026 Your Name
 * 
 ***************************************************************************************************/
#include "mb_port.h"

#if USB_ENABLE // If USB support is enabled, include USB-related headers
    #include "usbd_core.h"
    #include "usbd_desc.h"
    #include "usbd_cdc.h"
    #include "usbd_cdc_interface.h"
#else
    #include "usart.h"
#endif

#include "freertos_app.h"
#include "FreeRTOS.h"
#include "task.h"

#if USB_ENABLE // If USB support is enabled, declare USB-related variables
    USBD_HandleTypeDef USBD_Device;        /* USB Device处理结构体 */
    extern volatile uint8_t g_device_state;/* USB连接 情况 */
#else

#endif

//**************************************************************
//@brief  Initializes the communication port (e.g., UART, Ethernet).
//@param  None
//@return None
//**************************************************************

void PORT_Init(void) 
{
    #if USB_ENABLE
        // Initialize the communication port for debugging (e.g., USART for serial output)
        USBD_Init(&USBD_Device, &VCP_Desc, 0);
        USBD_RegisterClass(&USBD_Device, USBD_CDC_CLASS);
        USBD_CDC_RegisterInterface(&USBD_Device, &USBD_CDC_fops);
        USBD_Start(&USBD_Device);
    #else
        USART1_Init(); // Example: Initialize USART1 for Modbus RTU communication
    #endif
}

//**************************************************************
//@brief  Sends data through the communication port.
//@param  data Pointer to the data to be sent.
//@param  length Length of the data to be sent.
//@return None
//**************************************************************
void PORT_Send(const uint8_t *data, uint16_t length) 
{
    #if USB_ENABLE
        // Send data through the communication port (e.g., USB CDC)
        cdc_vcp_data_tx((uint8_t *)data, length); // Example: Send data through USB CDC
    #else
        USART_Send_Buff((uint8_t *)data, length); // Example: Send data through USART1
    #endif
}

//**************************************************************
//@brief  Receives data through the communication port.
//@param  buffer Pointer to the buffer where received data will be stored.
//@param  buffer_length Length of the buffer.
//@return None
//**************************************************************
void PORT_Receive(uint8_t *buffer, uint16_t buffer_length) 
{
    #if USB_ENABLE
        // Receive data through the communication port (e.g., USB CDC)
        cdc_vcp_data_rx(buffer, buffer_length); // Example: Receive data through USB CDC
    #else
        USART_Receive_Buff(buffer, buffer_length); // Example: Receive data through USART1
    #endif
}