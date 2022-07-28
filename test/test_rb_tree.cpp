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
  t.insert(1);
  t.insert(2);
  t.insert(3);
  t.insert(4);
  t.insert(5);
  t.show_all_list();
  t.show_all_tree();
}
