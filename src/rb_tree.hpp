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
    nil_ = create_new_node_(value_type());
    nil_->color = BLACK;
    root_ = nil_;
  }

  // destructor
  ~rb_tree() {
    delete_tree_(root_);
    delete nil_;
  }

  void insert(value_type n) {
    rb_insert_(create_new_node_(n));
  }

  void rb_delete(node* z) {
    node* y = z;
    node* x;
    int y_original_color = y->color;
    if (z->left == nil_) {
      x = z->right;
      rb_transplant_(z, z->right);
    } else if (z->right == nil_) {
      x = z->left;
      rb_transplant_(z, z->left);
    } else {
      y = tree_minimum_(z->right);
      y_original_color = y->color;
      if (y->parent == z) {
        x->parent = y;
      } else {
        rb_transplant_(y, y->right);
        y->right = z->right;
        y->right->parent = y;
      }
      rb_transplant_(z, y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
    }
    if (y_original_color == BLACK) {
      rb_delete_fixup_(x);
    }
  }

  void show_all_list() {
    inorder_tree_walk_(root_);
  }
  void show_all_tree() {
    inorder_tree_walk_tree_(root_, 0);
  }

  template <typename U>
  node* iterative_tree_search(node* x, U key) {
    while (x != nil_ && key != x->key) {
      if (key < x->ley) {
        x = x->left;
      } else {
        x = x->right;
      }
    }
    return x;
  }

  node* tree_successor(node* x) {
    node* y;
    if (x->right != nil_)
      return tree_minimum_(x->right);
    y = x->parent;
    while (y != nil_ && x == y->right) {
      x = y;
      y = y->parent;
    }
    return y;
  }

  node* tree_predecessor(node* x) {
    node* y;
    if (x->left != nil_)
      return tree_minimum_(x->left);
    y = x->parent;
    while (y != nil_ && x == y->left) {
      x = y;
      y = y->parent;
    }
    return y;
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

  void rb_insert_(node* z) {
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
    rb_insert_fixup_(z);
  }

  void rb_insert_fixup_(node* z) {
    node* y;
    while (z->parent->color == RED) {
      if (z->parent == z->parent->parent->left) {
        y = z->parent->parent->right;
        if (y->color == RED) {
          z->parent->color = BLACK;
          y->color = BLACK;
          z->parent->parent->color = RED;
          z = z->parent->parent;
        } else {
          if (z == z->parent->right) {
            z = z->parent;
            left_rotate_(z);
          }
          z->parent->color = BLACK;
          z->parent->parent->color = RED;
          right_rotate_(z->parent->parent);
        }
      } else {
        y = z->parent->parent->left;
        if (y->color == RED) {
          z->parent->color = BLACK;
          y->color = BLACK;
          z->parent->parent->color = RED;
          z = z->parent->parent;
        } else {
          if (z == z->parent->left) {
            z = z->parent;
            right_rotate_(z);
          }
          z->parent->color = BLACK;
          z->parent->parent->color = RED;
          left_rotate_(z->parent->parent);
        }
      }
    }
    root_->color = BLACK;
  }

  // place v node on u
  void rb_transplant_(node* u, node* v) {
    if (u->parent == nil_) {
      root_ = v;
    } else if (u == u->parent->left) {
      u->parent->left = v;
    } else {
      u->parent->right = v;
    }
    v->parent = u->parent;
  }

  node* tree_minimum_(node* x) {
    while (x->left != nil_) {
      x = x->left;
    }
    return x;
  }

  node* tree_maximum_(node* x) {
    while (x->right != nil_) {
      x = x->right;
    }
    return x;
  }

  void rb_delete_fixup_(node* x) {
    node* w;
    while (x != root_ && x->color == RED) {
      if (x == x->parent->left) {
        w = x->parent->right;
        if (w->color == RED) {
          w->color = BLACK;
          x->parent->color = RED;
          left_rotate_(x->parent);
          w = x->parent->right;
        }
        if (w->left->color == BLACK && w->right->color == BLACK) {
          w->color = RED;
          x = x->parent;
        } else {
          if (w->right->color == BLACK) {
            w->left->color = BLACK;
            w->color = RED;
            right_rotate_(w);
            w = x->p->right;
          }
          w->color = x->parent->color;
          x->parent->color = BLACK;
          w->right->color = BLACK;
          left_rotate_(x->parent);
          x = root_;
        }
      } else {
        w = x->parent->left;
        if (w->color == RED) {
          w->color = BLACK;
          x->parent->color = RED;
          right_rotate_(x->parent);
          w = x->parent->left;
        }
        if (w->right->color == BLACK && w->left->color == BLACK) {
          w->color = RED;
          x = x->parent;
        } else {
          if (w->left->color == BLACK) {
            w->right->color = BLACK;
            w->color = RED;
            left_rotate_(w);
            w = x->p->left;
          }
          w->color = x->parent->color;
          x->parent->color = BLACK;
          w->left->color = BLACK;
          right_rotate_(x->parent);
          x = root_;
        }
      }
    }
    x->color = BLACK;
  }

  void inorder_tree_walk_(node* x) {
    if (x != nil_) {
      inorder_tree_walk_(x->left);
      std::cout << x->key << std::endl;
      inorder_tree_walk_(x->right);
    }
  }
  void inorder_tree_walk_tree_(node* x, int depth) {
    if (x != nil_) {
      inorder_tree_walk_tree_(x->left, depth + 1);
      for (int i = 0; i < depth; ++i)
        std::cout << "  ";
      if (x->color == RED)
        std::cout << x->key << "r" << std::endl;
      else
        std::cout << x->key << "b" << std::endl;
      inorder_tree_walk_tree_(x->right, depth + 1);
    }
  }

  void delete_tree_(node* x) {
    if (x != nil_) {
      delete_tree_(x->left);
      delete_tree_(x->right);
      delete x;
    }
  }
};

} // namespace ft

#endif
