#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

namespace ft {

template <typename T, typename Allocator = std::allocator<T> >
class vector {
 public:
  typedef T* iterator;
  typedef const T* const_iterator;
  typedef std::reverse_iterator<iterator> reverse_iterator; //TODO
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator; //TODO

  vector() {
    first_ = alc.allocate(default_size_);
    last_ = first_;
    reserved_last_ = first_ + default_size_;
  }

  vector(const vector& rhs) { *this = rhs; }

  vector& operator=(const vector& rhs) {
    if (this != &rhs) {
    }
    return *this;
  }

  ~vector() {
    for (std::size_t i = 0; i != size(); ++i)
      alc.destroy(first_ + i);
    alc.deallocate(first_, reserved_last_ - first_);
  }

  void push_back(const T& var) {
    if (last_ == reserved_last_) {
      //reallocate
    }
    alc.construct(first_ + size(), var);
    ++last_;
  }

  T& operator[](std::size_t idx) const {
    if (idx < 0 || size() <= idx)
      throw std::exception();
    return first_[idx];
  }

  iterator begin() { return first_; }
  iterator end() { return last_; }
  std::size_t size() const { return last_ - first_; }

 private:
  static const int default_size_ = 8;
  Allocator alc;
  T* first_;
  T* last_;
  T* reserved_last_;
};

} // namespace ft

#endif
