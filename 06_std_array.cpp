#include <array>
#include <cstddef>
#include <iostream>
#include <stdexcept>

int main() {
  std::array<int, 5> a{10, 20, 30, 40, 50};

  std::cout << "a.size() = " << a.size() << "\n";
  std::cout << "a[0] = " << a[0] << "\n";

  // .at() checks bounds and throws an exception if the index is out of range.
  try {
    std::cout << "a.at(2) = " << a.at(2) << "\n";
    // std::cout << a.at(99) << "\n"; // uncomment to see out_of_range
  } catch (const std::out_of_range& e) {
    std::cout << "out_of_range: " << e.what() << "\n";
  }

  std::cout << "a.data() points to the first element: " << a.data() << "\n";

  a.fill(7);
  std::cout << "after fill(7): [ ";
  for (int v : a) {
    std::cout << v << ' ';
  }
  std::cout << "]\n";

  return 0;
}
