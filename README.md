# Search A Sorted

It's a fast, non-interpolated sorted-list searching algorithm.

`search_a_sorted_ascending()` and `search_a_sorted_descending()` are the searching functions that search for an element in a list of elements that are already sorted in either ascending or descending order.

They accept the following 5 arguments in left-to-right order.

1. `low` is the lowest index bound to search in `haystack`.
2. `high` is the highest index bound to search in `haystack` and must be greater than or equal to `low`.
3. `haystack` is the array of elements to search.
4. `needle` is the element to search for in `haystack`.
5. `position` is the pointer containing the index of the searched element.

When the return value is `1`, `position` contains the index of the found `needle`.

When the return value is `0`, a new index value isn't assigned to `position`.

It's in the same class as Binary Search, Exponential Search, Fibonnaci Search and `bsearch()`.

Search A Sorted is close to a lossless optimization with faster speed than Binary Search, Exponential Search and Fibonacci Search in all distributed instances that were tested.

It doesn't rely on evenly-distributed `haystack` values for heuristic, input-based calculations and it's substantially-faster than the worst instances of Interpolation Search.

It's the fastest sorted-list searching algorithm compared to sorted-list searching algorithms that don't require input-based calculations across a wide range of data types and data, both randomized and uniform.

I welcome submissions of algorithms in the same class that challenge the aforementioned claim.

`bsearch()` doesn't guarantee the use of Binary Search and has neither space nor time complexity guarantees.

Search A Sorted is an optimal alternative to every instance that implements `bsearch()` or Binary Search to perform a needle-in-a-haystack search operation on a sorted list of elements.

The following security explanation uses the context of ascending sort order.

`if (haystack[low] < needle)` ensures `needle` is larger than the `low` bound in `haystack` before proceeding.

If not, it falls through to verify the `low` bound in `haystack` before exiting.

Otherwise, `if (haystack[high] < needle)` ensures `needle` is contained within `haystack`, then verifies the `high` bound in `haystack`.

In addition to the aforementioned conditional statements creating the fastest instance whenever `needle` isn't found, they set up a safe range to iterate through without requiring additional comparisons for memory safety.

Then, `high--` decreases the previously-verified `high` bound to prevent overflows in the core searching loop while maintaining the searchability of each element in `haystack`.

Instead of initializing with a median pivot value before determining a search direction, the `high` bound is halved, meaning the first Binary Search operation always uses subtraction repeatedly before proceeding in the opposite direction.

The aforementioned alternating control flow prevents excessive array accesses and equality operations after each modification of the `high` bound to increase speed without either exceeding bounds or skipping elements.

The aforementioned process repeats until either `gap` is `2` or the `high` bound is greater than or equal to `needle`.

Then, to avoid infinite loops, it processes a final one-way Binary Search operation as if `gap` is `1`.

The final conditional statement `if (haystack[high] == needle)` verifies if the resulting `high` bound in `haystack` contains `needle`.
