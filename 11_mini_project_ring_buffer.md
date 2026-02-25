# 11 — Mini-project: Ring Buffer (circular queue) with `std::array<T, N>`

## Goal

Build a fixed-size **ring buffer** (also called a **circular queue**) using `std::array<T, N>` and modular indexing.

Required operations:

- `push` (insert at the end)
- `pop` (remove from the front)
- `size`
- `empty`
- `full`

## Concepts

- Fixed-size structure with capacity `N`.
- Two indices:
  - `head`: where the next `pop()` reads from
  - `tail`: where the next `push()` writes to
- **Wrap-around**: when reaching the end, it goes back to `0` using `% N`.
- We also store `size_` to distinguish “full” from “empty”.

### Text diagram (example)

Assume `N=5` and the indices are:

```
pos:   0   1   2   3   4
data: [ ] [ ] [ ] [ ] [ ]
head=0, tail=0, size=0
```

After `push(1), push(2), push(3)`:

```
pos:   0   1   2   3   4
data: [1] [2] [3] [ ] [ ]
head=0, tail=3, size=3
```

If we do `pop()` twice, `head` moves forward:

```
pos:   0   1   2   3   4
data: [1] [2] [3] [ ] [ ]
head=2, tail=3, size=1
```

And when we do `push(4), push(5), push(6), ...`, `tail` can wrap around and reuse old positions.

## Code explained (step by step)

File: `11_mini_project_ring_buffer.cpp`

1. `RingBuffer<T, N>` stores:
   - `std::array<T, N> data_`
   - `head_`, `tail_`, and `size_`
2. `push`:
   - if `full()`, it fails
   - writes into `data_[tail_]`
   - `tail_ = (tail_ + 1) % N`
   - increments `size_`
3. `pop`:
   - if `empty()`, returns `std::nullopt`
   - reads/moves `data_[head_]`
   - `head_ = (head_ + 1) % N`
   - decrements `size_`
4. `size/empty/full` are O(1) queries.
5. In `main`, we:
   - fill until `full()`
   - remove a few items
   - push more to force wrap-around
   - empty everything

## Common mistakes

- Not updating `head`/`tail` with modulo (`% N`).
- Trying to detect full/empty using only `head==tail` (ambiguous without a counter or an extra slot).
- Forgetting to update `size_` in `push/pop`.

## Exercises

1. Add `peek()` that returns the next element without removing it.
2. Add `clear()` that resets the buffer.
3. Modify `push` to overwrite the oldest element when full (“overwrite” policy).
4. Make a version that stores `std::optional<T>` and avoids `std::move` from “old” slots.

## How to build and run

```bash
g++ -std=c++20 -O2 -Wall -Wextra -pedantic -g 11_mini_project_ring_buffer.cpp -o app
./app
```
