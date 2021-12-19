#include "../src/vector.hpp"

class VectorTest : public ::testing::Test {
 protected:
  VectorTest() {
    v_.push_back(42);
    v_.push_back(1);
    v_.push_back(0);
    v_.push_back(-42);
    v_.push_back(4242);
  }
  ~VectorTest() {
  }
  ft::vector<int> v_;
};

void check_all_params_of_vector(ft::vector<int>& vft, std::vector<int>& vstd) {
  EXPECT_EQ(vft.size(), vstd.size());
  EXPECT_EQ(vft.max_size(), vstd.max_size());
  EXPECT_EQ(vft.capacity(), vstd.capacity());
  EXPECT_EQ(vft.empty(), vstd.empty());
}

TEST_F(VectorTest, constructor_basic) {
  ft::vector<int> vft;
  vft.push_back(42);
  EXPECT_EQ(vft[0], 42);
  EXPECT_EQ(vft.size(), 1);

  std::vector<int> vstd;
  vstd.push_back(42);
  EXPECT_EQ(vstd[0], 42);
  EXPECT_EQ(vstd.size(), 1);
  check_all_params_of_vector(vft, vstd);
}

TEST_F(VectorTest, test_vector_constructor) {
  ft::vector<int> v;
  v.push_back(42);
  EXPECT_EQ(v[0], 42);
  EXPECT_EQ(v.size(), 1);

  EXPECT_TRUE(true);
  EXPECT_FALSE(false);
}

TEST_F(VectorTest, test_vector_basic) {
  ft::vector<int> v;
  v.push_back(42);
  v.push_back(21);
  EXPECT_EQ(v[0], 42);
  EXPECT_EQ(v[1], 21);
  EXPECT_EQ(v.size(), 2);
}

TEST_F(VectorTest, test_vector_basic_compare) {
  std::vector<int> vstd;
  ft::vector<int> vft;
  vstd.push_back(42);
  vft.push_back(42);
  vstd.push_back(21);
  vft.push_back(21);
  EXPECT_EQ(vstd[0], vft[0]);
  EXPECT_EQ(vstd[1], vft[1]);
  EXPECT_EQ(vstd.size(), vft.size());
}

