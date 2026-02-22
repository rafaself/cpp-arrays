#include <array>
#include <cstddef>
#include <iostream>
#include <span>

int sum_ptr(const int *p, std::size_t n)
{
  int s = 0;
  for (std::size_t i = 0; i < n; ++i)
  {
    s += p[i];
  }
  return s;
}

template <std::size_t N>
int sum_ref_array(const int (&a)[N])
{
  int s = 0;
  for (std::size_t i = 0; i < N; ++i)
  {
    s += a[i];
  }
  return s;
}

template <std::size_t N>
int sum_std_array(const std::array<int, N> &a)
{
  int s = 0;
  for (std::size_t i = 0; i < a.size(); ++i)
  {
    s += a[i];
  }
  return s;
}

int sum_span(std::span<const int> s)
{
  int total = 0;
  for (int v : s)
  {
    total += v;
  }
  return total;
}

int main()
{
  int c_array[4]{1, 2, 3, 4};
  std::array<int, 4> stl_array{1, 2, 3, 4};

  std::cout << "1) pointer+size (C array): " << sum_ptr(c_array, 4) << "\n";
  std::cout << "2) array reference (C array): " << sum_ref_array(c_array) << "\n";
  std::cout << "3) std::array&: " << sum_std_array(stl_array) << "\n";
  std::cout << "4) std::span (C array): " << sum_span(c_array) << "\n";
  std::cout << "4) std::span (std::array): " << sum_span(stl_array) << "\n";

  // A nice span bonus: pass "subviews" without copying.
  std::span<const int> sub = std::span<const int>(c_array).subspan(1, 2); // [2,3]
  std::cout << "span subspan(1,2): " << sum_span(sub) << "\n";

  return 0;
}
