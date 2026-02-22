#include <cstddef>
#include <iostream>
#include <iterator>

void print_with_indices(const int *p, std::size_t n)
{
  std::cout << "indices: [ ";
  for (std::size_t i = 0; i < n; ++i)
  {
    std::cout << p[i] << ' ';
  }
  std::cout << "]\n";
}

void print_with_pointers(const int *begin, const int *end)
{
  std::cout << "pointers: [ ";
  for (auto it = begin; it != end; ++it)
  {
    std::cout << *it << ' ';
  }
  std::cout << "]\n";
}

int main()
{
  int a[5]{10, 20, 30, 40, 50};

  std::cout << "a[2] = " << a[2] << "\n";
  std::cout << "*(a + 2) = " << *(a + 2) << "\n"; // pointer arithmetic

  print_with_indices(a, std::size(a));

  const int *b = std::begin(a);
  const int *e = std::end(a);
  print_with_pointers(b, e);

  std::cout << "range-for: [ ";
  for (int v : a)
  { // works on C arrays
    std::cout << v << ' ';
  }
  std::cout << "]\n";

  return 0;
}
