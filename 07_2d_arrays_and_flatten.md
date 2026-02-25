# 07 — 2D arrays and flatten (row-major)

## Goal

Understand how a 2D array (`int m[3][4]`) is laid out in memory and how to represent the same matrix in a flattened (1D) form using `r*cols + c` indexing.

## Concepts

- `int m[3][4]` is an array of 3 rows, each with 4 columns.
- In C/C++, the default order is **row-major**: elements in the same row are contiguous.
- A flattened (1D) representation stores everything in a linear vector:
  - `idx = r * cols + c`
- `std::vector<int>` is useful when `rows` and `cols` are not compile-time constants.

## Code explained (step by step)

File: `07_2d_arrays_and_flatten.cpp`

1. Create `int m[3][4]{}` and fill it with `m[r][c] = r*10 + c`.
2. Print the matrix with alignment using `std::setw`.
3. Create `flat` with `rows*cols` elements.
4. Implement `idx_row_major(r,c,cols)` returning `r*cols + c`.
5. Fill and print the flattened version.

## Common mistakes

- Swapping `rows` and `cols` in the formula (leads to wrong access).
- Confusing row-major with column-major (in C++ the default convention is row-major).
- Passing a 2D array to functions with wrong dimensions (the compiler needs the second dimension size).

## Exercises

1. Write a `set(flat, rows, cols, r, c, value)` function using `idx_row_major`.
2. Implement `transpose` on the flattened version.
3. Compare the cost of accessing by row vs by column (conceptually: cache locality).

## How to build and run

```bash
g++ -std=c++20 -O2 -Wall -Wextra -pedantic -g 07_2d_arrays_and_flatten.cpp -o app
./app
```
