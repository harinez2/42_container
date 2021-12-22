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

TEST_F(VectorTest, int_constructor_with_allocator) {
  std::allocator<int> alc;
  ft::vector<int> vft(alc);
  std::vector<int> vstd(alc);

  EXPECT_EQ(vft.size(), 0);
  EXPECT_TRUE(vft.empty());
  compare_with_std_vector(vft, vstd);
}

TEST_F(VectorTest, int_constructor_init_with_value) {
  ft::vector<int> vft(4);
  std::vector<int> vstd(4);

  EXPECT_EQ(vft.size(), 4);
  EXPECT_FALSE(vft.empty());
  compare_with_std_vector(vft, vstd);
}

// TEST_F(VectorTest, int_constructor_init_with_value_two) {
//   ft::vector<int> vft(4, 2);
//   std::vector<int> vstd(4, 2);

//   EXPECT_EQ(vft.size(), 4);
//   EXPECT_FALSE(vft.empty());
//   compare_with_std_vector(vft, vstd);
// }

// TEST_F(VectorTest, int_constructor_init_with_value_two_with_allocator) {
//   ft::vector<int> vft(4, 2, std::allocator<int>);
//   std::vector<int> vstd(4, 2, std::allocator<int>);

//   EXPECT_EQ(vft.size(), 0);
//   EXPECT_TRUE(vft.empty());
//   compare_with_std_vector(vft, vstd);
// }

//------------------------------------------------------
// constructor (int) border

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
// copy constructor (int)

// TEST_F(VectorTest, int_constructor_copy) {
//   ft::vector<int> vft(4);
//   ft::vector<int> vft2(vft);
//   std::vector<int> vstd(4);
//   std::vector<int> vstd2(vstd);

//   EXPECT_EQ(vft2.size(), 4);
//   EXPECT_FALSE(vft2.empty());
//   compare_with_std_vector(vft2, vstd2);
// }

//------------------------------------------------------
// constructor with iterator (int)

// ezoe
// TEST_F(VectorTest, int_constructor_iterator) {
  // std::vector<int> v = {1,2,3,4,5} ;

  // auto i = v.begin();
  // *i ; // 1

// }

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

//https://programming-place.net/ppp/contents/cpp/library/005.html
// TEST_F(VectorTest, int_swap) {

//   std::vector<int> v;
//   v.reserve(10000);
//   v.push_back(0);

//   EXPECT_EQ(v.capacity(), 10000);

//   std::vector<int>(v).swap(v);

//   EXPECT_EQ(v.capacity(), 1);
// }
