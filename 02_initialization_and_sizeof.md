# 02 — Initialization and `sizeof`

## Goal

Understand the difference between an initialized and an uninitialized array, and learn how to measure an array’s size with `sizeof` (while it’s still a “real” array).

## Concepts

- `int a[5]{};` → initializes all elements to zero.
- `int a[5];` → **does not** initialize. Reading `a[i]` before writing is **UB**.
- `sizeof(a)` (where `a` is a real array) returns **bytes of the entire array**.
- Size in elements: `sizeof(a) / sizeof(a[0])`.
- Modern alternative: `std::size(a)`.

## Code explained (step by step)

File: `02_initialization_and_sizeof.cpp`

1. Create `zero[5]{}` and print it to see that everything starts as `0`.
2. Avoid reading an uninitialized array (that would be UB).
3. Fill `ok[5]` with defined values.
4. Compute:
   - `bytes = sizeof(ok)` (total bytes)
   - `bytes_per_element = sizeof(ok[0])`
   - `n = bytes / bytes_per_element`
5. Compare with `std::size(ok)`.

## Common mistakes

- Printing an uninitialized array “just to see”: that’s UB and it may seem to work.
- Using `sizeof(a)` inside functions where the array has decayed to a pointer (see module 03).
- Hardcoding `5` in loops and then forgetting to update it.

## Exercises

1. Change the type to `double` and compare `sizeof`.
2. Make a `char` array and compute the size in elements with `sizeof`.
3. Replace the fill loop with list initialization: `{1,2,3,4,5}`.

## How to build and run

```bash
g++ -std=c++20 -O2 -Wall -Wextra -pedantic -g array/02_initialization_and_sizeof.cpp -o app
./app
```
