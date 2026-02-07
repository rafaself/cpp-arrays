#include <array>
#include <cstddef>
#include <iostream>
#include <optional>

template <class T, std::size_t N>
class RingBuffer {
  static_assert(N > 0, "N must be > 0");

 public:
  bool push(const T& value) {
    if (full()) return false;
    data_[tail_] = value;
    tail_ = (tail_ + 1) % N;
    ++size_;
    return true;
  }

  bool push(T&& value) {
    if (full()) return false;
    data_[tail_] = std::move(value);
    tail_ = (tail_ + 1) % N;
    ++size_;
    return true;
  }

  std::optional<T> pop() {
    if (empty()) return std::nullopt;
    T value = std::move(data_[head_]);
    head_ = (head_ + 1) % N;
    --size_;
    return value;
  }

  [[nodiscard]] std::size_t size() const { return size_; }
  [[nodiscard]] bool empty() const { return size_ == 0; }
  [[nodiscard]] bool full() const { return size_ == N; }

 private:
  std::array<T, N> data_{};
  std::size_t head_ = 0;  // position of the next pop
  std::size_t tail_ = 0;  // position of the next push
  std::size_t size_ = 0;  // number of valid elements
};

int main() {
  RingBuffer<int, 5> rb;

  std::cout << "push 1..5:\n";
  for (int i = 1; i <= 5; ++i) {
    std::cout << "  push(" << i << ") -> " << (rb.push(i) ? "ok" : "full") << "\n";
  }
  std::cout << "size=" << rb.size() << ", full=" << (rb.full() ? "true" : "false") << "\n";

  std::cout << "\npop 3 times:\n";
  for (int i = 0; i < 3; ++i) {
    auto v = rb.pop();
    if (v) {
      std::cout << "  pop() -> " << *v << "\n";
    } else {
      std::cout << "  pop() -> empty\n";
    }
  }
  std::cout << "size=" << rb.size() << "\n";

  std::cout << "\npush 6,7,8 (tests wrap-around):\n";
  for (int i = 6; i <= 8; ++i) {
    std::cout << "  push(" << i << ") -> " << (rb.push(i) ? "ok" : "full") << "\n";
  }
  std::cout << "size=" << rb.size() << "\n";

  std::cout << "\npop until empty:\n";
  while (!rb.empty()) {
    std::cout << "  " << *rb.pop() << "\n";
  }
  std::cout << "empty=" << (rb.empty() ? "true" : "false") << "\n";

  return 0;
}
