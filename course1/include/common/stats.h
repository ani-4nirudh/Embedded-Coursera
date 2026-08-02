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
 * @file stats.h 
 * @brief Header file with function descriptions
 * @author Anirudh Singh
 * @date 27 July 2026
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Print the statistics of a given array
 * @param array The array of unsigned characters
 * @param len The length of the given array
 * @return void
 */
void print_statistics(unsigned char *array, int len);

/**
 * @brief Print the given array
 * @param array The array of unsigned characters
 * @param len The length of the given array
 * @return void
 */
void print_array(unsigned char *array, int len);

/**
 * @brief Find the median of the array
 * @param array The array of unsigned characters
 * @param len The length of the given array
 * @return the median
 */
unsigned char find_median(unsigned char *array, int len);

/**
 * @brief Find the mean of the array
 * @param array The array of unsigned characters
 * @param len The length of the given array
 * @return the mean
 */
unsigned char find_mean(unsigned char *array, int len);

/**
 * @brief Find the max of the array
 * @param array The array of unsigned characters
 * @param len The length of the given array
 * @return the maximum
 */
unsigned char find_maximum(unsigned char *array, int len);

/**
 * @brief Find the min of the array
 * @param array The array of unsigned characters
 * @param len The length of the given array
 * @return the minimum
 */
unsigned char find_minimum(unsigned char *array, int len);

/**
 * @brief Sort the array using selection sort
 * @param array The array of unsigned characters
 * @param len The length of the given array
 * @return the sorted array in descending order
 */
void sort_array(unsigned char *array, int len);

#endif /* __STATS_H__ */
