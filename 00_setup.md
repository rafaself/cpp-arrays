# 00 — Setup: how to compile (and why)

## Goal

Standardize how to build and run the examples, with flags that help catch bugs early.

## Concepts

- `-std=c++20`: enables C++20 features (needed for `std::span`).
- `-Wall -Wextra -pedantic`: turns on useful warnings (gold for learning).
- `-O2`: reasonable optimization (keeps programs fast without extra complexity).
- `-g`: includes debug symbols (helps debugging and improves diagnostics).
- Sanitizers (optional): detect **UB** (undefined behavior) and invalid accesses.

## Code explained (step by step)

This file has no code; it only defines commands and recommendations.

## Common mistakes

- Compiling without `-std=c++20` and then “not finding” `std::span`.
- Ignoring warnings: many array bugs show up as warnings first.
- Thinking “it ran once, so it’s correct”: arrays can have silent UB.

## Exercises

1. Build an example with and without `-Wall -Wextra` and compare the warnings.
2. Force an out-of-bounds access (for example `a[10]`) and run with sanitizers.

## How to build and run

Base command (use on any `.cpp` file in this course):

```bash
g++ -std=c++20 -O2 -Wall -Wextra -pedantic -g file.cpp -o app
./app
```

Optional (recommended when studying arrays): sanitizers.

```bash
g++ -std=c++20 -O1 -g -Wall -Wextra -pedantic -fsanitize=address,undefined file.cpp -o app
./app
```

Notes:
- `address` often detects invalid memory accesses (e.g., out-of-bounds).
- `undefined` often detects UB patterns (e.g., signed overflow in some cases).
- In general, use `-O1` with sanitizers for a good performance/diagnostics balance.
