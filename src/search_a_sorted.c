#include "search_a_sorted.h"

unsigned char search_a_sorted_ascending(uintptr_t low, uintptr_t high,
                                        int *haystack, int needle,
                                        uintptr_t *position) {
  uintptr_t gap;

  if (haystack[low] < needle) {
    if (haystack[high] < needle) {
      return 0;
    }

    if (haystack[high] == needle) {
      *position = high;
      return 1;
    }

    high--;
    gap = high - low;

    if (gap > 2) {
      while (haystack[high] > needle) {
        while (haystack[high] > needle) {
          high -= gap >> 1;
          gap = (gap >> 1) + 1;
        }

        while (haystack[high] < needle) {
          high += gap >> 1;
          gap = (gap >> 1) + 1;
        }

        if (gap < 3) {
          break;
        }
      }
    }

    while (haystack[high] > needle) {
      high--;
    }

    if (haystack[high] == needle) {
      *position = high;
      return 1;
    }

    return 0;
  }

  if (haystack[low] == needle) {
    *position = low;
    return 1;
  }

  return 0;
}

unsigned char search_a_sorted_descending(uintptr_t low, uintptr_t high,
                                         int *haystack, int needle,
                                         uintptr_t *position) {
  uintptr_t gap;

  if (haystack[low] > needle) {
    if (haystack[high] > needle) {
      return 0;
    }

    if (haystack[high] == needle) {
      *position = high;
      return 1;
    }

    high--;
    gap = high - low;

    if (gap > 2) {
      while (haystack[high] < needle) {
        while (haystack[high] < needle) {
          high -= gap >> 1;
          gap = (gap >> 1) + 1;
        }

        while (haystack[high] > needle) {
          high += gap >> 1;
          gap = (gap >> 1) + 1;
        }

        if (gap < 3) {
          break;
        }
      }
    }

    while (haystack[high] < needle) {
      high--;
    }

    if (haystack[high] == needle) {
      *position = high;
      return 1;
    }

    return 0;
  }

  if (haystack[low] == needle) {
    *position = low;
    return 1;
  }

  return 0;
}
