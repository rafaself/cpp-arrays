#include <cstddef>
#include <iostream>
#include <iterator>

int main()
{
  int zero[5]{}; // initializes all elements to 0

  std::cout << "zero = [ ";
  for (std::size_t i = 0; i < std::size(zero); ++i)
  {
    std::cout << zero[i] << ' ';
  }
  std::cout << "]\n";

  // int garbage[5]; // NOT initialized. Reading these values is UB (undefined behavior).
  // Instead of printing, we just show how to initialize safely:
  int ok[5]; // declared
  for (std::size_t i = 0; i < std::size(ok); ++i)
  {
    ok[i] = static_cast<int>(i + 1);
  }

  // sizeof on a "real" array gives the total number of bytes in the entire array.
  constexpr std::size_t bytes = sizeof(ok);
  constexpr std::size_t bytes_per_element = sizeof(ok[0]);
  constexpr std::size_t n = bytes / bytes_per_element;

  std::cout << "sizeof(ok) = " << bytes << " bytes\n";
  std::cout << "sizeof(ok[0]) = " << bytes_per_element << " bytes\n";
  std::cout << "n = sizeof(ok)/sizeof(ok[0]) = " << n << " elements\n";
  std::cout << "std::size(ok) = " << std::size(ok) << " elements\n";

  return 0;
}
