#include "../src/is_integral.hpp"

#include <type_traits>

class EnableIfTest : public ::testing::Test {
 public:
  EnableIfTest() {
  }
  ~EnableIfTest() {
  }

 protected:
  enum my_enum{};
};

//------------------------------------------------------

TEST_F(EnableIfTest, basic_cases) {
  bool ret;

  ret = std::is_same<std::enable_if<true, int>::type, int>::value;
  EXPECT_TRUE(ret);
  ret = std::is_same<std::enable_if<true, int>::type, bool>::value;
  EXPECT_FALSE(ret);
  ret = std::is_same<std::enable_if<true, int>::type, std::true_type>::value;
  EXPECT_FALSE(ret);
  ret = std::is_same<std::enable_if<true>::type, void>::value;
  EXPECT_TRUE(ret);

  ret = std::is_same<ft::enable_if<true, int>::type, int>::value;
  EXPECT_TRUE(ret);
  ret = std::is_same<ft::enable_if<true, int>::type, bool>::value;
  EXPECT_FALSE(ret);
  ret = std::is_same<ft::enable_if<true, int>::type, ft::true_type>::value;
  EXPECT_FALSE(ret);
  ret = std::is_same<ft::enable_if<true>::type, void>::value;
  EXPECT_TRUE(ret);
}

TEST_F(EnableIfTest, with_isintegral) {
  bool  ret;

  ret = std::is_same<std::enable_if<std::is_integral<int>::value, int>::type, int>::value;
  EXPECT_TRUE(ret);

  ret = std::is_same<ft::enable_if<ft::is_integral<int>::value, int>::type, int>::value;
  EXPECT_TRUE(ret);
}

template<typename T>
bool std_truefalsetest(T t, typename std::enable_if<std::is_integral<T>::value >::type* = 0) {
  return true;
}
bool std_truefalsetest(...) {
  return false;
}

template<typename T>
bool ft_truefalsetest(T t, typename ft::enable_if<ft::is_integral<T>::value >::type* = 0) {
  return true;
}
bool ft_truefalsetest(...) {
  return false;
}

TEST_F(EnableIfTest, truefalse_test) {
  bool  ret;

  ret = std_truefalsetest(42);
  EXPECT_TRUE(ret);
  ret = std_truefalsetest(3.14f);
  EXPECT_FALSE(ret);

  ret = ft_truefalsetest(42);
  EXPECT_TRUE(ret);
  ret = ft_truefalsetest(3.14f);
  EXPECT_FALSE(ret);
}
