# 03 — Array-to-pointer decay (classic pitfall)

## Goal

See “decay” in practice: when you pass a C array to a function, it **becomes a pointer**, and `sizeof` stops behaving the way you expect.

## Concepts

- **Array-to-pointer decay**: in many contexts, `int a[6]` becomes `int*`.
- A function parameter `int a[]` is equivalent to `int* a`.
- `sizeof(a)` inside the function measures the **pointer** size, not the original array size.
- Classic fix: pass **pointer + size**.

## Code explained (step by step)

File: `03_array_to_pointer_decay.cpp`

1. In `main`, `a` is a real array:
   - `sizeof(a)` measures the entire array.
   - `std::size(a)` returns the number of elements.
2. Call `try_guess_size_bad(a)`:
   - Inside the function, `a` is treated as a pointer.
   - `sizeof(a)` is now the pointer size (for example 8 bytes on 64-bit).
3. Call `print_with_size(a, std::size(a))`, which works because the size is passed along.

## Common mistakes

- Trusting `sizeof(parameter)` to figure out how many elements there are.
- Writing `void f(int a[10])` thinking it forces size 10 (it doesn’t; it still becomes a pointer).
- Forgetting to pass the size and “guessing” in the loop.

## Exercises

1. Change the type to `double` and notice that `sizeof(a)` in `main` changes, but inside the function it remains the pointer size.
2. Do `print_with_size(a + 2, 3)` and print only part of the array.
3. Try compiling with extra warnings and see whether the compiler warns about `sizeof` on the parameter.

## How to build and run

```bash
g++ -std=c++20 -O2 -Wall -Wextra -pedantic -g array/03_array_to_pointer_decay.cpp -o app
./app
```
