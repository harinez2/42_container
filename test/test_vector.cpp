#include "../src/vector.hpp"
#include "test_vector.hpp"

#include <vector>

class VectorTest : public ::testing::Test {
 public:
  VectorTest() {
    vft_.push_back(42);
    vft_.push_back(1);
    vft_.push_back(0);
    vft_.push_back(-42);
    vft_.push_back(4242);
    
    vstd_.push_back(42);
    vstd_.push_back(1);
    vstd_.push_back(0);
    vstd_.push_back(-42);
    vstd_.push_back(4242);
  }
  ~VectorTest() {
  }

 protected:
  ft::vector<int> vft_;
  std::vector<int> vstd_;
};

//------------------------------------------------------
// constructor (int)

TEST_F(VectorTest, int_constructor_empty) {
  ft::vector<int> vft;
  std::vector<int> vstd;

  EXPECT_EQ(vft.size(), 0);
  EXPECT_TRUE(vft.empty());
  compare_with_std_vector(vft, vstd);
}

TEST_F(VectorTest, int_constructor_init_four_array) {
  ft::vector<int> vft(4);
  std::vector<int> vstd(4);

  EXPECT_EQ(vft.size(), 4);
  EXPECT_FALSE(vft.empty());
  compare_with_std_vector(vft, vstd);
}

TEST_F(VectorTest, int_constructor_init_err_bordermin) {
  ft::vector<int> vft(0);
  std::vector<int> vstd(0);

  EXPECT_EQ(vft.size(), 0);
  EXPECT_TRUE(vft.empty());
  compare_with_std_vector(vft, vstd);
}

TEST_F(VectorTest, int_constructor_init_err_bordermax) {
  ft::vector<int> vft(65535);
  std::vector<int> vstd(65535);

  EXPECT_EQ(vft.size(), 65535);
  EXPECT_FALSE(vft.empty());
  compare_with_std_vector(vft, vstd);
}
//------------------------------------------------------
// constructor (string)

// TEST_F(VectorTest, constructor_empty_string) {
//   ft::vector<std::string> vft;
//   std::vector<std::string> vstd;

//   EXPECT_EQ(vft.size(), 0);
//   EXPECT_TRUE(vft.empty());
//   compare_with_std_vector(vft, vstd);
// }

// TEST_F(VectorTest, constructor_init_with_same_value_int) {
//   ft::vector<std::string> vft("hello", 100);
//   std::vector<std::string> vstd("hello", 100);

//   EXPECT_EQ(vft.size(), 100);
//   EXPECT_EQ(vft[0], "hello");
//   EXPECT_FALSE(vft.empty());
//   compare_with_std_vector(vft, vstd);
// }

//------------------------------------------------------
// basic (int)

TEST_F(VectorTest, int_basic) {
  ft::vector<int> vft;
  std::vector<int> vstd;
  vft.push_back(42);
  vstd.push_back(42);

  EXPECT_EQ(vft[0], 42);
  compare_with_std_vector(vft, vstd);
  
  vft.push_back(21);
  vstd.push_back(21);

  EXPECT_EQ(vft[0], 42);
  EXPECT_EQ(vft[1], 21);
  compare_with_std_vector(vft, vstd);
}

