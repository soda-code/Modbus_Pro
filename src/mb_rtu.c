/**************************************************************
 * @file    : mb_rtu.c
 * @brief   : Implementation of Modbus RTU mode functions.
 * @license : MIT License
 * @author  : Your Name
 * @date    : 2026-01-01
 *  
 *****************************************************************/

#include "mb_rtu.h"

//**************************************************************
//@brief  Initializes the Modbus RTU mode.
//@param  None
//@return None
//**************************************************************

void mb_rtu_init(void) 
{
    mb_serial_init();
}

//**************************************************************
//@brief  Initializes the Modbus RTU mode.
//@param  None
//@return None
//**************************************************************
void mb_rtu_send(const uint8_t *data, uint16_t length) 
{
    #if DMA_ENABLE
        // Implement DMA-based sending if enabled
        mb_serial_send_dma(data, length);
    #else
        // Implement standard sending method
        mb_serial_send(data, length);
    #endif
}

//**************************************************************
//@brief  Receives data in Modbus RTU mode.
//@param  buffer Pointer to the buffer where received data will be stored.
//@param  buffer_length Length of the buffer.
//@return None
//**************************************************************
void mb_rtu_receive(uint8_t *buffer, uint16_t buffer_length) 
{
    #if DMA_ENABLE
        // Implement DMA-based receiving if enabled
        mb_serial_receive_dma(buffer, buffer_length); 
    #else
        // Implement standard receiving method
        mb_serial_receive(buffer, buffer_length);
    #endif  
}

