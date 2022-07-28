#include "../src/rb_tree.hpp"

class RbTreeTest : public ::testing::Test {
 public:
  RbTreeTest() {
  }
  ~RbTreeTest() {
  }

 protected:
};

//------------------------------------------------------

TEST_F(RbTreeTest, basic_cases) {
  ft::rb_tree<int> t;
  t.showAllTree();

  
}
