#include "mb_rtu.h"

//**************************************************************
//@brief  Initializes the Modbus RTU mode.
//@param  None
//@return None
//**************************************************************
void mb_rtu_send(const uint8_t *data, uint16_t length) 
{

    uasrt_send(mb_rtu_inf.usart, data, length);
}

//**************************************************************
//@brief  Receives data in Modbus RTU mode.
//@param  buffer Pointer to the buffer where received data will be stored.
//@param  buffer_length Length of the buffer.
//@return None
//**************************************************************
void mb_rtu_receive(uint8_t *buffer, uint16_t buffer_length) 
{

    uasrt_receive(mb_rtu_inf.usart, buffer, buffer_length);
}

