
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

  VectorTest_int_constructor_empty(vt);
  VectorTest_int_constructor_allocator(vt);
  VectorTest_int_constructor_value(vt);
  VectorTest_int_constructor_value_initvalue(vt);
  VectorTest_int_constructor_value_initvalue_allocator(vt);
  VectorTest_int_constructor_valuearray(vt);
  VectorTest_int_constructor_border(vt);
  VectorTest_int_constructor_copy(vt);
  VectorTest_int_basic(vt);
  VectorTest_int_size(vt);
  VectorTest_int_maxsize(vt);
  VectorTest_int_resize(vt);
  VectorTest_int_capacity(vt);
  VectorTest_int_empty(vt);
  VectorTest_int_reserve(vt);
  VectorTest_int_clear(vt);
  VectorTest_str_constructor_empty(vt);
  return 0;
}
