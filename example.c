#include <stdio.h>
#include "generic_bubble_sort.h"

/*
 * Example usage of the generic bubble sort library
 * with an array of integers
 */

int main(void) {
    int arr[] = { 3, 2, 1, 5, 6, 4, 10, 9 };
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);
    
    sort(arr, arr_len, sizeof(arr[0]), cmp_int);
    
    for (size_t i = 0; i < arr_len; ++i)
        printf("%d ", arr[i]);
    puts("");

    return 0;
}
