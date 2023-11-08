# Generic Bubble Sort Library in C

Sort arrays of any type using a custom comparator function in C using the bubble sort algorithm.

No preprocessing using macros and no use of `_Generic`, just pure C.

## Usage

Sorting an array is done using the `sort` function:

```
void sort(void *arr, size_t n, size_t value_size, int (*cmp)(void*,void*));
```

* `void *arr`: pointer to the array to be sorted
* `size_t n`: size of `arr`
* `size_t value_size`: size of the elemens of `arr`
* `int (*cmp)(void*,void*)`: callback function used for comparison

A comparator function used in place of `cmp` has to apply the following rules:

* Accept two pointers to be compared with. These two values have to be cast to the appropriate type, e.g. to `int*` in `cmp_int`.
* Return an `int` indicating the ordering with the below scheme:
    - If `left > right` return a value greater than zero
    - If `left < right` return a value less than zero
    - If `left == right` return zero

### Implementation of `cmp_int`

```C
int cmp_int(void *v1, void *v2) {
    int *p = v1, *q = v2; // implicit cast to int*
    if (*p > *q) return 1;
    else if (*p < *q) return -1;
    else return 0;
}
```

Comparators are user-defined and can for example be used to do descending sorting, whatever the user intends to do.

The goal is for users of this library to sort any type by just having to implement a comparator which then can be provided to the `sort` function.

### Exmaple usage

Sorting an array of integers using the library provided `cmp_int` comparator:

```C
#include "generic_bubble_sort.h"

/* Sort an array of integers using cmp_int */

int arr[] = { 3, 2, 5, 1 }; 
size_t arr_len = sizeof(arr) / sizeof(arr[0]);

sort(arr, arr_len, sizeof(arr[0]), cmp_int);

/* Array after sort: { 1, 2, 3, 5} */
```
