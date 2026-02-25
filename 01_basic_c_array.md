# 01 — Basic C array (`T a[N]`)

## Goal

Learn how to declare a C array, fill it, print it, and sum its elements, reinforcing the idea of **bounds**.

## Concepts

- C array: `int a[5];` is a contiguous block of 5 `int`s.
- Valid indices: `0` to `N-1`.
- `std::size(a)`: gets the number of elements of a “real” array (C++17+).
- Out-of-bounds access (e.g., `a[10]`) causes **UB** (undefined behavior).

## Code explained (step by step)

File: `01_basic_c_array.cpp`

1. Declare `int a[5];`.
2. Fill it with a `for` loop, using `std::size(a)` to avoid hardcoding the size.
3. Print each element with `std::cout`.
4. Compute the sum with another `for` loop.

## Common mistakes

- Using `i <= N` instead of `i < N` (a classic off-by-one).
- Thinking `a[5]` is the “5th element” (the last one is `a[4]`).
- Mixing `int` with `std::size_t` and getting signed/unsigned comparison warnings.

## Exercises

1. Change the fill to `a[i] = i*i` and see the new sum.
2. Compute the average of the elements (use `double`).
3. Find the largest and smallest element (without using algorithms yet).

## How to build and run

```bash
g++ -std=c++20 -O2 -Wall -Wextra -pedantic -g 01_basic_c_array.cpp -o app
./app
```
