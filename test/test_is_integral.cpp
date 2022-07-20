#include "../src/type_traits.hpp"

class IsIntegralTest : public ::testing::Test {
 public:
  IsIntegralTest() {
  }
  ~IsIntegralTest() {
  }

 protected:
  enum my_enum{};
};

//------------------------------------------------------

TEST_F(IsIntegralTest, basic_cases) {
  bool ret;

  EXPECT_TRUE(std::is_integral<int>::value);
  ret = std::is_same<std::is_integral<int>::value_type, int>::value;
  EXPECT_FALSE(ret);
  ret = std::is_same<std::is_integral<int>::value_type, bool>::value;
  EXPECT_TRUE(ret);
  ret = std::is_same<std::is_integral<int>::type, std::true_type>::value;
  EXPECT_TRUE(ret);
  EXPECT_TRUE(std::is_integral<int>());

  EXPECT_TRUE(ft::is_integral<int>::value);
  ret = std::is_same<ft::is_integral<int>::value_type, int>::value;
  EXPECT_FALSE(ret);
  ret = std::is_same<ft::is_integral<int>::value_type, bool>::value;
  EXPECT_TRUE(ret);
  ret = std::is_same<ft::is_integral<int>::type, ft::true_type>::value;
  EXPECT_TRUE(ret);
  EXPECT_TRUE(ft::is_integral<int>());
}

TEST_F(IsIntegralTest, pointer_cases) {
  bool ret;

  EXPECT_FALSE(std::is_integral<int*>::value);
  ret = std::is_same<std::is_integral<int*>::value_type, bool>::value;
  EXPECT_TRUE(ret);
  ret = std::is_same<std::is_integral<int*>::type, std::false_type>::value;
  EXPECT_TRUE(ret);
  EXPECT_FALSE(std::is_integral<int*>());

  EXPECT_FALSE(ft::is_integral<int*>::value);
  ret = std::is_same<ft::is_integral<int*>::value_type, bool>::value;
  EXPECT_TRUE(ret);
  ret = std::is_same<ft::is_integral<int*>::type, ft::false_type>::value;
  EXPECT_TRUE(ret);
  EXPECT_FALSE(ft::is_integral<int*>());
}

TEST_F(IsIntegralTest, integral_cases) {
  EXPECT_TRUE(std::is_integral<bool>::value);
  EXPECT_TRUE(std::is_integral<char>::value);
  EXPECT_TRUE(std::is_integral<unsigned char>::value);
  EXPECT_TRUE(std::is_integral<unsigned short>::value);
  EXPECT_TRUE(std::is_integral<unsigned int>::value);
  EXPECT_TRUE(std::is_integral<unsigned long>::value);

  EXPECT_TRUE(ft::is_integral<bool>::value);
  EXPECT_TRUE(ft::is_integral<char>::value);
  EXPECT_TRUE(ft::is_integral<unsigned char>::value);
  EXPECT_TRUE(ft::is_integral<unsigned short>::value);
  EXPECT_TRUE(ft::is_integral<unsigned int>::value);
  EXPECT_TRUE(ft::is_integral<unsigned long>::value);
}

TEST_F(IsIntegralTest, non_integral_cases) {
  EXPECT_FALSE(std::is_integral<my_enum>::value);
  EXPECT_FALSE(std::is_integral<int&>::value);
  EXPECT_FALSE(std::is_integral<int[1]>::value);
  EXPECT_FALSE(std::is_integral<int ()>::value);
  EXPECT_FALSE(std::is_integral<float>::value);
  
  EXPECT_FALSE(ft::is_integral<my_enum>::value);
  EXPECT_FALSE(ft::is_integral<int&>::value);
  EXPECT_FALSE(ft::is_integral<int[1]>::value);
  EXPECT_FALSE(ft::is_integral<int ()>::value);
  EXPECT_FALSE(ft::is_integral<float>::value);
}
