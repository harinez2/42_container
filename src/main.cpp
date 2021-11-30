#include "vector.hpp"

#include <vector>
#include <iostream>
#include <cassert>

void test_reference_sample() {
  // std::vector<int> v;
  ft::vector<int> v;
  v.push_back(1);
  v.push_back(99);
  v.push_back(4);

  v[1] = 3;
  v.push_back(5);
  // v.insert(v.begin() + 1, 2);

  // int* p = v.data();
  std::size_t size = v.size();
  std::cout << "size:" << size << std::endl;
  std::cout << "v[0]:" << v[0] << std::endl;
  std::cout << "v[1]:" << v[1] << std::endl;
  std::cout << "v[2]:" << v[2] << std::endl;
  std::cout << "v[3]:" << v[3] << std::endl;
  // assert(p[0] == 1);
  // assert(size == 5u);

  for (ft::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    std::cout << *it << std::endl;
}

int main() {
  test_reference_sample();
  // ft::vector<int> a;
  return 0;
}
