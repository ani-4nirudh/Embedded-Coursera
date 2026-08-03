/******************************************************************************
 * Copyright (C) 2026 by Anirudh Singh
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.c
 * @brief Basic data manipulation
 *
 * @author Anirudh Singh
 * @date August 2 2026
 *
 */

#include "data.h"
#include <stdbool.h>

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base) {
  bool is_negative = false;
  int32_t data_cpy = data;
  uint8_t count = 0;
  
  // Return null character for base less than 2 and greater than 16
  if ((base < 2) || (base > 16)) {
    *ptr = '\0';
    return 1;
  }

  // Make the copy a positive number
  if (data < 0) {
    data_cpy *= -1;
    is_negative = true;
  }

  if (data_cpy == 0) {
    *(ptr + count) = '0';
    count++;
  } else if (data_cpy != 0) {
    uint8_t rem;                          // Variable to save the digits
    while (data_cpy != 0) {               // Saving digits in a reverse order
      rem = data_cpy % base;
      if (rem < 10) {
        *(ptr + count) = (uint8_t) ('0' + rem);
      } else {
        *(ptr + count) = (uint8_t) ('A' + (rem - 10));
      }
      data_cpy /= base;
      count++;                           // Here count becomes length of the string
    }
  }

  // Adding a negative sign if the number is negative
  if (is_negative) {
    *(ptr + count) = '-';
    count++;
  }

  // Reversing the digits
  for (uint8_t i = 0; i < (count / 2); i++) {
    uint8_t temp = *(ptr + (count - 1 - i));
    *(ptr + (count - i - 1)) = *(ptr + i);
    *(ptr + i) = temp;
  }

  *(ptr + count) = '\0';                  // Add the null character at the end

  return (count + 1);                     // Return length of the string
}


