#include <cstddef>
#include <iostream>
#include <iterator>

int main() {
  int a[5];  // C array (fixed size, known at compile time)

  for (std::size_t i = 0; i < std::size(a); ++i) {
    a[i] = static_cast<int>((i + 1) * 10);  // 10, 20, 30, 40, 50
  }

  std::cout << "Array a = [ ";
  for (std::size_t i = 0; i < std::size(a); ++i) {
    std::cout << a[i] << ' ';
  }
  std::cout << "]\n";

  int sum = 0;
  for (std::size_t i = 0; i < std::size(a); ++i) {
    sum += a[i];
  }
  std::cout << "Sum = " << sum << "\n";

  // Important: always respect bounds. a[5] would be out-of-bounds (UB).
  return 0;
}
