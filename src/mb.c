#include "mb_rtu.h"
#include "mb_ascii.h"
#include "mb_tcp.h"
#include "mb.h"

//**************************************************************
//@brief    :Initializes the Modbus context based on the specified mode.
//@param    :mb Pointer to the Modbus context structure.
//@param    :mode Modbus mode (RTU, ASCII, TCP).
//@return   :None
//**************************************************************
void mb_init(mb_t *mb, mb_mode_t mode) 
{
    switch (mode) 
    {
        case MB_MODE_RTU:
            mb->init = mb_rtu_init;
            mb->send = mb_rtu_send;
            mb->receive = mb_rtu_receive;
            break;
        case MB_MODE_ASCII:
            mb->init = mb_ascii_init;
            mb->send = mb_ascii_send;
            mb->receive = mb_ascii_receive;
            break;
        case MB_MODE_TCP:
            mb->init = mb_tcp_init;
            mb->send = mb_tcp_send;
            mb->receive = mb_tcp_receive;
            break;
        default:
            // Handle invalid mode
            break;
    }
}

//**************************************************************
//@brief  Initializes the Modbus RTU mode.
//@param  None
//@return None
//**************************************************************
void mb_rtu_init(void) 
{
    // Initialize RTU-specific resources (e.g., serial port)
}

void mb_send(mb_t *mb, const uint8_t *data, uint16_t length) 
{
    if (mb->send) 
    {
        mb->send(data, length);
    }
}

void mb_receive(mb_t *mb, uint8_t *buffer, uint16_t buffer_length) 
{
    if (mb->receive) 
    {
        mb->receive(buffer, buffer_length);
    }
}



