#include <array>
#include <cstddef>
#include <iostream>
#include <span>
#include <vector>

void print_span(std::span<const int> s, const char* name) {
  std::cout << name << " (size=" << s.size() << ") = [ ";
  for (int v : s) {
    std::cout << v << ' ';
  }
  std::cout << "]\n";
}

void double_in_place(std::span<int> s) {
  for (int& v : s) {
    v *= 2;
  }
}

int main() {
  std::array<int, 8> a{0, 1, 2, 3, 4, 5, 6, 7};
  std::vector<int> v{10, 11, 12, 13, 14, 15};

  std::span<int> sa(a);
  std::span<int> sv(v);

  print_span(sa, "a (span)");
  print_span(sv, "v (span)");

  // Views: subspan() takes a "slice" without copying.
  auto middle = sa.subspan(2, 4);  // [2,3,4,5]
  print_span(middle, "a.subspan(2,4)");

  // We can modify through span<int> (non-const).
  double_in_place(middle);
  print_span(sa, "a after doubling subspan(2,4)");

  // We can also take prefix/suffix.
  print_span(sa.first(3), "a.first(3)");
  print_span(sa.last(2), "a.last(2)");

  return 0;
}
