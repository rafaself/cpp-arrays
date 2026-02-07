#include <algorithm>
#include <array>
#include <cstddef>
#include <iostream>
#include <iterator>

template <class It>
void imprime(It begin, It end, const char* nome) {
  std::cout << nome << " = [ ";
  for (auto it = begin; it != end; ++it) {
    std::cout << *it << ' ';
  }
  std::cout << "]\n";
}

int main() {
  int a[7]{5, 1, 7, 3, 3, 2, 9};
  imprime(std::begin(a), std::end(a), "a (original)");

  std::sort(std::begin(a), std::end(a));
  imprime(std::begin(a), std::end(a), "a (sort)");

  std::reverse(std::begin(a), std::end(a));
  imprime(std::begin(a), std::end(a), "a (reverse)");

  auto [mn, mx] = std::minmax_element(std::begin(a), std::end(a));
  std::cout << "min = " << *mn << ", max = " << *mx << "\n";

  // Para binary_search, o range precisa estar ordenado.
  std::sort(std::begin(a), std::end(a));
  const int alvo = 7;
  bool achou = std::binary_search(std::begin(a), std::end(a), alvo);
  std::cout << "binary_search(" << alvo << ") = " << (achou ? "true" : "false") << "\n";

  // O mesmo vale para std::array.
  std::array<int, 5> b{4, 2, 8, 1, 6};
  imprime(b.begin(), b.end(), "b (original)");
  std::sort(b.begin(), b.end());
  imprime(b.begin(), b.end(), "b (sort)");

  return 0;
}

