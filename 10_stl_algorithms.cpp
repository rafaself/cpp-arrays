#include <algorithm>
#include <array>
#include <cstddef>
#include <iostream>
#include <iterator>

template <class It>
void print_range(It begin, It end, const char* name) {
  std::cout << name << " = [ ";
  for (auto it = begin; it != end; ++it) {
    std::cout << *it << ' ';
  }
  std::cout << "]\n";
}

int main() {
  int a[7]{5, 1, 7, 3, 3, 2, 9};
  print_range(std::begin(a), std::end(a), "a (original)");

  std::sort(std::begin(a), std::end(a));
  print_range(std::begin(a), std::end(a), "a (sort)");

  std::reverse(std::begin(a), std::end(a));
  print_range(std::begin(a), std::end(a), "a (reverse)");

  auto [mn, mx] = std::minmax_element(std::begin(a), std::end(a));
  std::cout << "min = " << *mn << ", max = " << *mx << "\n";

  // For binary_search, the range must be sorted.
  std::sort(std::begin(a), std::end(a));
  const int target = 7;
  bool found = std::binary_search(std::begin(a), std::end(a), target);
  std::cout << "binary_search(" << target << ") = " << (found ? "true" : "false") << "\n";

  // The same applies to std::array.
  std::array<int, 5> b{4, 2, 8, 1, 6};
  print_range(b.begin(), b.end(), "b (original)");
  std::sort(b.begin(), b.end());
  print_range(b.begin(), b.end(), "b (sort)");

  return 0;
}

