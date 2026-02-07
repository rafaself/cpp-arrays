# 12 — Pointer to array vs array of pointers

## Goal

Understand the difference between:

- `int*` (pointer to element)
- `int (*)[N]` (pointer to entire array)
- `int* a[N]` (array of pointers)

These three forms are often mixed up, but they have different types and memory behavior.

## Concepts

- `int* p = nums;` points to `nums[0]`.
- `int (*pa)[4] = &nums;` points to the whole `nums` array.
- `p + 1` moves by `sizeof(int)`.
- `pa + 1` moves by `sizeof(nums)` (the whole array block).
- `int* ptr_array[3]` is an array where each slot stores an address.

## Code explained (step by step)

File: `12_pointer_to_array_vs_array_of_pointers.cpp`

1. `nums` is declared as `int[4]`.
2. `elem_ptr` and `array_ptr` are created with different pointer types.
3. The program prints addresses:
   - `nums` and `elem_ptr` represent the first element address.
   - `&nums` is the address of the array object.
4. The program prints `elem_ptr + 1` and `array_ptr + 1`:
   - the first advances by one element,
   - the second advances by one entire array.
5. `multiply_all(array_ptr, 2)` shows how a function can explicitly receive a pointer to an array of fixed size.
6. Finally, `ptr_array` demonstrates an array whose elements are pointers.

## Common mistakes

- Writing `int* p[4]` when you actually wanted `int (*p)[4]`.
- Assuming `&nums` has type `int*` (it does not).
- Forgetting that pointer arithmetic depends on the pointer type.

## Exercises

1. Change `nums` to size 6 and update the type of `array_ptr`.
2. Add another function that receives `int*` + size and compare it with the pointer-to-array version.
3. Replace `int* ptr_array[3]` with `const char* words[3]` and print each string.

## How to build and run

```bash
g++ -std=c++20 -O2 -Wall -Wextra -pedantic -g array/12_pointer_to_array_vs_array_of_pointers.cpp -o app
./app
```
