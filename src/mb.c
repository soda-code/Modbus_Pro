#include "mb.h"

//********************************************************************************
//@brief    :Initializes the Modbus context based on the specified mode.
//@param    :mb Pointer to the Modbus context structure.
//@param    :mode Modbus mode (RTU, ASCII, TCP).
//@return   :None
//********************************************************************************
mb_t *mb_g_all ; // Global variable to hold the Modbus context
void mb_init(mb_mode_t mode) 
{
    // Initialize the Modbus context based on the specified mode
    switch (mode) 
    {
        case MB_MODE_RTU:
            mb_g_all->init = mb_rtu_init;
            mb_g_all->RtuSend = mb_rtu_send;
            mb_g_all->RtuReceive = mb_rtu_receive;
            break;
        case MB_MODE_ASCII:
            mb_g_all->init = mb_ascii_init;
            mb_g_all->AsciiSend = mb_ascii_send;
            mb_g_all->AsciiReceive = mb_ascii_receive;
            break;
        case MB_MODE_TCP:
            mb_g_all->init = mb_tcp_init;
            mb_g_all->TcpSend = mb_tcp_send;
            mb_g_all->TcpReceive = mb_tcp_receive;
            break;
        default:
            // Handle invalid mode
            break;
    }
    // Call the initialization function for the selected mode
    if (mb_g_all->init) 
    {
        mb_g_all->init(); // Call the initialization function for the selected mode
    }
    mb_g_all->mode = mode; // Store the selected mode in the Modbus context
}

//********************************************************************************
//@brief  Sends data using the Modbus context.
//@param  data      Pointer to the data to be sent.
//@param  length    Length of the data to be sent.
//@return None
//********************************************************************************

void mb_send(mb_mode_t mode, const uint8_t *data, uint16_t length) 
{
    switch (mode) 
    {
        case MB_MODE_RTU:
            uint8_t device_addr = MB_DEVICE_ADDR_1; // Example device address
            uint8_t function_code = MB_FUNC_WRITE_SINGLE_REGISTER; // Example function code
            mb_g_all->RtuSend(device_addr, function_code, (uint8_t *)data, length); // Call the send function for Modbus RTU mode
            break;
        case MB_MODE_ASCII:
            mb_g_all->AsciiSend(data, length); // Call the send function for Modbus ASCII mode
            break;
        case MB_MODE_TCP:
            mb_g_all->TcpSend(data, length); // Call the send function for Modbus TCP
            break;
        default:
        // Handle invalid mode
        break;
    }

}

//********************************************************************************
//@brief  Receives data using the Modbus context.
//@param  buffer            Pointer to the buffer where received data will be stored.
//@param  buffer_length     Length of the buffer.
//@return None
//********************************************************************************

void mb_receive(mb_mode_t mode,mb_device_addr_t device_addr, uint8_t *buffer, uint16_t buffer_length) 
{
    switch (mode) 
    {
        case MB_MODE_RTU:
            mb_g_all->RtuReceive(device_addr, buffer, buffer_length); // Call the receive function for Modbus RTU mode
            break;
        case MB_MODE_ASCII:
            mb_g_all->AsciiReceive(buffer, buffer_length); // Call the receive function for Modbus ASCII mode
            break;
        case MB_MODE_TCP:
            mb_g_all->TcpReceive(buffer, buffer_length); // Call the receive function for Modbus TCP mode
            break;
        default:
        // Handle invalid mode
        break;
    }
}



