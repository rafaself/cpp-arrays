# 10 — STL algorithms on arrays

## Goal

Apply common STL algorithms to contiguous sequences (C arrays and `std::array`):

- `sort`
- `reverse`
- `minmax_element`
- `binary_search`

## Concepts

- STL algorithms work with **iterators**, so you must provide a range `[begin, end)`.
- For C arrays:
  - `std::begin(a)` and `std::end(a)` return pointers.
- For `std::array`:
  - `b.begin()` and `b.end()` return iterators.
- Some algorithms have preconditions:
  - `std::binary_search` requires the range to be **sorted**.

## Code explained (step by step)

File: `10_stl_algorithms.cpp`

1. Create a C array `a` and print it.
2. Sort with `std::sort`.
3. Reverse with `std::reverse`.
4. Get min/max with `std::minmax_element`.
5. Sort again and run `std::binary_search`.
6. Repeat with `std::array<int,5> b`.

## Common mistakes

- Calling `binary_search` without sorting first (incorrect results).
- Passing the wrong `end` (for example `begin + N-1` instead of `begin + N`).
- Thinking `sort` works on any container: it requires random-access iterators (so it works on arrays/vectors).

## Exercises

1. Use `std::count` to count how many times a value appears.
2. Use `std::unique` (after sorting) to remove duplicates (conceptually: compact).
3. Find the first element greater than `x` with `std::upper_bound` (sorted range).

## How to build and run

```bash
g++ -std=c++20 -O2 -Wall -Wextra -pedantic -g array/10_stl_algorithms.cpp -o app
./app
```
