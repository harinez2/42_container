#include "../src/iterator.hpp"

#include <iterator>
#include <bits/stl_iterator_base_types.h>
#include <bits/stl_iterator.h>
#include <algorithm>

class NormalIteratorTest : public ::testing::Test {
 public:
  NormalIteratorTest() {
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
  }
  ~NormalIteratorTest() {
  }

 protected:
  std::vector<int> v;
};

//------------------------------------------------------

TEST_F(NormalIteratorTest, increment_decrement) {
  __gnu_cxx::__normal_iterator<std::vector<int>::iterator, std::vector<int>> gnu_it;
  __gnu_cxx::__normal_iterator<std::vector<int>::iterator, std::vector<int>> gnu_it_vec(v.begin());
  EXPECT_EQ(*gnu_it_vec, 10);
  EXPECT_EQ(*gnu_it_vec++, 10);
  EXPECT_EQ(*gnu_it_vec, 20);
  EXPECT_EQ(*++gnu_it_vec, 30);
  EXPECT_EQ(*gnu_it_vec, 30);
  EXPECT_EQ(*gnu_it_vec--, 30);
  EXPECT_EQ(*gnu_it_vec, 20);
  EXPECT_EQ(*--gnu_it_vec, 10);
  EXPECT_EQ(*gnu_it_vec, 10);
  
  ft::normal_iterator<std::vector<int>::iterator, std::vector<int>> ft_it;
  ft::normal_iterator<std::vector<int>::iterator, std::vector<int>> ft_it_vec(v.begin());
  EXPECT_EQ(*ft_it_vec, 10);
  EXPECT_EQ(*ft_it_vec++, 10);
  EXPECT_EQ(*ft_it_vec, 20);
  EXPECT_EQ(*++ft_it_vec, 30);
  EXPECT_EQ(*ft_it_vec, 30);
  EXPECT_EQ(*ft_it_vec--, 30);
  EXPECT_EQ(*ft_it_vec, 20);
  EXPECT_EQ(*--ft_it_vec, 10);
  EXPECT_EQ(*ft_it_vec, 10);
}

TEST_F(NormalIteratorTest, copy_constructor) {
  __gnu_cxx::__normal_iterator<std::vector<int>::iterator, std::vector<int>> gnu_it_vec2(v.begin());
  __gnu_cxx::__normal_iterator<std::vector<int>::iterator, std::vector<int>> gnu_it_vec(gnu_it_vec2);
  EXPECT_EQ(*gnu_it_vec, 10);
  gnu_it_vec++;
  EXPECT_EQ(*gnu_it_vec, 20);
  
  ft::normal_iterator<std::vector<int>::iterator, std::vector<int>> ft_it_vec2(v.begin());
  ft::normal_iterator<std::vector<int>::iterator, std::vector<int>> ft_it_vec(ft_it_vec2);
  EXPECT_EQ(*ft_it_vec, 10);
  ft_it_vec++;
  EXPECT_EQ(*ft_it_vec, 20);
}

TEST_F(NormalIteratorTest, const_constructor) {
  const std::vector<int>::iterator it_const = v.begin();
  __gnu_cxx::__normal_iterator<std::vector<int>::iterator, std::vector<int>> gnu_it_vec(it_const);
  EXPECT_EQ(*gnu_it_vec, 10);
  gnu_it_vec++;
  EXPECT_EQ(*gnu_it_vec, 20);
  
  ft::normal_iterator<std::vector<int>::iterator, std::vector<int>> ft_it_vec(it_const);
  EXPECT_EQ(*ft_it_vec, 10);
  ft_it_vec++;
  EXPECT_EQ(*ft_it_vec, 20);
}

TEST_F(NormalIteratorTest, plus_minus) {
  __gnu_cxx::__normal_iterator<std::vector<int>::iterator, std::vector<int>> gnu_it_vec(v.begin());
  EXPECT_EQ(*(gnu_it_vec + 2), 30);
  EXPECT_EQ(*gnu_it_vec, 10);
  EXPECT_EQ(*(gnu_it_vec += 2), 30);
  EXPECT_EQ(*gnu_it_vec, 30);
  EXPECT_EQ(*(gnu_it_vec - 2), 10);
  EXPECT_EQ(*gnu_it_vec, 30);
  EXPECT_EQ(*(gnu_it_vec -= 2), 10);
  EXPECT_EQ(*gnu_it_vec, 10);
  
  ft::normal_iterator<std::vector<int>::iterator, std::vector<int>> ft_it_vec(v.begin());
  EXPECT_EQ(*(ft_it_vec + 2), 30);
  EXPECT_EQ(*ft_it_vec, 10);
  EXPECT_EQ(*(ft_it_vec += 2), 30);
  EXPECT_EQ(*ft_it_vec, 30);
  EXPECT_EQ(*(ft_it_vec - 2), 10);
  EXPECT_EQ(*ft_it_vec, 30);
  EXPECT_EQ(*(ft_it_vec -= 2), 10);
  EXPECT_EQ(*ft_it_vec, 10);
}

TEST_F(NormalIteratorTest, reference_operators) {
  __gnu_cxx::__normal_iterator<std::vector<int>::iterator, std::vector<int>> gnu_it_vec(v.begin());
  EXPECT_EQ(*(gnu_it_vec.base()), 10);
  EXPECT_EQ(*((&gnu_it_vec)->base()), 10);
  EXPECT_EQ(gnu_it_vec[0], 10);
  EXPECT_EQ(gnu_it_vec[2], 30);
  
  ft::normal_iterator<std::vector<int>::iterator, std::vector<int>> ft_it_vec(v.begin());
  EXPECT_EQ(*(ft_it_vec.base()), 10);
  EXPECT_EQ(*((&ft_it_vec)->base()), 10);
  EXPECT_EQ(ft_it_vec[0], 10);
  EXPECT_EQ(ft_it_vec[2], 30);
}

TEST_F(NormalIteratorTest, comparison_operators) {
  __gnu_cxx::__normal_iterator<std::vector<int>::iterator, std::vector<int>> gnu_it_vec(v.begin());
  __gnu_cxx::__normal_iterator<std::vector<int>::iterator, std::vector<int>> gnu_it_same(v.begin());
  __gnu_cxx::__normal_iterator<std::vector<int>::iterator, std::vector<int>> gnu_it_right(v.begin());
  gnu_it_right++;
  gnu_it_right++;
  EXPECT_TRUE(gnu_it_vec == gnu_it_same);
  EXPECT_FALSE(gnu_it_vec == gnu_it_right);
  EXPECT_FALSE(gnu_it_vec != gnu_it_same);
  EXPECT_TRUE(gnu_it_vec != gnu_it_right);
  EXPECT_FALSE(gnu_it_vec < gnu_it_same);
  EXPECT_TRUE(gnu_it_vec < gnu_it_right);
  EXPECT_FALSE(gnu_it_vec > gnu_it_same);
  EXPECT_FALSE(gnu_it_vec > gnu_it_right);
  EXPECT_TRUE(gnu_it_vec <= gnu_it_same);
  EXPECT_TRUE(gnu_it_vec <= gnu_it_right);
  EXPECT_TRUE(gnu_it_vec >= gnu_it_same);
  EXPECT_FALSE(gnu_it_vec >= gnu_it_right);
  EXPECT_EQ(*(gnu_it_right + 2), 50);
  EXPECT_EQ(gnu_it_right - gnu_it_vec, 2);
  
  ft::normal_iterator<std::vector<int>::iterator, std::vector<int>> ft_it_vec(v.begin());
  ft::normal_iterator<std::vector<int>::iterator, std::vector<int>> ft_it_same(v.begin());
  ft::normal_iterator<std::vector<int>::iterator, std::vector<int>> ft_it_right(v.begin());
  ft_it_right++;
  ft_it_right++;
  EXPECT_TRUE(ft_it_vec == ft_it_same);
  EXPECT_FALSE(ft_it_vec == ft_it_right);
  EXPECT_FALSE(ft_it_vec != ft_it_same);
  EXPECT_TRUE(ft_it_vec != ft_it_right);
  EXPECT_FALSE(ft_it_vec < ft_it_same);
  EXPECT_TRUE(ft_it_vec < ft_it_right);
  EXPECT_FALSE(ft_it_vec > ft_it_same);
  EXPECT_FALSE(ft_it_vec > ft_it_right);
  EXPECT_TRUE(ft_it_vec <= ft_it_same);
  EXPECT_TRUE(ft_it_vec <= ft_it_right);
  EXPECT_TRUE(ft_it_vec >= ft_it_same);
  EXPECT_FALSE(ft_it_vec >= ft_it_right);
  EXPECT_EQ(*(ft_it_right + 2), 50);
  EXPECT_EQ(ft_it_right - ft_it_vec, 2);
}

//------------------------------------------------------
//------------------------------------------------------

class ReverseIteratorTest : public ::testing::Test {
 public:
  ReverseIteratorTest() {
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
  }
  ~ReverseIteratorTest() {
  }
 protected:
  std::vector<int> v;
};

//------------------------------------------------------

TEST_F(ReverseIteratorTest, increment_decrement) {
  std::reverse_iterator<std::vector<int>::iterator> gnu_it;
  std::reverse_iterator<std::vector<int>::iterator> gnu_it_vec(v.end());
  EXPECT_EQ(*gnu_it_vec, 50);
  EXPECT_EQ(*gnu_it_vec++, 50);
  EXPECT_EQ(*gnu_it_vec, 40);
  EXPECT_EQ(*++gnu_it_vec, 30);
  EXPECT_EQ(*gnu_it_vec, 30);
  EXPECT_EQ(*gnu_it_vec--, 30);
  EXPECT_EQ(*gnu_it_vec, 40);
  EXPECT_EQ(*--gnu_it_vec, 50);
  EXPECT_EQ(*gnu_it_vec, 50);
  
  ft::reverse_iterator<std::vector<int>::iterator> ft_it;
  ft::reverse_iterator<std::vector<int>::iterator> ft_it_vec(v.end());
  EXPECT_EQ(*ft_it_vec, 50);
  EXPECT_EQ(*ft_it_vec++, 50);
  EXPECT_EQ(*ft_it_vec, 40);
  EXPECT_EQ(*++ft_it_vec, 30);
  EXPECT_EQ(*ft_it_vec, 30);
  EXPECT_EQ(*ft_it_vec--, 30);
  EXPECT_EQ(*ft_it_vec, 40);
  EXPECT_EQ(*--ft_it_vec, 50);
  EXPECT_EQ(*ft_it_vec, 50);
}

TEST_F(ReverseIteratorTest, copy_constructor) {
  std::reverse_iterator<std::vector<int>::iterator> gnu_it_vec2(v.end());
  std::reverse_iterator<std::vector<int>::iterator> gnu_it_vec(gnu_it_vec2);
  EXPECT_EQ(*gnu_it_vec, 50);
  gnu_it_vec++;
  EXPECT_EQ(*gnu_it_vec, 40);
  
  ft::reverse_iterator<std::vector<int>::iterator> ft_it_vec2(v.end());
  ft::reverse_iterator<std::vector<int>::iterator> ft_it_vec(ft_it_vec2);
  EXPECT_EQ(*ft_it_vec, 50);
  ft_it_vec++;
  EXPECT_EQ(*ft_it_vec, 40);
}

TEST_F(ReverseIteratorTest, const_constructor) {
  const std::vector<int>::iterator it_const = v.end();
  std::reverse_iterator<std::vector<int>::iterator> gnu_it_vec(it_const);
  EXPECT_EQ(*gnu_it_vec, 50);
  gnu_it_vec++;
  EXPECT_EQ(*gnu_it_vec, 40);
  
  ft::reverse_iterator<std::vector<int>::iterator> ft_it_vec(it_const);
  EXPECT_EQ(*ft_it_vec, 50);
  ft_it_vec++;
  EXPECT_EQ(*ft_it_vec, 40);
}

TEST_F(ReverseIteratorTest, assignment_operator) {
  std::reverse_iterator<std::vector<int>::iterator> gnu_it_vec2(v.end());
  std::reverse_iterator<std::vector<int>::iterator> gnu_it_vec = gnu_it_vec2;
  EXPECT_EQ(*gnu_it_vec, 50);
  gnu_it_vec++;
  EXPECT_EQ(*gnu_it_vec, 40);
  
  ft::reverse_iterator<std::vector<int>::iterator> ft_it_vec2(v.end());
  ft::reverse_iterator<std::vector<int>::iterator> ft_it_vec = ft_it_vec2;
  EXPECT_EQ(*ft_it_vec, 50);
  ft_it_vec++;
  EXPECT_EQ(*ft_it_vec, 40);
}

TEST_F(ReverseIteratorTest, plus_minus) {
  std::reverse_iterator<std::vector<int>::iterator> gnu_it_vec(v.end());
  EXPECT_EQ(*(gnu_it_vec + 2), 30);
  EXPECT_EQ(*gnu_it_vec, 50);
  EXPECT_EQ(*(gnu_it_vec += 2), 30);
  EXPECT_EQ(*gnu_it_vec, 30);
  EXPECT_EQ(*(gnu_it_vec - 2), 50);
  EXPECT_EQ(*gnu_it_vec, 30);
  EXPECT_EQ(*(gnu_it_vec -= 2), 50);
  EXPECT_EQ(*gnu_it_vec, 50);
  
  ft::reverse_iterator<std::vector<int>::iterator> ft_it_vec(v.end());
  EXPECT_EQ(*(ft_it_vec + 2), 30);
  EXPECT_EQ(*ft_it_vec, 50);
  EXPECT_EQ(*(ft_it_vec += 2), 30);
  EXPECT_EQ(*ft_it_vec, 30);
  EXPECT_EQ(*(ft_it_vec - 2), 50);
  EXPECT_EQ(*ft_it_vec, 30);
  EXPECT_EQ(*(ft_it_vec -= 2), 50);
  EXPECT_EQ(*ft_it_vec, 50);
}

TEST_F(ReverseIteratorTest, reference_operators) {
  std::reverse_iterator<std::vector<int>::iterator> gnu_it_vec(v.end());
  gnu_it_vec++;
  EXPECT_EQ(*(gnu_it_vec.base()), 50);
  EXPECT_EQ(*((&gnu_it_vec)->base()), 50);
  EXPECT_EQ(gnu_it_vec[0], 40);
  EXPECT_EQ(gnu_it_vec[2], 20);
  
  ft::reverse_iterator<std::vector<int>::iterator> ft_it_vec(v.end());
  ft_it_vec++;
  EXPECT_EQ(*(ft_it_vec.base()), 50);
  EXPECT_EQ(*((&ft_it_vec)->base()), 50);
  EXPECT_EQ(ft_it_vec[0], 40);
  EXPECT_EQ(ft_it_vec[2], 20);
}

TEST_F(ReverseIteratorTest, comparison_operators) {
  std::reverse_iterator<std::vector<int>::iterator> gnu_it_vec(v.end());
  std::reverse_iterator<std::vector<int>::iterator> gnu_it_same(v.end());
  std::reverse_iterator<std::vector<int>::iterator> gnu_it_right(v.end());
  gnu_it_right++;
  gnu_it_right++;
  EXPECT_TRUE(gnu_it_vec == gnu_it_same);
  EXPECT_FALSE(gnu_it_vec == gnu_it_right);
  EXPECT_FALSE(gnu_it_vec != gnu_it_same);
  EXPECT_TRUE(gnu_it_vec != gnu_it_right);
  EXPECT_FALSE(gnu_it_vec < gnu_it_same);
  EXPECT_TRUE(gnu_it_vec < gnu_it_right);
  EXPECT_FALSE(gnu_it_vec > gnu_it_same);
  EXPECT_FALSE(gnu_it_vec > gnu_it_right);
  EXPECT_TRUE(gnu_it_vec <= gnu_it_same);
  EXPECT_TRUE(gnu_it_vec <= gnu_it_right);
  EXPECT_TRUE(gnu_it_vec >= gnu_it_same);
  EXPECT_FALSE(gnu_it_vec >= gnu_it_right);
  EXPECT_EQ(*(gnu_it_right + 2), 10);
  EXPECT_EQ(gnu_it_right - gnu_it_vec, 2);
  
  ft::reverse_iterator<std::vector<int>::iterator> ft_it_vec(v.end());
  ft::reverse_iterator<std::vector<int>::iterator> ft_it_same(v.end());
  ft::reverse_iterator<std::vector<int>::iterator> ft_it_right(v.end());
  ft_it_right++;
  ft_it_right++;
  EXPECT_TRUE(ft_it_vec == ft_it_same);
  EXPECT_FALSE(ft_it_vec == ft_it_right);
  EXPECT_FALSE(ft_it_vec != ft_it_same);
  EXPECT_TRUE(ft_it_vec != ft_it_right);
  EXPECT_FALSE(ft_it_vec < ft_it_same);
  EXPECT_TRUE(ft_it_vec < ft_it_right);
  EXPECT_FALSE(ft_it_vec > ft_it_same);
  EXPECT_FALSE(ft_it_vec > ft_it_right);
  EXPECT_TRUE(ft_it_vec <= ft_it_same);
  EXPECT_TRUE(ft_it_vec <= ft_it_right);
  EXPECT_TRUE(ft_it_vec >= ft_it_same);
  EXPECT_FALSE(ft_it_vec >= ft_it_right);
  EXPECT_EQ(*(ft_it_right + 2), 10);
  EXPECT_EQ(ft_it_right - ft_it_vec, 2);
}

TEST_F(ReverseIteratorTest, comparison_operators_differenttype) {
  std::reverse_iterator<std::vector<int>::const_iterator> gnu_it_const(v.end());
  std::reverse_iterator<std::vector<int>::iterator> gnu_it_same(v.end());
  std::reverse_iterator<std::vector<int>::iterator> gnu_it_right(v.end());
  ++gnu_it_right;
  ++gnu_it_right;
  EXPECT_TRUE(gnu_it_const == gnu_it_same);
  EXPECT_FALSE(gnu_it_const == gnu_it_right);
  EXPECT_FALSE(gnu_it_const != gnu_it_same);
  EXPECT_TRUE(gnu_it_const != gnu_it_right);
  EXPECT_FALSE(gnu_it_const < gnu_it_same);
  EXPECT_TRUE(gnu_it_const < gnu_it_right);
  EXPECT_FALSE(gnu_it_const > gnu_it_same);
  EXPECT_FALSE(gnu_it_const > gnu_it_right);
  EXPECT_TRUE(gnu_it_const <= gnu_it_same);
  EXPECT_TRUE(gnu_it_const <= gnu_it_right);
  EXPECT_TRUE(gnu_it_const >= gnu_it_same);
  EXPECT_FALSE(gnu_it_const >= gnu_it_right);
  EXPECT_EQ(*(gnu_it_right + 2), 10);
  EXPECT_EQ(gnu_it_right - gnu_it_const, 2);

  ft::reverse_iterator<std::vector<int>::const_iterator> ft_it_const(v.end());
  ft::reverse_iterator<std::vector<int>::iterator> ft_it_same(v.end());
  ft::reverse_iterator<std::vector<int>::iterator> ft_it_right(v.end());
  ++ft_it_right;
  ++ft_it_right;
  EXPECT_TRUE(ft_it_const == ft_it_same);
  EXPECT_FALSE(ft_it_const == ft_it_right);
  EXPECT_FALSE(ft_it_const != ft_it_same);
  EXPECT_TRUE(ft_it_const != ft_it_right);
  EXPECT_FALSE(ft_it_const < ft_it_same);
  EXPECT_TRUE(ft_it_const < ft_it_right);
  EXPECT_FALSE(ft_it_const > ft_it_same);
  EXPECT_FALSE(ft_it_const > ft_it_right);
  EXPECT_TRUE(ft_it_const <= ft_it_same);
  EXPECT_TRUE(ft_it_const <= ft_it_right);
  EXPECT_TRUE(ft_it_const >= ft_it_same);
  EXPECT_FALSE(ft_it_const >= ft_it_right);
  EXPECT_EQ(*(ft_it_right + 2), 10);
  EXPECT_EQ(ft_it_right - ft_it_const, 2);  
}
