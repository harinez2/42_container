#include "vector.hpp"

// #include <vector>
#include <iostream>
// #include <cassert>

template <typename T>
void print_vec(const T& vec) {
  for (typename T::const_iterator it = vec.begin(); it != vec.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

void test_reference_sample() {
  std::cout << "<<<test_reference_sample>>>" << std::endl;

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
  std::cout << std::endl;
}

void test_reserve() {
  std::cout << "<<<test_reserve>>>" << std::endl;

  // std::vector<int> v;
  ft::vector<int> v;

  std::cout << "capacity(): " << v.capacity() << std::endl;
  v.push_back(1);
  std::cout << "capacity(): " << v.capacity() << std::endl;
  v.reserve(20);
  std::cout << "capacity(): " << v.capacity() << std::endl;
  std::cout << std::endl;
}

void test_erase() {
  std::cout << "<<<test_erase>>>" << std::endl;
  // std::vector<int> v;
  ft::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  v.push_back(6);
  print_vec(v);

  ft::vector<int>::iterator it = v.begin();
  std::cout << "deleting 0..." << *(v.erase(it)) << std::endl;
  print_vec(v);

  it = v.begin();
  ++it;
  ++it;
  std::cout << "deleting 2..." << *(v.erase(it)) << std::endl;
  print_vec(v);

  std::cout << std::endl;
}

void test_erase_range() {
  std::cout << "<<<test_erase_range>>>" << std::endl;
  // std::vector<int> v;
  ft::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  v.push_back(6);
  print_vec(v);

  ft::vector<int>::iterator it = v.begin();
  ft::vector<int>::iterator it_end = v.begin();
  ++it_end;
  std::cout << "deleting 0-1..." << *(v.erase(it, it_end)) << std::endl;
  print_vec(v);

  it = v.begin();
  ++it;
  ++it;
  it_end = it;
  ++it_end;
  ++it_end;
  std::cout << "deleting 2-4..." << *(v.erase(it, it_end)) << std::endl;
  print_vec(v);

  std::cout << std::endl;
}

int main() {
  // test_reference_sample();
  // test_reserve();
  // test_erase();
  test_erase_range();
  return 0;
}
