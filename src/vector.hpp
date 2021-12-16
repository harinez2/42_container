#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <stdexcept>

namespace ft {

template <typename T, typename Allocator = std::allocator<T> >
class vector {
 public:
  typedef T& reference;
  typedef const T& const_reference;
  typedef T* iterator;
  typedef const T* const_iterator;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef typename Allocator::pointer pointer;
  typedef typename Allocator::const_pointer const_pointer;
  typedef std::reverse_iterator<iterator> reverse_iterator; //TODO
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator; // TODO

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

  iterator begin() { return first_; }
  iterator end()   { return last_;  }
  const_iterator begin() const { return first_; }
  const_iterator end()   const { return last_;  }
  reverse_iterator rbegin() { return last_;  }
  reverse_iterator rend()   { return first_; }
  const_reverse_iterator rbegin() const { return last_;  }
  const_reverse_iterator rend()   const { return first_; }

  size_type size() const { return std::distance(first_, last_); }
  size_type max_size() const { return alc.max_size(); }
  // void resize(size_type sz, T c = T()) {}
  size_type capacity() const { return std::distance(first_, reserved_last_); }
  bool empty() const { return first_ == last_; }
  void reserve(size_type n) {
    if (n > max_size())
      std::length_error("reserve() failed : the specified size is bigger than max_size().");
    if (n <= capacity())
      return;
    T* tmp_first_ = alc.allocate(n);
    size_type data_size = size();
    for (size_type i = 0; i < data_size; ++i) {
      alc.construct(tmp_first_ + i, first_[i]);
      alc.destroy(first_ + i);
    }
    alc.deallocate(first_, data_size);
    first_ = tmp_first_;
    last_ = first_ + data_size;
    reserved_last_ = first_ + n;
  }

  T& operator[](size_type n)             { return first_[n]; }
  const T& operator[](size_type n) const { return first_[n]; }
  T&       at(size_type n) {
    if (n < 0 || size() <= n)
      throw std::exception();
    return first_[n];
  }
  const T& at(size_type n) const {
    if (n < 0 || size() <= n)
      throw std::exception();
    return first_[n];
  }
  T&       front()       { return first_; }
  const T& front() const { return first_; }
  T&       back()       { T* end = last_; --end; return end; }
  const T& back() const { T* end = last_; --end; return end; }

  // template <class InputIterator>
  // void assign(InputIterator first, InputIterator last) {}
  // void assign(size_type n, const T& u) {}
  void push_back(const T& x) {
    if (last_ == reserved_last_) {
      //reallocate
    }
    alc.construct(first_ + size(), x);
    ++last_;
  }
  void pop_back() {
    if (empty() == true)
      return;
    --last_;
  }
  // iterator insert(iterator position, const T& x) {}
  // void insert(iterator position, size_type n, const T& x) {}
  // template <class InputIterator>
  // void insert(iterator position, InputIterator first, InputIterator last) {}
  iterator erase(iterator position) {
    return erase(position, position);
  }
  iterator erase(iterator first, iterator last) {
    bool flg_found = false;
    iterator it_prev;
    iterator it_ret = end();
    for (iterator it = begin(); it != end(); ) {
      if (it == first) {
        flg_found = true;
        it_ret = it;
        it_prev = it;
        while (it != last && it != end())
          ++it;
        if (it == end())
          continue;
      }
      else if (flg_found == true) {
        *it_prev = *it;
        ++it_prev;
      }
      ++it;
    }
    if (flg_found == true) {
      T* new_last_ = it_prev;
      while (it_prev != end()) {
        alc.destroy(it_prev++);
      }
      last_ = new_last_;
    }
    return it_ret;
  }
  // void swap(vector& x) {}
  // void clear() {}

  allocator_type get_allocator() const {}

 private:
  static const int default_size_ = 8;
  Allocator alc;
  T* first_;
  T* last_;
  T* reserved_last_;
};

// ft::vector& std::operator==(const ft::vector& lhs, const ft::vector& rhs) {};
// ft::vector& std::operator!=(const ft::vector& lhs, const ft::vector& rhs) {};
// ft::vector& std::operator<(const ft::vector& lhs, const ft::vector& rhs) {};
// ft::vector& std::operator<=(const ft::vector& lhs, const ft::vector& rhs) {};
// ft::vector& std::operator>(const ft::vector& lhs, const ft::vector& rhs) {};
// ft::vector& std::operator>=(const ft::vector& lhs, const ft::vector& rhs) {};

// swap();

} // namespace ft

#endif
