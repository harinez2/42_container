#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

namespace ft {

template <typename T, typename allocator = std::allocator<T> >
class vector {
 public:
  vector() : size_(default_size_), end_(0) {
    alc = allocator();
    data_ = alc.allocate(default_size_);
  }

  vector(const vector& rhs) { *this = rhs; }

  vector& operator=(const vector& rhs) {
    if (this != &rhs) {
    }
    return *this;
  }

  ~vector() {
    for (std::size_t i = 0; i != 8; ++i)
      alc.destroy(data_ + i);
    alc.deallocate(data_, 8);
  }

 private:
  static const int default_size_ = 8;
  allocator alc;
  int size_;
  int end_;
  T* data_;
};

} // namespace ft

#endif
