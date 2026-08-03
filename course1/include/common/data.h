/******************************************************************************
 * Copyright (C) 2017 by Anirudh Singh
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.h 
 * @brief Header file for data.c
 *
 * @author Anirudh Singh
 * @date August 2, 2026
 *
 */


#ifndef __DATA_H__
#define __DATA_H__

#define BASE_10 10
#define BASE_16 16

#include "platform.h"

/**
 * @brief Integer to ASCII string conversion
 *
 * @param data Value to convert to string
 * @param ptr Data converted to string pointer
 * @param base Bases to support 2 to 16
 *
 * @return length of the converted data
 * */
uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base);


/**
 * @brief ASCII to integer string conversion
 *
 * @param digits Integer value to convert to
 * @param ptr Pointer variable to the string
 * @param base Bases to support 2 to 16
 *
 * @return Converted signed integer
 * */
int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base);

#endif /* ifndef __DATA_H__
#define __DATA_H__ */
