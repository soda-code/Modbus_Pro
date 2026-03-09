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
mb_t *mb_g_all = NULL; // Global variable to hold the Modbus context
void mb_init(mb_t *mb) 
{
    mb_g_all = mb; // Store the pointer to the Modbus context in the global variable
    switch (mb_g_all->mode) 
    {
        case MB_MODE_RTU:
            mb_g_all->init = mb_rtu_init;
            mb_g_all->send = mb_rtu_send;
            mb_g_all->receive = mb_rtu_receive;
            break;
        case MB_MODE_ASCII:
            mb_g_all->init = mb_ascii_init;
            mb_g_all->send = mb_ascii_send;
            mb_g_all->receive = mb_ascii_receive;
            break;
        case MB_MODE_TCP:
            mb_g_all->init = mb_tcp_init;
            mb_g_all->send = mb_tcp_send;
            mb_g_all->receive = mb_tcp_receive;
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
mb_rtu_config_t mb_rtu_inf = {0}; // Global variable to hold Modbus RTU configuration parameters
void mb_rtu_init(mb_rtu_config_t *config) 
{
    // Initialize RTU-specific resources (e.g., serial port)
    mb_rtu_inf = *config; // Store the configuration parameters in the global variable
    uasrt_init(mb_rtu_inf.usart, mb_rtu_inf.baud_rate, mb_rtu_inf.parity, mb_rtu_inf.stop_bits);
}

void mb_send(const uint8_t *data, uint16_t length) 
{
    if (mb_g_all->send) 
    {
        mb_g_all->send(data, length);
    }
}

void mb_receive(mb_t *mb, uint8_t *buffer, uint16_t buffer_length) 
{
    if (mb_g_all->receive) 
    {
        mb_g_all->receive(buffer, buffer_length);
    }
}



