#include "../includes/utility.hpp"

#include <utility>

class UtilityTest : public ::testing::Test {
 public:
  UtilityTest() {
  }
  ~UtilityTest() {
  }

 protected:
  std::pair<int, int> std_p1_int = std::pair<int, int>(2, 4);
  std::pair<int, int> std_p2_int = std::pair<int, int>(2, 4);
  std::pair<int, int> std_p3_int = std::pair<int, int>(4, 2);
  ft::pair<int, int> ft_p1_int = ft::pair<int, int>(2, 4);
  ft::pair<int, int> ft_p2_int = ft::pair<int, int>(2, 4);
  ft::pair<int, int> ft_p3_int = ft::pair<int, int>(4, 2);

  std::pair<float, float> std_p1_float = std::pair<float, float>(2.1f, 3.14f);
  std::pair<float, float> std_p2_float = std::pair<float, float>(3.1f, 2.14f);
  ft::pair<float, float> ft_p1_float = ft::pair<float, float>(2.1f, 3.14f);
  ft::pair<float, float> ft_p2_float = ft::pair<float, float>(3.1f, 2.14f);
};

//------------------------------------------------------

TEST_F(UtilityTest, pair_basic_cases) {
  EXPECT_EQ(std_p1_int.first, 2);
  EXPECT_EQ(std_p1_int.second, 4);
  EXPECT_EQ(ft_p1_int.first, 2);
  EXPECT_EQ(ft_p1_int.second, 4);

  EXPECT_EQ(std_p1_float.first, 2.1f);
  EXPECT_EQ(std_p1_float.second, 3.14f);
  EXPECT_EQ(ft_p1_float.first, 2.1f);
  EXPECT_EQ(ft_p1_float.second, 3.14f);
}

TEST_F(UtilityTest, pair_constructors) {
  std::pair<int, int> std_int_empty;
  ft::pair<int, int> ft_int_empty;
  EXPECT_EQ(std_int_empty.first, 0);
  EXPECT_EQ(std_int_empty.second, 0);
  EXPECT_EQ(ft_int_empty.first, 0);
  EXPECT_EQ(ft_int_empty.second, 0);

  std::pair<char, char> std_char_empty;
  ft::pair<char, char> ft_char_empty;
  EXPECT_EQ(std_char_empty.first, 0);
  EXPECT_EQ(std_char_empty.second, 0);
  EXPECT_EQ(ft_char_empty.first, 0);
  EXPECT_EQ(ft_char_empty.second, 0);

  std::pair<int, int> std_int_twovalue(7, 8);
  ft::pair<int, int> ft_int_twovalue(7, 8);
  EXPECT_EQ(std_int_twovalue.first, 7);
  EXPECT_EQ(std_int_twovalue.second, 8);
  EXPECT_EQ(ft_int_twovalue.first, 7);
  EXPECT_EQ(ft_int_twovalue.second, 8);

  std::pair<int, int> std_int_copyconst(std_int_twovalue);
  ft::pair<int, int> ft_int_copyconst(ft_int_twovalue);
  EXPECT_EQ(std_int_copyconst.first, 7);
  EXPECT_EQ(std_int_copyconst.second, 8);
  EXPECT_EQ(ft_int_copyconst.first, 7);
  EXPECT_EQ(ft_int_copyconst.second, 8);

  std::pair<float, float> std_float_typechange = std_int_twovalue;
  ft::pair<float, float> ft_float_typechange = ft_int_twovalue;
  EXPECT_EQ(std_float_typechange.first, 7.0f);
  EXPECT_EQ(std_float_typechange.second, 8.0f);
  EXPECT_EQ(ft_float_typechange.first, 7.0f);
  EXPECT_EQ(ft_float_typechange.second, 8.0f);
  
  std::pair<int, int> std_int_assign;
  ft::pair<int, int> ft_int_assign;
  std_int_assign = std_int_twovalue;
  ft_int_assign = ft_int_twovalue;
  EXPECT_EQ(std_int_assign.first, 7);
  EXPECT_EQ(std_int_assign.second, 8);
  EXPECT_EQ(ft_int_assign.first, 7);
  EXPECT_EQ(ft_int_assign.second, 8);
}

TEST_F(UtilityTest, pair_non_member_operators) {
  // operator==
  EXPECT_TRUE(std_p1_int == std_p2_int);
  EXPECT_TRUE(ft_p1_int == ft_p2_int);
  EXPECT_FALSE(std_p2_int == std_p3_int);
  EXPECT_FALSE(ft_p2_int == ft_p3_int);

  // operator!=
  EXPECT_FALSE(std_p1_int != std_p2_int);
  EXPECT_FALSE(ft_p1_int != ft_p2_int);
  EXPECT_TRUE(std_p2_int != std_p3_int);
  EXPECT_TRUE(ft_p2_int != ft_p3_int);
  
  // operator<
  EXPECT_FALSE(std_p1_int < std_p2_int);
  EXPECT_FALSE(ft_p1_int < ft_p2_int);
  EXPECT_TRUE(std_p2_int < std_p3_int);
  EXPECT_TRUE(ft_p2_int < ft_p3_int);
  EXPECT_FALSE(std_p3_int < std_p2_int);
  EXPECT_FALSE(ft_p3_int < ft_p2_int);

  // operator>
  EXPECT_FALSE(std_p1_int > std_p2_int);
  EXPECT_FALSE(ft_p1_int > ft_p2_int);
  EXPECT_TRUE(std_p3_int > std_p2_int);
  EXPECT_TRUE(ft_p3_int > ft_p2_int);
  EXPECT_FALSE(std_p2_int > std_p3_int);
  EXPECT_FALSE(ft_p2_int > ft_p3_int);

  // operator<=
  EXPECT_TRUE(std_p1_int <= std_p2_int);
  EXPECT_TRUE(ft_p1_int <= ft_p2_int);
  EXPECT_TRUE(std_p2_int <= std_p3_int);
  EXPECT_TRUE(ft_p2_int <= ft_p3_int);
  EXPECT_FALSE(std_p3_int <= std_p2_int);
  EXPECT_FALSE(ft_p3_int <= ft_p2_int);

  // operator>=
  EXPECT_TRUE(std_p1_int >= std_p2_int);
  EXPECT_TRUE(ft_p1_int >= ft_p2_int);
  EXPECT_TRUE(std_p3_int >= std_p2_int);
  EXPECT_TRUE(ft_p3_int >= ft_p2_int);
  EXPECT_FALSE(std_p2_int >= std_p3_int);
  EXPECT_FALSE(ft_p2_int >= ft_p3_int);
}

TEST_F(UtilityTest, make_pair) {
  std::pair<int, int> std_int_twovalue = std::make_pair(7, 8);
  ft::pair<int, int> ft_int_twovalue = ft::make_pair(7, 8);
  EXPECT_EQ(std_int_twovalue.first, 7);
  EXPECT_EQ(std_int_twovalue.second, 8);
  EXPECT_EQ(ft_int_twovalue.first, 7);
  EXPECT_EQ(ft_int_twovalue.second, 8);
}
