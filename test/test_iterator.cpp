#include "../src/iterator.hpp"

#include <iterator>
#include <bits/stl_iterator_base_types.h>
#include <bits/stl_iterator.h>
#include <algorithm>

class NormalIteratorTest : public ::testing::Test {
 public:
  NormalIteratorTest() {
  }
  ~NormalIteratorTest() {
  }
 protected:
  std::vector<int> v = {1, 2, 3, 4, 5};
};

//------------------------------------------------------

TEST_F(NormalIteratorTest, increment_decrement) {
  __gnu_cxx::__normal_iterator<std::vector<int>::iterator, std::vector<int>> gnu_it;
  __gnu_cxx::__normal_iterator<std::vector<int>::iterator, std::vector<int>> gnu_it_vec(v.begin());
  EXPECT_EQ(*gnu_it_vec, 1);
  EXPECT_EQ(*gnu_it_vec++, 1);
  EXPECT_EQ(*gnu_it_vec, 2);
  EXPECT_EQ(*++gnu_it_vec, 3);
  EXPECT_EQ(*gnu_it_vec, 3);
  EXPECT_EQ(*gnu_it_vec--, 3);
  EXPECT_EQ(*gnu_it_vec, 2);
  EXPECT_EQ(*--gnu_it_vec, 1);
  EXPECT_EQ(*gnu_it_vec, 1);
  
  ft::normal_iterator<std::vector<int>::iterator, std::vector<int>> ft_it;
  ft::normal_iterator<std::vector<int>::iterator, std::vector<int>> ft_it_vec(v.begin());
  EXPECT_EQ(*ft_it_vec, 1);
  EXPECT_EQ(*ft_it_vec++, 1);
  EXPECT_EQ(*ft_it_vec, 2);
  EXPECT_EQ(*++ft_it_vec, 3);
  EXPECT_EQ(*ft_it_vec, 3);
  EXPECT_EQ(*ft_it_vec--, 3);
  EXPECT_EQ(*ft_it_vec, 2);
  EXPECT_EQ(*--ft_it_vec, 1);
  EXPECT_EQ(*ft_it_vec, 1);
}

TEST_F(NormalIteratorTest, copy_constructor) {
  __gnu_cxx::__normal_iterator<std::vector<int>::iterator, std::vector<int>> gnu_it_vec2(v.begin());
  __gnu_cxx::__normal_iterator<std::vector<int>::iterator, std::vector<int>> gnu_it_vec(gnu_it_vec2);
  EXPECT_EQ(*gnu_it_vec, 1);
  EXPECT_EQ(*gnu_it_vec++, 1);
  EXPECT_EQ(*gnu_it_vec, 2);
  EXPECT_EQ(*++gnu_it_vec, 3);
  EXPECT_EQ(*gnu_it_vec, 3);
  EXPECT_EQ(*gnu_it_vec--, 3);
  EXPECT_EQ(*gnu_it_vec, 2);
  EXPECT_EQ(*--gnu_it_vec, 1);
  EXPECT_EQ(*gnu_it_vec, 1);
  
  ft::normal_iterator<std::vector<int>::iterator, std::vector<int>> ft_it_vec2(v.begin());
  ft::normal_iterator<std::vector<int>::iterator, std::vector<int>> ft_it_vec(ft_it_vec2);
  EXPECT_EQ(*ft_it_vec, 1);
  EXPECT_EQ(*ft_it_vec++, 1);
  EXPECT_EQ(*ft_it_vec, 2);
  EXPECT_EQ(*++ft_it_vec, 3);
  EXPECT_EQ(*ft_it_vec, 3);
  EXPECT_EQ(*ft_it_vec--, 3);
  EXPECT_EQ(*ft_it_vec, 2);
  EXPECT_EQ(*--ft_it_vec, 1);
  EXPECT_EQ(*ft_it_vec, 1);
}

TEST_F(NormalIteratorTest, plus_minus) {
  
  // __gnu_cxx::__normal_iterator<std::vector<int>::iterator, std::vector<int>> it_tmp;
  // std::cout << *(it += 2) << std::endl;
  // it_tmp = it + 1;
  // std::cout << *it_tmp << std::endl;
  // std::cout << *(it -= 2) << std::endl;
  // it_tmp = it - 1;
  // std::cout << *it_tmp << std::endl;
  // std::cout << it.base() << std::endl;
}

TEST_F(NormalIteratorTest, basic_cases) {
  

  // ft::normal_iterator<int> it;
  // ft::normal_iterator<int, vector> it;
  // ft::normal_iterator it_vec(v.begin());//?
  // ft::normal_iterator it2(it);
  
  // std::cout << *it << std:endl;
  // std::cout << it->current_ << std:endl;
  // std::cout << *it++ << std:endl;
  // std::cout << *++it << std:endl;
  // std::cout << *it-- << std:endl;
  // std::cout << *--it << std:endl;
  // std::cout << *it[2] << std:endl;
  
  // std::cout << *(it += 2) << std:endl;
  // it_tmp = it + 1;
  // std::cout << *it_tmp << std:endl;
  // std::cout << *(it -= 2) << std:endl;
  // it_tmp = it - 1;
  // std::cout << *it_tmp << std:endl;
  // std::cout << it.base() << std:endl;
}

class increment_iterator{//} : public ft::iterator<std::input_iterator_tag, int> {
  int x_;

public:
  increment_iterator(int x = 0) : x_(x) {}

  increment_iterator& operator++() {
    ++x_;
    return *this;
  }

  increment_iterator operator++(int) {
    int tmp = x_;
    ++x_;
    return increment_iterator(tmp);
  }

  int operator*() const { return x_; }
};

inline bool operator==(const increment_iterator& a, const increment_iterator& b)
  { return *a == *b; }

inline bool operator!=(const increment_iterator& a, const increment_iterator& b)
  { return !(a == b); }

inline bool operator<(const increment_iterator& a, const increment_iterator& b)
  { return *a < *b; }

inline bool operator<=(const increment_iterator& a, const increment_iterator& b)
  { return !(b < a); }

inline bool operator>(const increment_iterator& a, const increment_iterator& b)
  { return b < a; }

inline bool operator>=(const increment_iterator& a, const increment_iterator& b)
  { return !(a < b); }

TEST_F(NormalIteratorTest, basic_cases2) {
  increment_iterator first(0);
  increment_iterator last(10);

  // int i = 0;
  // while (first != last) {
  //   EXPECT_EQ(*first, i);
  //   ++first;
  //   ++i;
  // }
  std::for_each(first, last, [](int x) {
    std::cout << x << std::endl;
  });
}

//------------------------------------------------------
//------------------------------------------------------

class ReverseIteratorTest : public ::testing::Test {
 public:
  ReverseIteratorTest() {
  }
  ~ReverseIteratorTest() {
  }
 protected:
  std::vector<int> v = {1, 2, 3, 4, 5};
};

//------------------------------------------------------

TEST_F(ReverseIteratorTest, basic_cases) {
  std::reverse_iterator<decltype(v)::iterator> std_first(v.end());
  std::reverse_iterator<decltype(v)::iterator> std_last(v.begin());
  // std::for_each(std_first, std_last, [](int std_x) {
  while (std_first != std_last) {
    std::cout << *std_first << std::endl;
    ++std_first;
  }
  
  ft::reverse_iterator<decltype(v)::iterator> ft_first(v.end());
  ft::reverse_iterator<decltype(v)::iterator> ft_last(v.begin());
  // std::for_each(ft_first, ft_last, [](int ft_x) {
  //   std::cout << ft_x << std::endl;
  // });
  // while (ft_first != ft_last) {
  //   std::cout << *ft_first << std::endl;
  //   ++ft_first;
  // }

}
