#include "../src/iterator.hpp"

#include <iterator>
#include <algorithm>

class IteratorTest : public ::testing::Test {
 public:
  IteratorTest() {
  }
  ~IteratorTest() {
  }
};

//------------------------------------------------------

// iterator tests

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

TEST_F(IteratorTest, iterator_basic_cases) {
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
// normal iterator tests



//------------------------------------------------------
// reverse iterator tests

TEST_F(IteratorTest, reverseit_basic_cases) {
  std::vector<int> v = {1, 2, 3, 4, 5};

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
