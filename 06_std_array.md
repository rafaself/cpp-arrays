# 06 — `std::array<T, N>`

## Goal

Learn the basics of `std::array`: fixed size, STL integration, and useful APIs like `.size()`, `.at()`, and `.data()`.

## Concepts

- `std::array<T, N>` is a fixed-size container (like a C array), but with a container interface.
- `.size()` returns `N`.
- `.at(i)` checks bounds and throws `std::out_of_range` if `i` is invalid.
- `.data()` returns `T*` to the first element (useful to interoperate with C-style APIs).
- `.fill(x)` fills all elements with `x`.

## Code explained (step by step)

File: `06_std_array.cpp`

1. Create `std::array<int,5> a{...}`.
2. Show `.size()` and access via `operator[]`.
3. Demonstrate `.at()` inside `try/catch` (bounds checking).
4. Use `.data()` to show the memory is contiguous.
5. Call `a.fill(7)` and print with range-based `for`.

## Common mistakes

- Using `operator[]` expecting bounds checking (there isn’t; it’s like a C array).
- Storing a pointer from `.data()` and later using it incorrectly (with `std::array` it won’t be invalidated by reallocation, but still watch lifetime/scope).
- Thinking `std::array` is “dynamic” (it isn’t; the size is part of the type).

## Exercises

1. Write a function that takes `std::array<int, N>` and returns the largest element.
2. Compare `a[999]` (UB) with `a.at(999)` (exception).
3. Convert a C array to `std::array` manually and compare usage.

## How to build and run

```bash
g++ -std=c++20 -O2 -Wall -Wextra -pedantic -g 06_std_array.cpp -o app
./app
```
