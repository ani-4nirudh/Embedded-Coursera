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

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
*/

/*
 * @brief Print the statistics of a given array
 * @param array
 * @return void
 * */
void print_statistics(char *array);

/*
 * @brief Print the given array
 * @param array
 * @return void
 * */
void print_array(char *array, int len);

/*
 * @brief Find the median of the array
 * @param array
 * @param length of array
 * @return the median
 * */
char find_median(char *array, int len);

/*
 * @brief Find the mean of the array
 * @param array
 * @param length of array
 * @return the median
 * */
char find_mean(char *array, int len);

/*
 * @brief Find the max of the array
 * @param array
 * @param length of array
 * @return the median
 * */
char find_maximum(char *array, int len);

/*
 * @brief Find the min of the array
 * @param array
 * @param length of array
 * @return the median
 * */
char find_minimum(char *array, int len);

/*
 * @brief Sort the array
 * @param array
 * @param length of array
 * @return the median
 * */
char sort_array(char *array, int len);

#endif /* __STATS_H__ */
