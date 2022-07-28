#include "type_traits.hpp"
#include "utility.hpp"
#include "vector.hpp"

// #include <vector>
#include <iostream>
// #include <cassert>

#include <boost/type_traits/is_integral.hpp> //TODO:remove
#include <boost/core/is_same.hpp> //TODO:remove
#include <cassert> //TODO:remove

enum my_enum{};

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
  ft::vector<int>::iterator it_end = v.end();
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

void test_isintegral() {
  // 1-4
  assert(boost::is_integral<int>::value == true);//, "value == true, int is integral");
  if (!(boost::core::is_same< boost::is_integral<int>::value_type, bool>::value == true))//, "value_type == bool");
    std::cout << "NG boost2" << std::endl;
  if (!(boost::core::is_same<boost::is_integral<int>::type, boost::true_type>::value == true))//, "type == true_type");
    std::cout << "NG boost3" << std::endl;
  assert(boost::is_integral<int>() == true);//, "is_integral<int>() == true");

  // 5-8
  assert(boost::is_integral<int*>::value == false);//, "value == false, int* is not integral");
  if (!(boost::core::is_same<boost::is_integral<int*>::value_type, bool>::value == true))//, "value_type == bool");
    std::cout << "NG boost6" << std::endl;
  if (!(boost::core::is_same<boost::is_integral<int*>::type, boost::false_type>::value == true))//, "type == false_type");
    std::cout << "NG boost7" << std::endl;
  assert(boost::is_integral<int*>() == false);//, "is_integral<int*>() == false");

  // 9-14
  assert(boost::is_integral<bool>::value == true);//, "bool is integral");
  assert(boost::is_integral<char>::value == true);//, "char is integral");
  assert(boost::is_integral<unsigned char>::value == true);
  assert(boost::is_integral<unsigned short>::value == true);
  assert(boost::is_integral<unsigned int>::value == true);
  assert(boost::is_integral<unsigned long>::value == true);

  // 15-19
  assert(boost::is_integral<my_enum>::value == false);//, "my_enum is not integral");
  assert(boost::is_integral<int&>::value == false);//, "int& is not integral");
  assert(boost::is_integral<int[1]>::value == false);//, "int[1] is not integral");
  assert(boost::is_integral<int ()>::value == false);//, "int () is not integral");
  assert(boost::is_integral<float>::value == false);//, "float is not integral");

  //---------------------------------------------

  // 1-4
  assert(ft::is_integral<int>::value == true);
  if (!(boost::core::is_same<ft::is_integral<int>::value_type, bool>::value))
    std::cout << "NG ft2" << std::endl;
  if (!(boost::core::is_same<ft::is_integral<int>::type, ft::true_type>::value == true))
    std::cout << "NG ft3" << std::endl;
  assert(ft::is_integral<int>() == true);

  // 5-8
  assert(ft::is_integral<int*>::value == false);
  if (!(boost::core::is_same<ft::is_integral<int*>::value_type, bool>::value == true))
    std::cout << "NG ft6" << std::endl;
  if (!(boost::core::is_same<ft::is_integral<int*>::type, ft::false_type>::value == true))
    std::cout << "NG ft7" << std::endl;
  assert(ft::is_integral<int*>() == false);
  
  // 9-14
  assert(ft::is_integral<bool>::value == true);
  assert(ft::is_integral<char>::value == true);
  assert(ft::is_integral<unsigned char>::value == true);
  assert(ft::is_integral<unsigned short>::value == true);
  assert(ft::is_integral<unsigned int>::value == true);
  assert(ft::is_integral<unsigned long>::value == true);

  // 15-19
  assert(ft::is_integral<my_enum>::value == false);
  assert(ft::is_integral<int&>::value == false);
  assert(ft::is_integral<int[1]>::value == false);
  assert(ft::is_integral<int ()>::value == false);
  assert(ft::is_integral<float>::value == false);
}

#include "rb_tree.hpp"
void test_rbtree() {
  ft::rb_tree<int> t;
}

int main() {
  // test_reference_sample();
  // test_reserve();
  // test_erase();
  // test_erase_range();

  // test_isintegral();

  test_rbtree();
  return 0;
}
