/****************************************************************
 *
 *  
 *****************************************************************/
#ifndef __MB_SERIAL_H
#define __MB_SERIAL_H
#include "mb_config.h"
#include "mb_rtu.h"


void mb_serial_init(void); // Function prototype for initializing the Modbus serial context
void mb_serial_send(const uint8_t *data, uint16_t length); // Function prototype for sending data using the Modbus serial context
void mb_serial_receive(uint8_t *buffer, uint16_t buffer_length); // Function prototype

#endif // __MB_SERIAL_H