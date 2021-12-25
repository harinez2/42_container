#ifndef TEST_VECTOR_HPP
#define TEST_VECTOR_HPP

#include "../src/vector.hpp"

#include <vector>

template <typename T>
void compare_with_std_vector(ft::vector<T>& vft, std::vector<T>& vstd) {
  EXPECT_EQ(vft.size(), vstd.size());
  EXPECT_EQ(vft.max_size(), vstd.max_size());
  EXPECT_EQ(vft.capacity(), vstd.capacity());
  EXPECT_EQ(vft.empty(), vstd.empty());
  for (size_t i = 0; i < vstd.size(); ++i)
    EXPECT_EQ(vft[i], vstd[i]);
}

#endif
