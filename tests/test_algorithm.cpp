#include "../includes/algorithm.hpp"

#include <algorithm>
#include <vector>

class AlgorithmTest : public ::testing::Test {
 public:
  AlgorithmTest() {
    std_v1.push_back(4);
    std_v1.push_back(2);
    std_v1.push_back(0);
  }
  ~AlgorithmTest() {
  }

 protected:
  std::vector<int> std_v1;
};

//------------------------------------------------------

TEST_F(AlgorithmTest, equal_basic_cases) {
  std::vector<int> std_v2;
  std_v2.push_back(4);
  std_v2.push_back(2);
  std_v2.push_back(0);
  std::vector<int> std_v3;
  std_v3.push_back(4);
  std_v3.push_back(2);
  std_v3.push_back(1);
  std::vector<int> std_v4;
  std_v4.push_back(4);
  std_v4.push_back(2);
  std_v4.push_back(0);
  std_v4.push_back(0);

  EXPECT_TRUE(std::equal(std::begin(std_v1), std::end(std_v1), std::begin(std_v2)));
  EXPECT_TRUE(ft::equal(std::begin(std_v1), std::end(std_v1), std::begin(std_v2)));
  
  EXPECT_FALSE(std::equal(std::begin(std_v1), std::end(std_v1), std::begin(std_v3)));
  EXPECT_FALSE(ft::equal(std::begin(std_v1), std::end(std_v1), std::begin(std_v3)));
  
  EXPECT_TRUE(std::equal(std::begin(std_v1), std::end(std_v1), std::begin(std_v4)));
  EXPECT_TRUE(ft::equal(std::begin(std_v1), std::end(std_v1), std::begin(std_v4)));
}

bool predicator_double(int x, int y) {
  if (x * 2 == y)
    return true;
  return false;
}

TEST_F(AlgorithmTest, equal_with_pred) {
  std::vector<int> std_v2;
  std_v2.push_back(8);
  std_v2.push_back(4);
  std_v2.push_back(0);
  std::vector<int> std_v3;
  std_v3.push_back(8);
  std_v3.push_back(4);
  std_v3.push_back(1);
  std::vector<int> std_v4;
  std_v4.push_back(8);
  std_v4.push_back(4);
  std_v4.push_back(0);
  std_v4.push_back(0);

  EXPECT_TRUE(std::equal(std::begin(std_v1), std::end(std_v1), std::begin(std_v2), predicator_double));
  EXPECT_TRUE(ft::equal(std::begin(std_v1), std::end(std_v1), std::begin(std_v2), predicator_double));
  
  EXPECT_FALSE(std::equal(std::begin(std_v1), std::end(std_v1), std::begin(std_v3), predicator_double));
  EXPECT_FALSE(ft::equal(std::begin(std_v1), std::end(std_v1), std::begin(std_v3), predicator_double));
  
  EXPECT_TRUE(std::equal(std::begin(std_v1), std::end(std_v1), std::begin(std_v4), predicator_double));
  EXPECT_TRUE(ft::equal(std::begin(std_v1), std::end(std_v1), std::begin(std_v4), predicator_double));
}

//------------------------------------------------------

TEST_F(AlgorithmTest, lexicographical_basic_cases) {
  // same length, same value
  std::vector<int> std_v2(std_v1);
  std::vector<int> std_v3(std_v1);
  EXPECT_FALSE(std::lexicographical_compare(std_v2.begin(), std_v2.end(),
      std_v3.begin(), std_v3.end()));
  EXPECT_FALSE(ft::lexicographical_compare(std_v2.begin(), std_v2.end(),
      std_v3.begin(), std_v3.end()));

  // left length is short
  std_v3.push_back(1);
  EXPECT_TRUE(std::lexicographical_compare(std_v2.begin(), std_v2.end(),
      std_v3.begin(), std_v3.end()));
  EXPECT_TRUE(ft::lexicographical_compare(std_v2.begin(), std_v2.end(),
      std_v3.begin(), std_v3.end()));

  // same length, left value is small
  std_v2.push_back(0);
  EXPECT_TRUE(std::lexicographical_compare(std_v2.begin(), std_v2.end(),
      std_v3.begin(), std_v3.end()));
  EXPECT_TRUE(ft::lexicographical_compare(std_v2.begin(), std_v2.end(),
      std_v3.begin(), std_v3.end()));

  // same length, right value is small
  std_v2.pop_back();
  std_v3.pop_back();
  std_v2.push_back(1);
  std_v3.push_back(0);
  EXPECT_FALSE(std::lexicographical_compare(std_v2.begin(), std_v2.end(),
      std_v3.begin(), std_v3.end()));
  EXPECT_FALSE(ft::lexicographical_compare(std_v2.begin(), std_v2.end(),
      std_v3.begin(), std_v3.end()));
}

TEST_F(AlgorithmTest, lexicographical_with_compare) {
  // same length, same value
  std::vector<int> std_v2(std_v1);
  std::vector<int> std_v3(std_v1);
  EXPECT_FALSE(std::lexicographical_compare(std_v2.begin(), std_v2.end(),
      std_v3.begin(), std_v3.end(), std::greater<int>()));
  EXPECT_FALSE(ft::lexicographical_compare(std_v2.begin(), std_v2.end(),
      std_v3.begin(), std_v3.end(), std::greater<int>()));

  // left length is short
  std_v3.push_back(1);
  EXPECT_TRUE(std::lexicographical_compare(std_v2.begin(), std_v2.end(),
      std_v3.begin(), std_v3.end(), std::greater<int>()));
  EXPECT_TRUE(ft::lexicographical_compare(std_v2.begin(), std_v2.end(),
      std_v3.begin(), std_v3.end(), std::greater<int>()));

  // same length, left value is small
  std_v2.push_back(0);
  EXPECT_FALSE(std::lexicographical_compare(std_v2.begin(), std_v2.end(),
      std_v3.begin(), std_v3.end(), std::greater<int>()));
  EXPECT_FALSE(ft::lexicographical_compare(std_v2.begin(), std_v2.end(),
      std_v3.begin(), std_v3.end(), std::greater<int>()));

  // same length, right value is small
  std_v2.pop_back();
  std_v3.pop_back();
  std_v2.push_back(1);
  std_v3.push_back(0);
  EXPECT_TRUE(std::lexicographical_compare(std_v2.begin(), std_v2.end(),
      std_v3.begin(), std_v3.end(), std::greater<int>()));
  EXPECT_TRUE(ft::lexicographical_compare(std_v2.begin(), std_v2.end(),
      std_v3.begin(), std_v3.end(), std::greater<int>()));
}
