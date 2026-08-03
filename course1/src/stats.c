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
 * @file stats.c 
 * @brief Analysis of the char dataset
 * @author Anirudh Singh
 * @date 27 July 2026
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

// int main(void) {
//
//   unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
//                               114, 88,   45,  76, 123,  87,  25,  23,
//                               200, 122, 150, 90,   92,  87, 177, 244,
//                               201,   6,  12,  60,   8,   2,   5,  67,
//                                 7,  87, 250, 230,  99,   3, 100,  90};
//
//   /* Other Variable Declarations Go Here */
//   /* Statistics and Printing Functions Go Here */
//   sort_array(test, SIZE);
//   print_array(test, SIZE);
//   print_statistics(test, SIZE);
//
//   return 0;
// }

/* Add other Implementation File Code Here */
void print_statistics(unsigned char *array, int len) {
  unsigned char max_num = find_maximum(array, len);
  unsigned char min_num = find_minimum(array, len);
  unsigned char median = find_median(array, len);
  unsigned char mean = find_mean(array, len);
  printf("Max: %u\n", max_num);
  printf("Min: %u\n", min_num);
  printf("Median: %u\n", median);
  printf("Mean: %u\n", mean);
}

void print_array(unsigned char *array, int len) {
  #ifdef VERBOSE
    PRINTF("{ ");
    for (int i = 0; i < len - 1; i++) {
      PRINTF("%u, ", array[i]);
    }
    PRINTF("%u }\n", array[len - 1]);
  #endif
}

unsigned char find_median(unsigned char *array, int len) {
  unsigned char median;
  if ((len % 2) == 0) {
    median = (array[(len / 2) - 1] + array[(len / 2)]) / 2;
    return median;
  }
  median = array[len / 2];
  return median;
}

unsigned char find_mean(unsigned char *array, int len) {
  int sum = 0;
  for (int i = 0; i < len; i++) {
    sum += (int) array[i];
  }
  return (unsigned char)((sum + (len / 2)) / len);
}

unsigned char find_maximum(unsigned char *array, int len) {
  return array[0];
}

unsigned char find_minimum(unsigned char *array, int len) {
  return array[len - 1];
}

void sort_array(unsigned char *array, int len) {
  for (int i = 0; i <= (len - 2); i++) {
    int max_idx = i;
    for (int j = i + 1; j <= (len - 1); j++) {
      if (array[j] > array[max_idx]) {
        max_idx = j; 
      }
    }
    unsigned char temp = array[max_idx];
    array[max_idx] = array[i];
    array[i] = temp;
  }
}
