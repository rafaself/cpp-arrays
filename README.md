# Mini-course: Arrays in C++ (from basics to advanced)

This mini-course covers “classic” C arrays (`T a[N]`) and modern STL alternatives (`std::array`, `std::vector`, `std::span`), focusing on safe usage, passing to functions, and algorithms.

## Prerequisites

- A compiler with **C++20** support (e.g., `g++` 10+ or `clang++` 12+).
- A terminal and basic build knowledge.

## How to build and run

One example (replace with the file you want):

```bash
g++ -std=c++20 -O2 -Wall -Wextra -pedantic -g array/01_basic_c_array.cpp -o app
./app
```

Build all examples (one executable per file):

```bash
for f in array/*.cpp; do
  g++ -std=c++20 -O2 -Wall -Wextra -pedantic -g "$f" -o "${f%.cpp}"
done
```

Run, for example:

```bash
./array/10_stl_algorithms
```

## Index (modules)

0. [Setup and recommended flags](./00_setup.md)
1. [Basic C array](./01_basic_c_array.md)
2. [Initialization and `sizeof`](./02_initialization_and_sizeof.md)
3. [Array-to-pointer decay (classic pitfall)](./03_array_to_pointer_decay.md)
4. [Pointers and iteration](./04_pointers_and_iteration.md)
5. [Passing arrays to functions (4 ways)](./05_passing_arrays_to_functions.md)
6. [`std::array`](./06_std_array.md)
7. [2D arrays and flatten (row-major)](./07_2d_arrays_and_flatten.md)
8. [Dynamic: `new[]/delete[]` (educational) and RAII](./08_dynamic_new_delete_and_raii.md)
9. [`std::span` and views](./09_span_views.md)
10. [STL algorithms on arrays](./10_stl_algorithms.md)
11. [Mini-project: ring buffer with `std::array`](./11_mini_project_ring_buffer.md)
12. [Pointer to array vs array of pointers](./12_pointer_to_array_vs_array_of_pointers.md)
# cpp-arrays
