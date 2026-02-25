# 09 — `std::span` and views (`subspan`, `first`, `last`) — C++20

## Goal

Learn `std::span` as a “window” (view) over contiguous memory, and use `subspan()` to work with parts of an array **without copying**.

## Concepts

- `std::span<T>` does not own the memory: it just points to a contiguous sequence.
- It can be built from:
  - C-array
  - `std::array`
  - `std::vector` (as long as the vector doesn’t reallocate and stays alive)
- Views:
  - `subspan(offset, count)`
  - `first(count)`
  - `last(count)`
- `std::span<const T>` represents a read-only view.

## Code explained (step by step)

File: `09_span_views.cpp`

1. Create a `std::array` and a `std::vector`.
2. Build spans (`sa` and `sv`) pointing to the data.
3. Print using a function that takes `std::span<const int>`.
4. Create a view `middle = sa.subspan(2,4)` and print it.
5. Pass `middle` to `double_in_place(std::span<int>)` to modify only that slice.
6. Use `first()` and `last()` as shortcuts.

## Common mistakes

- Using a `span` after the original memory is gone (dangling).
- Creating a `span` from a `std::vector` and then growing the vector (it may reallocate and invalidate the span).
- Confusing `span` with a container: `span` has no `.push_back()` and does not manage capacity.

## Exercises

1. Write `sum(std::span<const int>)`.
2. Write a function that normalizes a slice of a vector using `subspan()`.
3. Create a `span` for a flattened matrix and implement `row(r)` that returns `subspan(r*cols, cols)`.

## How to build and run

This module uses **C++20**.

```bash
g++ -std=c++20 -O2 -Wall -Wextra -pedantic -g 09_span_views.cpp -o app
./app
```
