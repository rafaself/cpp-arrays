#include <cstddef>
#include <iostream>
#include <iterator>

int main()
{
  int a[5];

  for (std::size_t i = 0; i < std::size(a); ++i)
  {
    a[i] = static_cast<int>((i + 1) * 10);
  }

  std::cout << "Array a = [ ";
  for (std::size_t i = 0; i < std::size(a); ++i)
  {
    std::cout << a[i] << ' ';
  }
  std::cout << "]\n";

  int sum = 0;
  for (std::size_t i = 0; i < std::size(a); ++i)
  {
    sum += a[i];
  }
  std::cout << "Sum = " << sum << "\n";

  return 0;
}
