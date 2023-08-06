#include "generic_bubble_sort.h"

void swap(void* restrict v1, void* restrict v2, size_t p_size) {
    unsigned char *p = v1, *q = v2, tmp;
    for (size_t i = 0; i < p_size; ++i) {
        tmp = p[i];
        p[i] = q[i];
        q[i] = tmp;
    }
}

void sort(void *arr, size_t n, size_t value_size, 
          int (*cmp)(void*,void*)) 
{
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            unsigned char *l = ((unsigned char*)arr) + j * value_size;
            unsigned char *r = ((unsigned char*)arr) + (j+1) * value_size;
            if (cmp(l, r) > 0)
                swap(l, r, value_size);
        }
    }
}

int cmp_int(void *v1, void *v2) {
    int *p = v1, *q = v2; 
    if (*p > *q) return 1;
    else if (*p < *q) return -1;
    else return 0;
}

