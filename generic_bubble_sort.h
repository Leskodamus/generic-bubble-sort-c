#ifndef GENERIC_BUBBLE_SORT_LIB
#define GENERIC_BUBBLE_SORT_LIB

#include "stddef.h"

/**
 * 
 * GENERIC BUBBLE SORT LIBRARY
 *
 */

/* Swap the values of two given pointers */
void swap(void* restrict v1, void* restrict v2, size_t p_size);

/* Bubble sort an array */
void sort(void *arr, size_t n, size_t value_size, 
          int (*cmp)(void*,void*));

/* Comparator for int */
int cmp_int(void *v1, void *v2);

#endif // GENERIC_BUBBLE_SORT_LIB

