#include "../src/algorithm.hpp"

#include <algorithm>
#include <vector>

class AlgorithmTest : public ::testing::Test {
 public:
  AlgorithmTest() {
  }
  ~AlgorithmTest() {
  }
};

//------------------------------------------------------

TEST_F(AlgorithmTest, equal_basic_cases) {
  std::vector<int> std_v1 = {4, 2, 0};
  std::vector<int> std_v2 = {4, 2, 0};
  std::vector<int> std_v3 = {4, 2, 1};
  std::vector<int> std_v4 = {4, 2, 0, 0};

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
  std::vector<int> std_v1 = {4, 2, 0};
  std::vector<int> std_v2 = {8, 4, 0};
  std::vector<int> std_v3 = {8, 4, 1};
  std::vector<int> std_v4 = {8, 4, 0, 0};

  EXPECT_TRUE(std::equal(std::begin(std_v1), std::end(std_v1), std::begin(std_v2), predicator_double));
  EXPECT_TRUE(ft::equal(std::begin(std_v1), std::end(std_v1), std::begin(std_v2), predicator_double));
  
  EXPECT_FALSE(std::equal(std::begin(std_v1), std::end(std_v1), std::begin(std_v3), predicator_double));
  EXPECT_FALSE(ft::equal(std::begin(std_v1), std::end(std_v1), std::begin(std_v3), predicator_double));
  
  EXPECT_TRUE(std::equal(std::begin(std_v1), std::end(std_v1), std::begin(std_v4), predicator_double));
  EXPECT_TRUE(ft::equal(std::begin(std_v1), std::end(std_v1), std::begin(std_v4), predicator_double));
}
