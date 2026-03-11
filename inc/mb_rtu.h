/****************************************************************
 * Modbus Library for C
 * Author: li
 * Description: This library provides a unified interface for Modbus communication in RTU, ASCII, and TCP modes.
 * License: MIT License
 * Copyright (c) 2026 Your Name
 *  
 *****************************************************************/
#ifndef __MB_RTU_H
#define __MB_RTU_H

#include "mb_port.h"

typedef enum   //设备地址
{
    MB_DEVICE_ADDR_ALL = 0x00, //广播地址
    MB_DEVICE_ADDR_1 = 0x01, //设备地址1
    MB_DEVICE_ADDR_2 = 0x02, //设备地址2
    MB_DEVICE_ADDR_3 = 0x03, //设备地址3
    MB_DEVICE_ADDR_4 = 0x04, //设备地址4
    MB_DEVICE_ADDR_5 = 0x05, //设备地址5
    MB_DEVICE_ADDR_6 = 0x06, //设备地址6
    MB_DEVICE_ADDR_7 = 0x07, //设备地址7
    MB_DEVICE_ADDR_8 = 0x08, //设备地址8
    MB_DEVICE_ADDR_9 = 0x09, //设备地址9
    MB_DEVICE_ADDR_10 = 0x0A //设备地址10
} mb_device_addr_t;

typedef enum   //功能码 
{
    MB_FUNC_READ_COILS                  = 0x01, //读线圈
    MB_FUNC_READ_DISCRETE_INPUTS        = 0x02, //读离散输入
    MB_FUNC_READ_HOLDING_REGISTERS      = 0x03, //读保持寄存器
    MB_FUNC_READ_INPUT_REGISTERS        = 0x04, //读输入寄存器
    MB_FUNC_WRITE_SINGLE_COIL           = 0x05, //写单个线圈
    MB_FUNC_WRITE_SINGLE_REGISTER       = 0x06, //写单个寄存器
    MB_FUNC_WRITE_MULTIPLE_COILS        = 0x0F, //写多个线圈
    MB_FUNC_WRITE_MULTIPLE_REGISTERS    = 0x10  //写多个寄存器

} mb_function_code_t;

typedef enum   //异常功能码 
{
    MB_EXCEPT_ILLEGAL_FUNCTION      = 0x01, //非法功能
    MB_EXCEPT_ILLEGAL_DATA_ADDRESS  = 0x02, //非法数据地址
    MB_EXCEPT_ILLEGAL_DATA_VALUE    = 0x03, //非法数据值
    MB_EXCEPT_SLAVE_DEVICE_FAILURE  = 0x04  //从设备故障
} mb_exception_code_t;

typedef struct 
{
    mb_device_addr_t device_addr;       //设备地址
    mb_function_code_t function_code;   //功能码
    uint8_t *data;                      //数据指针
    uint16_t data_length;               //数据长度
    uint16_t crc;                       //CRC校验码
} mb_rtu_frame_t;

extern mb_rtu_frame_t mb_rtu_frame; // Modbus RTU帧结构体实例

void mb_rtu_init(void);  // Function prototype for initializing Modbus RTU mode
void mb_rtu_send(uint8_t device_addr, uint8_t function_code, uint8_t *data, uint16_t data_length) ;         // Function prototype for sending data in Modbus RTU mode
void mb_rtu_receive(uint8_t *buffer, uint16_t buffer_length);   // Function prototype for receiving data in Modbus RTU mode

#endif // __MB_RTU_H
