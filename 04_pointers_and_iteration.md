# 04 — Pointers, arithmetic, and iteration (`std::begin/std::end`)

## Goal

Relate `a[i]` to `*(a+i)`, and learn ways to iterate using pointers and `std::begin/std::end`.

## Concepts

- For C arrays, `a` often behaves like a “pointer to the first element”.
- `a[i]` is equivalent to `*(a + i)`.
- `std::begin(a)` and `std::end(a)` return pointers (iterators) to the beginning and one-past-the-end.
- Range-based `for` works directly on C arrays.

## Code explained (step by step)

File: `04_pointers_and_iteration.cpp`

1. Create `int a[5]{...}`.
2. Show that `a[2]` and `*(a + 2)` produce the same value.
3. Iterate with:
   - indices (`p[i]`)
   - pointers (`for (it = begin; it != end; ++it)`)
4. Use range-based `for` as a simple and safe iteration style.

## Common mistakes

- Confusing `end` with the “last element”: `end` points **after** the last one.
- Doing pointer arithmetic outside the array (e.g., `a + 100`) and then dereferencing.
- Forgetting that `*(a+i)` requires `i` to be within bounds.

## Exercises

1. Print addresses (`static_cast<const void*>(a + i)`) to see contiguity in memory.
2. Reverse the iteration using pointers (from end to start) carefully.
3. Write a function that sums a range `[begin, end)`.

## How to build and run

```bash
g++ -std=c++20 -O2 -Wall -Wextra -pedantic -g 04_pointers_and_iteration.cpp -o app
./app
```
