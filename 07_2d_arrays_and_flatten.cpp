#include <cstddef>
#include <iomanip>
#include <iostream>
#include <vector>

void print_matrix_3x4(const int m[3][4]) {
  for (std::size_t r = 0; r < 3; ++r) {
    for (std::size_t c = 0; c < 4; ++c) {
      std::cout << std::setw(4) << m[r][c];
    }
    std::cout << '\n';
  }
}

std::size_t idx_row_major(std::size_t r, std::size_t c, std::size_t cols) {
  return r * cols + c;
}

int main() {
  int m[3][4]{};
  for (std::size_t r = 0; r < 3; ++r) {
    for (std::size_t c = 0; c < 4; ++c) {
      m[r][c] = static_cast<int>(r * 10 + c);
    }
  }

  std::cout << "Matrix int m[3][4] (row-major):\n";
  print_matrix_3x4(m);

  const std::size_t rows = 3;
  const std::size_t cols = 4;
  std::vector<int> flat(rows * cols);

  for (std::size_t r = 0; r < rows; ++r) {
    for (std::size_t c = 0; c < cols; ++c) {
      flat[idx_row_major(r, c, cols)] = static_cast<int>(r * 10 + c);
    }
  }

  std::cout << "\nFlattened version (std::vector<int>) using idx = r*cols + c:\n";
  for (std::size_t r = 0; r < rows; ++r) {
    for (std::size_t c = 0; c < cols; ++c) {
      std::cout << std::setw(4) << flat[idx_row_major(r, c, cols)];
    }
    std::cout << '\n';
  }

  return 0;
}

