#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

namespace ft {

template <typename T, typename Allocator = std::allocator<T> >
class vector {
 public:
  vector() : size_(default_size_), end_(0) {
    // alc = Allocator();
    data_ = alc.allocate(default_size_);
    size_ = default_size_;
  }

  vector(const vector& rhs) { *this = rhs; }

  vector& operator=(const vector& rhs) {
    if (this != &rhs) {
    }
    return *this;
  }

  ~vector() {
    for (std::size_t i = 0; i != end_; ++i)
      alc.destroy(data_ + i);
    alc.deallocate(data_, size_);
  }

  void push_back(const T& var) {
    if (end_ == size_) {
      //reallocate
    }
    alc.construct(data_ + end_++, var);
  }

  T& operator[](std::size_t idx) const {
    if (idx < 0 || size_ <= idx)
      throw std::exception();
    return data_[idx];
  }

  // typename T::iterator begin() { return data_; }
  // typename T::iterator end() { return data_ + end_; }
  std::size_t size() { return end_; }

 private:
  static const int default_size_ = 8;
  Allocator alc;
  std::size_t size_;
  std::size_t end_;
  T* data_;
};

} // namespace ft

#endif
