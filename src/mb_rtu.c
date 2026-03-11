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

void mb_rtu_send(uint8_t device_addr, uint8_t function_code, uint8_t *data, uint16_t data_length) 
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

    PORT_Send(send_buffer, 4 + data_length); // Send the complete Modbus RTU frame
}

//**************************************************************
//@brief  Receives data in Modbus RTU mode.
//@param  buffer Pointer to the buffer where received data will be stored.
//@param  buffer_length Length of the buffer.
//@return None
//**************************************************************

void mb_rtu_receive(uint8_t *buffer, uint16_t buffer_length)    
{
   mb_rtu_frame_t received_frame; // Variable to hold the received Modbus RTU frame
    // Parse the received buffer to fill the Modbus RTU frame structure (parsing logic not shown here)
    // Example parsing logic (not complete):
    if (buffer_length >= 4) // Minimum length for a valid Modbus RTU frame
    {
        received_frame.device_addr = buffer[0]; // Extract device address
        received_frame.function_code = buffer[1]; // Extract function code
        received_frame.data_length = buffer_length - 4; // Calculate data length (total length - device address - function code - CRC)
        for (uint16_t i = 0; i < received_frame.data_length; i++) 
        {
            received_frame.data[i] = buffer[2 + i]; // Extract data
        }
        received_frame.crc = (buffer[2 + received_frame.data_length] << 8) | buffer[3 + received_frame.data_length]; // Extract CRC
    }   
}

