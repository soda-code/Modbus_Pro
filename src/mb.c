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
//@brief    :Initializes the Modbus context based on the specified mode.
//@param    :mode Modbus mode (RTU, ASCII, TCP).
//@return   :None
//**************************************************************

void mb_init_mode(mb_mode_t mode) 
{
    if (mb_g_all == NULL)
    {
        mb_g_all->mode = mode; // Set the Modbus mode in the global context
        mb_init(mb_g_all); // Initialize the Modbus context based on the specified mode
        return;
    }
    
}

//**************************************************************
//@brief    :Deinitializes the Modbus context and frees any allocated resources
//@param    :None
//@return   :None
//**************************************************************

void mb_deinit(void) 
{
    mb_g_all = NULL; // Clear the global Modbus context pointer
    // Implement deinitialization logic if necessary (e.g., free resources)
}

//**************************************************************
//@brief    :Sends data using the Modbus context's send function pointer.
//@param    :data Pointer to the data to be sent.
//@param    :length Length of the data to be sent.
//@return   :None
//**************************************************************

void mb_send(const uint8_t *data, uint16_t length) 
{
    if (mb_g_all->send) 
    {
        mb_g_all->send(data, length);
    }
}

//**************************************************************
//@brief    :Receives data using the Modbus context's receive function pointer.
//@param    :buffer Pointer to the buffer where received data will be stored.
//@param    :buffer_length Length of the buffer.
//@return   :None
//**************************************************************

void mb_receive(mb_t *mb, uint8_t *buffer, uint16_t buffer_length) 
{
    if (mb_g_all->receive) 
    {
        mb_g_all->receive(buffer, buffer_length);
    }
}



