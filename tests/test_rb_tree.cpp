#include "../includes/rb_tree.hpp"

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
  t.insert_node(1);
  t.insert_node(2);
  t.insert_node(3);
  t.insert_node(4);
  t.insert_node(5);
  t.show_all_list();
  t.show_all_tree();

  t.delete_node(4);
  t.show_all_tree();
}
