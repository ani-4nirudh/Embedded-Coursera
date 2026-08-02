/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Move the data to the destination
 *
 * @param src Source variable to be copied from
 * @param dst Destinaton variable to be copied to
 * @param length Number of bytes to move
 *
 * @return Pointer to the destination
 */
uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length);

/**
 * @brief Copy the data to the destinaton
 *
 * @param src Source variable to be copied from
 * @param dst Destinaton variable to be copied to
 * @param length Number of bytes to move
 *
 * @return Pointer to the destination
 */
uint8_t *my_memcopy(uint8_t *src, uint8_t *dst, size_t length);

/**
 * @brief Set the memory of the given location to a given value
 *
 * @param src Source variable
 * @param length Number of bytes to move
 * @param value Value to set the bytes to
 *
 * @return Pointer to the source
 */
uint8_t *my_memset(uint8_t *src, size_t length, uint8_t value);

/**
 * @brief Zero the memory of the given location
 *
 * @param src Source variable to be copied from
 * @param length Number of bytes to move
 *
 * @return Pointer to the source
 */
uint8_t *my_memzero(uint8_t *src, size_t length);

/**
 * @brief Reverse the order of all the bytes
 *
 * @param src Pointer to the memory location
 * @param length Length in bytes
 *
 * @return Pointer to the source
 */
uint8_t *my_reverse(uint8_t *src, size_t length);

/**
 * @brief Number of words to dynamically allocate in heap
 *
 * @param length Length in bytes to allocate
 *
 * @return NULL pointer or pointer to memory if successful
 */
int32_t *reserve_words(size_t length);

/**
 * @brief Free the dynamically allocated memory
 *
 * @param Pointer to the heap allocation
 *
 * @return void
 */
void *free_words(int32_t *src);

#endif /* __MEMORY_H__ */
