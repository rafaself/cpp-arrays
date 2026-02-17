#include <cstddef>
#include <iostream>
#include <iterator>

void try_guess_size_bad(const int a[])
{
  // WARNING: here the parameter is NOT an array. It "decays" to int*.
  std::cout << "[bad] sizeof(a) inside the function = " << sizeof(a)
            << " bytes (pointer size)\n";
}

void print_with_size(const int *p, std::size_t n)
{
  std::cout << "[ok] n = " << n << ", values = [ ";
  for (std::size_t i = 0; i < n; ++i)
  {
    std::cout << p[i] << ' ';
  }
  std::cout << "]\n";
}

int main()
{
  int a[6]{1, 2, 3, 4, 5, 6};

  std::cout << "sizeof(a) in main = " << sizeof(a) << " bytes (entire array)\n";
  std::cout << "std::size(a) in main = " << std::size(a) << " elements\n";

  try_guess_size_bad(a);

  print_with_size(a, std::size(a));
  return 0;
}
