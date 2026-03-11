/***************************************************************************************
 * File_name:    mb_rtu_crc.c
 * Author:       li
 * Description:  This file contains the implementation of the CRC16 calculation for Modbus RTU communication.
 * License:      MIT License
 * Copyright (c) 2026 Your Name
 * *****************************************************************************************/
#include "mb_rtu_crc.h"

//**************************************************************************
//@brief  Calculates the CRC16 for Modbus RTU communication.
//@param  data          Pointer to the data for which to calculate CRC.
//@param  length        Length of the data.
//@return The calculated CRC16 value.
//**************************************************************************
uint16_t mb_rtu_crc16(const uint8_t *data, uint16_t length) 
{
    uint16_t crc = 0xFFFF; // Initial CRC value
    for (uint16_t i = 0; i < length; i++) 
    {
        crc ^= data[i]; // XOR byte into least sig. byte of crc
        for (uint8_t j = 0; j < 8; j++) 
        {
            if (crc & 0x0001) 
            {
                crc >>= 1; // Shift right
                crc ^= 0xA001; // XOR with polynomial
            } 
            else 
            {
                crc >>= 1; // Just shift right
            }
        }
    }
    return crc; // Return the calculated CRC value
}

//**************************************************************************
//@brief  Calculates the CRC32 for Modbus RTU communication.
//@param  data          Pointer to the data for which to calculate CRC.
//@param  length        Length of the data.
//@return The calculated CRC32 value.
//**************************************************************************
uint32_t mb_rtu_crc32(const uint8_t *data, uint32_t length) 
{
    uint32_t crc = 0xFFFFFFFF; // Initial CRC value
    for (uint32_t i = 0; i < length; i++) 
    {
        crc ^= data[i]; // XOR byte into least sig. byte of crc
        for (uint8_t j = 0; j < 8; j++) 
        {
            if (crc & 0x00000001) 
            {
                crc >>= 1; // Shift right
                crc ^= 0xEDB88320; // XOR with polynomial
            } 
            else 
            {
                crc >>= 1; // Just shift right
            }
        }
    }
    return ~crc; // Return the calculated CRC value (bitwise NOT)
}

