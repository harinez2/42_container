
//#ifdef MANUAL_TEST
#include <cstddef>
#include <cassert>
#include <iostream>
#include <vector>

#define EXPECT_TRUE(x) assert(x == true)
#define EXPECT_FALSE(x) assert(x == false)
#define EXPECT_EQ(x,y) assert(x == y)
#define TEST_F(x,y) void x##_##y(VectorTest& vt)
//#endif

#include "test_vector.hpp"
#include "../src/vector.hpp"

namespace testing {
class Test {};
}
#include "test_vector.cpp"




//#ifdef MANUAL_TEST
int main() {
  VectorTest vt;

  // TEST_F(vector, test_VectorTest_constructor);
  VectorTest_int_constructor_copy(vt);
  return 0;
}
//#endif
