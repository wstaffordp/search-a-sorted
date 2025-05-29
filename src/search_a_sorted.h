#ifndef SEARCH_A_SORTED_H
#define SEARCH_A_SORTED_H

#include <stdint.h>

unsigned char search_a_sorted_ascending(uintptr_t low, uintptr_t high,
                                        int *haystack, int needle,
                                        uintptr_t *position);

unsigned char search_a_sorted_descending(uintptr_t low, uintptr_t high,
                                         int *haystack, int needle,
                                         uintptr_t *position);

#endif
