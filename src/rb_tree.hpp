#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#define NILNODE     0
#define RED         1
#define BLACK       2

namespace ft {

template <typename T>
class rb_tree {
 public:
  typedef T&                                         reference;
  typedef const T&                                   const_reference;
  typedef std::size_t                                size_type;
  typedef std::ptrdiff_t                             difference_type;
  typedef T                                          value_type;
  typedef T*                                         pointer;

  typedef struct s_node {
    int               color;
    value_type        key;
    struct s_node*    left;
    struct s_node*    right;
    struct s_node*    parent;
  } node;

  // constructor
  rb_tree() {
    nil_ = create_new_node_(0);
    nil_->color = NILNODE;
    root_ = nil_;
  }

  // destructor
  ~rb_tree() {}

  void rb_insert(node* z) {
    node* y = nil_;
    node* x = root_;
    while (x != nil_) {
      y = x;
      if (z->key < x->key) {
        x = x->left;
      } else {
        x = x->right;
      }
    }
    z->parent = y;
    if (y == nil_) {
      root_ = z;
    } else if (z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
    z->left = nil_;
    z->right = nil_;
    z->color = RED;
    insert_fixup_(z);
  }

  void rb_delete(node* z) {
    node* y = z;
    node* x;
    int y_original_color = y->color;
    if (z->left == nil_) {
      x = z->right;
      transplant_(z, z->right);
    } else if (z->right == nil_) {
      x = z->left;
      transplant_(z, z->left);
    } else {
      y = tree_minimum_(z->right);
      y_original_color = y->color;
      if (y->parent == z) {
        x->parent = y;
      } else {
        transplant_(y, y->right);
        y->right = z->right;
        y->right->parent = y;
      }
      transplant_(z, y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
    }
    if (y_original_color == BLACK) {
      delete_fixup_(x);
    }
  }

 private:
  node*       root_;
  node*       nil_;

  node* create_new_node_(value_type x) {
    node* new_node = new node();

    new_node->color = RED;
    new_node->key = x;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;
    return new_node;
  }

  void left_rotate_(node* x) {
    node* y = x->right;
    x->right = y->left;
    if (y->left != nil_) {
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nil_) {
      root_ = y;
    } else if (x == x->parent->left) {
      x->parent->left = y;
    } else {
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
  }

  void right_rotate_(node* x) {
    node* y = x->left;
    x->left = y->right;
    if (y->right != nil_) {
      y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nil_) {
      root_ = y;
    } else if (x == x->parent->right) {
      x->parent->right = y;
    } else {
      x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
  }

  void insert_fixup_(node* z) {
    node* y;
    while (z->parent->color == RED) {
      if (z->parent == z->parent->parent->left) {
        y = z->parent->parent->right;
        if (y->color == RED) {
          z->parent->color = BLACK;
          y->color = BLACK;
          z->parent->parent->color = RED;
          z = z->parent->parent;
        } else if (z == z->parent->right) {
          z = z->parent;
          left_rotate_(z);
        }
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        right_rotate_(z->parent->parent);
      } else {
        y = z->parent->parent->left;
        if (y->color == RED) {
          z->parent->color = BLACK;
          y->color = BLACK;
          z->parent->parent->color = RED;
          z = z->parent->parent;
        } else if (z == z->parent->left) {
          z = z->parent;
          right_rotate_(z);
        }
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        left_rotate_(z->parent->parent);
      }
    }
    root_->color = BLACK;
  }

  // place v node on u
  void transplant_(node* u, node* v) {
    if (u->parent == nil_) {
      root_ = v;
    } else if (u == u->parent->left) {
      u->parent->left = v;
    } else {
      u->parent->right = v;
    }
    v->parent = u->parent;
  }

  void tree_minimum_(node* z) {

  }

  void delete_fixup_(node* x) {

  }
};

} // namespace ft

#endif
