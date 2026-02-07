# 05 — Passing arrays to functions (4 ways)

## Goal

Learn four common and safe ways to pass “sequences” to functions:

1. Pointer + size
2. Array reference (size deduced)
3. `std::array&`
4. `std::span` (C++20)

## Concepts

- **Pointer+size**: works with any contiguous block, but it’s easy to pass the wrong size.
- **Array reference**: `int (&a)[N]` preserves `N` in the type; great for C arrays.
- **`std::array`**: wrapper with `.size()`, STL integration, and no surprising decay.
- **`std::span` (C++20)**: a non-owning view of a contiguous sequence (array, `std::array`, `std::vector`, etc.).

## Code explained (step by step)

File: `05_passing_arrays_to_functions.cpp`

- `sum_ptr(const int*, size_t)`: the classic C-style approach.
- `sum_ref_array(const int (&)[N])`: deduces `N` automatically.
- `sum_std_array(const std::array<int, N>&)`: takes the container.
- `sum_span(std::span<const int>)`: takes a view; enables `subspan()` without copying.

In `main`, we call each function with a C array and/or `std::array` to compare ergonomics.

## Common mistakes

- Passing the wrong size in “pointer+size” (silent bug).
- Trying to pass `std::vector` to `int (&a)[N]` (won’t compile; only C arrays).
- Thinking `std::span` “owns” the memory (it doesn’t; it just points).

## Exercises

1. Implement `print(std::span<const int>)` that prints any contiguous sequence.
2. Make an `average(...)` function in the four styles and compare signatures.
3. Use `subspan()` to sum a window of the array.

## How to build and run

This module uses **C++20** because of `std::span`.

```bash
g++ -std=c++20 -O2 -Wall -Wextra -pedantic -g array/05_passing_arrays_to_functions.cpp -o app
./app
```
