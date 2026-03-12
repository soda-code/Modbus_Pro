#include "mb_rtu.h"
#include "mb_rtu_crc.h"

//**************************************************************
//@brief  Initializes the Modbus RTU mode.
//@param  None
//@return None
//**************************************************************


void mb_rtu_init(void) 
{
    PORT_Init();
}


//**************************************************************
//@brief  Initializes the Modbus RTU mode.
//@param  device_addr:      Modbus device address, 
//@param  function_code:    Modbus function code, 
//@param  data:             Pointer to the data to be sent, 
//@param  data_length:      Length of the data to be sent.
//@return None
//**************************************************************
mb_rtu_adu_t mb_rtu_tx_adu;
void mb_rtu_send(uint8_t device_addr, mb_function_code_t function_code, uint8_t *data, uint16_t data_length) 
{
    uint8_t send_buffer[MB_MAX_BUFFER_SIZE]; // Example buffer size, adjust as needed
    uint16_t crc = 0xff; // Variable to hold CRC value

    send_buffer[0] = device_addr; // Set device address
    send_buffer[1] = function_code; // Set function code
    // Copy data to send buffer
    for (uint16_t i = 0; i < data_length; i++) 
    {
        send_buffer[2 + i] = data[i];
    }
    // Calculate CRC and append to send buffer (CRC calculation function not shown here)
    crc = mb_rtu_crc16(send_buffer, 2 + data_length); // Calculate CRC for device address, function code, and data
    send_buffer[2 + data_length] = (crc >> 8) & 0xFF; // Append CRC high byte
    send_buffer[3 + data_length] = crc & 0xFF; // Append CRC

    // Enter critical section to ensure thread safety during transmission
    MB_ENTER_CRITICAL(); // Enter critical section to ensure thread safety during transmission
    PORT_Send(send_buffer, 4 + data_length); // Send the complete Modbus RTU frame
    MB_EXIT_CRITICAL(); // Exit critical section
}

//**************************************************************
//@brief  Receives data in Modbus RTU mode.
//@param  buffer Pointer to the buffer where received data will be stored.
//@param  buffer_length Length of the buffer.
//@return None
//**************************************************************

void mb_rtu_receive( uint8_t *buffer, uint16_t buffer_length)    
{
    uint8_t device_addr = buffer[0]; // Extract device address from the received frame
    uint8_t received_function_code = buffer[1]; // Extract function code from the received frame
    uint16_t crc_received = (buffer[buffer_length - 2] << 8) | buffer[buffer_length - 1]; // Extract CRC from the received frame

    if(device_addr > MB_DEVICE_ADDR_MAX) // Check if the device address is valid
    {
        return; // Ignore frames with invalid device address
    }
    if(received_function_code > MB_FUNC_MAX) // Check if the function code is valid
    {
        return; // Ignore frames with invalid function code
    }
    if(mb_rtu_crc16(buffer, buffer_length-2) != crc_received) // Validate CRC of the received frame
    {
        return; // Ignore frames with invalid CRC
    }
    if (buffer_length < 4) // Minimum length for a valid Modbus RTU frame (device address + function code + CRC)
    {
        switch(received_function_code)
        {
            case MB_FUNC_READ_COILS:
            case MB_FUNC_READ_DISCRETE_INPUTS:
            case MB_FUNC_READ_HOLDING_REGISTERS:
            case MB_FUNC_READ_INPUT_REGISTERS:
            case MB_FUNC_WRITE_SINGLE_COIL:
            case MB_FUNC_WRITE_SINGLE_REGISTER:
            case MB_FUNC_WRITE_MULTIPLE_COILS:
            case MB_FUNC_WRITE_MULTIPLE_REGISTERS:
                // Handle specific function code errors if needed
                break;
            default:
                // Handle illegal function code error
                break;
        }
    } 
    else
    {
        // Process the received frame (e.g., validate CRC, extract data, etc.)
        // This is a placeholder for actual processing logic
        // You would typically validate the CRC and then extract the data based on the function code
    }
}

