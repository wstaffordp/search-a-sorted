#ifndef SEARCH_A_SORTED_H
#define SEARCH_A_SORTED_H

#include <stddef.h>

unsigned char search_a_sorted_ascending(size_t low, size_t high, int *haystack,
                                        int needle, size_t *position);

unsigned char search_a_sorted_descending(size_t low, size_t high, int *haystack,
                                         int needle, size_t *position);

#endif
