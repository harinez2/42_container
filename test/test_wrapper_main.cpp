
#include <cstddef>
#include <cassert>
#include <iostream>
#include <vector>

#define EXPECT_TRUE(x) assert(x == true)
#define EXPECT_FALSE(x) assert(x == false)
#define EXPECT_EQ(x,y) assert(x == y)
#define TEST_F(x,y) void x##_##y(VectorTest& vt)

namespace testing {
class Test {};
}
#include "test_vector.cpp"

int main() {
  VectorTest vt;

  VectorTest_int_constructor_copy(vt);
  return 0;
}
