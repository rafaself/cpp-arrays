# 08 — Dynamic arrays: `new[]/delete[]` (educational) and modern alternatives (RAII)

## Goal

Understand how to allocate an array dynamically (for educational purposes only) and learn modern alternatives that avoid leaks and bugs: `std::vector` and `std::unique_ptr<T[]>`.

## Concepts

- `new[]` allocates an array on the heap; `delete[]` must deallocate it **with brackets**.
- Mistakes with `new[]/delete[]` are common:
  - forgetting `delete[]` (leak)
  - using `delete` instead of `delete[]` (UB)
  - early return/exception before `delete[]` (leak)
- **RAII**: resources are released automatically when leaving scope.
  - `std::vector<T>`: the best general option for a dynamic array.
  - `std::unique_ptr<T[]>`: useful when you truly want a “heap array” with no resizing.

## Code explained (step by step)

File: `08_dynamic_new_delete_and_raii.cpp`

1. `raw = new int[n]`: allocates `n` integers.
2. Fill and print; then call `delete[] raw`.
3. Create `std::vector<int> v(n)` and use `v.data()` to get a contiguous pointer.
4. Create `auto up = std::make_unique<int[]>(n)`:
   - `up[i]` works like an array
   - automatic release at end of scope

## Common mistakes

- Mixing `delete` with memory from `new[]`.
- Returning before freeing in raw-pointer code.
- Thinking `unique_ptr<int[]>` has `.size()` (it doesn’t; you still need to store the size).

## Exercises

1. Write an example that returns a filled `std::vector<int>` (factory function).
2. Write a function that takes `std::unique_ptr<int[]>` by reference and fills the array.
3. Compare the ergonomics of storing the size together (`vector`) vs separately (`unique_ptr<int[]>`).

## How to build and run

```bash
g++ -std=c++20 -O2 -Wall -Wextra -pedantic -g array/08_dynamic_new_delete_and_raii.cpp -o app
./app
```
