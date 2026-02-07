#include <cstddef>
#include <iostream>

template <std::size_t N>
void multiply_all(int (*arr)[N], int factor) {
  for (std::size_t i = 0; i < N; ++i) {
    (*arr)[i] *= factor;
  }
}

int main() {
  int nums[4]{10, 20, 30, 40};

  int* elem_ptr = nums;          // pointer to first element
  int (*array_ptr)[4] = &nums;   // pointer to the entire array

  std::cout << "nums          = " << static_cast<const void*>(nums) << "\n";
  std::cout << "elem_ptr      = " << static_cast<const void*>(elem_ptr) << "\n";
  std::cout << "&nums         = " << static_cast<const void*>(&nums) << "\n";
  std::cout << "elem_ptr + 1  = " << static_cast<const void*>(elem_ptr + 1) << "\n";
  std::cout << "array_ptr + 1 = " << static_cast<const void*>(array_ptr + 1) << "\n\n";

  std::cout << "sizeof(nums)      = " << sizeof(nums) << " bytes\n";
  std::cout << "sizeof(elem_ptr)  = " << sizeof(elem_ptr) << " bytes\n";
  std::cout << "sizeof(array_ptr) = " << sizeof(array_ptr) << " bytes\n\n";

  multiply_all(array_ptr, 2);
  std::cout << "after multiply_all(array_ptr, 2): [ ";
  for (int value : nums) {
    std::cout << value << ' ';
  }
  std::cout << "]\n\n";

  int a = 7, b = 8, c = 9;
  int* ptr_array[3]{&a, &b, &c};  // array of pointers
  std::cout << "array of pointers values: [ ";
  for (int* p : ptr_array) {
    std::cout << *p << ' ';
  }
  std::cout << "]\n";

  return 0;
}
