#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>

void print(const int* p, std::size_t n, const char* name) {
  std::cout << name << " = [ ";
  for (std::size_t i = 0; i < n; ++i) {
    std::cout << p[i] << ' ';
  }
  std::cout << "]\n";
}

int main() {
  constexpr std::size_t n = 5;

  // 1) new[]/delete[] (educational): works, but it's easy to mess up and it's not idiomatic modern C++.
  int* raw = new int[n];
  for (std::size_t i = 0; i < n; ++i) {
    raw[i] = static_cast<int>((i + 1) * 3);
  }
  print(raw, n, "raw(new[])");
  delete[] raw;  // forget -> leak; mess up -> UB

  // 2) std::vector (recommended in most cases)
  std::vector<int> v(n);
  for (std::size_t i = 0; i < v.size(); ++i) {
    v[i] = static_cast<int>(100 + i);
  }
  print(v.data(), v.size(), "vector");

  // 3) std::unique_ptr<T[]> (RAII with a dynamic array)
  auto up = std::make_unique<int[]>(n);
  for (std::size_t i = 0; i < n; ++i) {
    up[i] = static_cast<int>(200 + i);
  }
  print(up.get(), n, "unique_ptr<int[]>");
  // delete[] is automatic when 'up' goes out of scope.

  return 0;
}
