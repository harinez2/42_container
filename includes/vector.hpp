#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <stdexcept>
#include <iterator>
#include <sstream>

#include "algorithm.hpp"
#include "iterator_base_types.hpp"
#include "iterator.hpp"
#include "type_traits.hpp"

namespace ft {

template <typename T, typename Allocator = std::allocator<T> >
class vector {
 public:
  typedef T&                                         reference;
  typedef const T&                                   const_reference;
  typedef std::size_t                                size_type;
  typedef std::ptrdiff_t                             difference_type;
  typedef T                                          value_type;
  typedef Allocator                                  allocator_type;
  typedef typename allocator_type::pointer           pointer;
  typedef typename allocator_type::const_pointer     const_pointer;
  typedef ft::normal_iterator<pointer, vector>       iterator;
  typedef ft::normal_iterator<const_pointer, vector> const_iterator;
  typedef ft::reverse_iterator<iterator>             reverse_iterator;
  typedef ft::reverse_iterator<const_iterator>       const_reverse_iterator;

  // constructor (1)
  explicit vector(const allocator_type& a = allocator_type())
      : alc_(a), first_(NULL), last_(NULL), reserved_last_(NULL) {}

  // constructor (2)
  explicit vector(size_type n, const value_type v = value_type(), const allocator_type& a = allocator_type())
      : vector(a) {
    first_ = alc_.allocate(n);
    last_ = first_ + n;
    reserved_last_ = first_ + n;
    std::uninitialized_fill(first_, first_ + n, v);
  }

  // constructor (3)
  template <class InputIter>
  vector(InputIter first, 
      typename ft::enable_if<!ft::is_integral<InputIter>::value, InputIter>::type last,
      const allocator_type& a = allocator_type())
      : vector(a) {
    reserve(std::distance(first, last));
    for (InputIter it = first; it != last; ++it)
      push_back(*it);
  }

  // constructor (4)
  vector(const vector& rhs) : vector(rhs.alc_) { *this = rhs; }

  vector& operator=(const vector& rhs) {
    if (this != &rhs) {
      clear();
      reserve(std::distance(rhs.first_, rhs.last_));
      for (const_iterator it = rhs.begin(); it != rhs.end(); ++it)
        push_back(*it);
    }
    return *this;
  }

  // destructor
  ~vector() {
    clear();
    alc_.deallocate(first_, capacity());
  }

  // iterator
  iterator begin() { return iterator(first_); }
  iterator end()   { return iterator(last_);  }
  const_iterator begin() const { return const_iterator(first_); }
  const_iterator end()   const { return const_iterator(last_);  }
  reverse_iterator rbegin() { return reverse_iterator(last_); }
  reverse_iterator rend()   { return reverse_iterator(first_); }
  const_reverse_iterator rbegin() const { return const_reverse_iterator(last_); }
  const_reverse_iterator rend()   const { return const_reverse_iterator(first_); }

  // area
  size_type size() const {
    if (first_ == NULL)
      return 0;
    else
      return std::distance(first_, last_);
  }
  size_type max_size() const { return alc_.max_size(); }
  void resize(size_type sz, value_type c = value_type()) {
    if (sz < size())
      erase(begin() + sz, end());
    else if (sz > size()) {
      reserve(sz);
      std::fill_n(last_, sz - size(), c);
      last_ += sz - size();
    }
  }
  size_type capacity() const {
    if (first_ == NULL)
      return 0;
    else
      return std::distance(first_, reserved_last_);
  }
  bool empty() const { return first_ == last_; }
  void reserve(size_type n) {
    if (n > max_size())
      throw std::length_error("vector::reserve");
    if (n <= capacity())
      return;

    pointer tmp_first_ = alc_.allocate(n);
    size_type data_size = size();
    if (first_ != NULL) {
      std::uninitialized_copy(first_, first_ + data_size, tmp_first_);
      destroy_until_(rend());
      alc_.deallocate(first_, capacity());
    }
    first_ = tmp_first_;
    last_ = first_ + data_size;
    reserved_last_ = first_ + n;
  }

  // elements access
  reference       operator[](size_type n)       { return *(first_ + n); }
  const_reference operator[](size_type n) const { return *(first_ + n); }
  reference at(size_type n) {
    if (size() <= n) {
      std::ostringstream oss_n;
      oss_n << n;
      std::ostringstream oss_size;
      oss_size << size();
      throw std::out_of_range(
        "vector::_M_range_check: __n (which is " + oss_n.str() +
        ") >= this->size() (which is " + oss_size.str() + ")");
    }
    return *(first_ + n);
  }
  const_reference at(size_type n) const {
    if (size() <= n) {
      std::ostringstream oss_n;
      oss_n << n;
      std::ostringstream oss_size;
      oss_size << size();
      throw std::out_of_range(
        "vector::_M_range_check: __n (which is " + oss_n.str() +
        ") >= this->size() (which is " + oss_size.str() + ")");
    }
    return *(first_ + n);
  }
  pointer data() {
    return first_;
  }
  const_pointer data() const {
    return first_;
  }
  reference       front()       { return *begin(); }
  const_reference front() const { return *begin(); }
  reference       back()       { return *(end() - 1); }
  const_reference back() const { return *(end() - 1); }

  // changing container elements
  template <class InputIterator>
  void assign(InputIterator first,
      typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
    size_type inputitr_size = std::distance(first, last);
    if (inputitr_size == this->size()) {
      std::copy(first, last, begin());
    } else if (inputitr_size < this->size()) {
      std::copy(first, last, begin());
      destroy_until_(rend() - inputitr_size);
    } else {
      size_type n = std::distance(first, last);
      reserve(n);
      std::copy(first, last, begin());
      last_ = first_ + n;
    }
  }
  void assign(size_type n, const_reference u) {
    if (n > capacity()) {
      pointer tmp_first_ = alc_.allocate(n);
      std::uninitialized_fill(tmp_first_, tmp_first_ + n, u);
      if (first_ != NULL) {
        destroy_until_(rend());
        alc_.deallocate(first_, capacity());
      }
      first_ = tmp_first_;
      last_ = tmp_first_ + n;
      reserved_last_ = tmp_first_ + n;
    } else if (n > size()) {
      std::fill(begin(), end(), u);
      std::uninitialized_fill(end(), end() + n - size(), u);
      last_ += n - size();
    } else {
      std::fill_n(begin(), n, u);
      destroy_until_(rbegin() + size() - n);
    }
  }
  void push_back(const_reference x) {
    if (last_ != reserved_last_) {
      alc_.construct(first_ + size(), x);
      ++last_;
    } else {
      realloc_insert_(end(), 1, x);
    }
  }
  void pop_back() {
    --last_;
    alc_.destroy(last_);
  }
  iterator insert(iterator position, const_reference x) {
    if (last_ != reserved_last_ && position == end()) {
      alc_.construct(last_, x);
      ++last_;
    } else if (last_ != reserved_last_) {
      make_insert_space_backward_(position, 1);
      std::fill_n(position, 1, x);
    } else {
      realloc_insert_(position, 1, x);
    }
    return position;
  }
  void insert(iterator position, size_type n, const_reference x) {
    if (n == 0)
      return;
    if (reserved_last_ - last_ >= n) {
      make_insert_space_backward_(position, n);
      std::fill_n(position, n, x);
    } else {
      realloc_insert_(position, n, x);
    }
  }
  template <class InputIterator>
  void insert(iterator position, InputIterator first,
      typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
    size_type n = std::distance(first, last);
    if (n == 0)
      return;
    if (reserved_last_ - last_ >= n) {
      make_insert_space_backward_(position, n);
      std::copy(first, last, position);
    } else {
      const size_type new_len = get_new_allocate_size_(n, "vector::realloc_insert_");
      const size_type elems_before = &*position - first_;

      pointer new_first = alc_.allocate(new_len);
      pointer new_last = new_first;
      try {
        std::uninitialized_copy(begin(), position, new_first);
        std::uninitialized_copy(first, last, new_first + elems_before);
        std::uninitialized_copy(position, end(), new_first + elems_before + n);
        new_last = new_first + size() + n;
      } catch(...) {//TODO
        destroy_until_(reverse_iterator(new_first));
        alc_.deallocate(new_first, new_len);
      }
      destroy_until_(rend());
      alc_.deallocate(first_, capacity());
      first_ = new_first;
      last_ = new_last;
      reserved_last_ = new_first + new_len;
    }
  }
  iterator erase(iterator position) {
    return erase(position, position + 1);
  }
  iterator erase(iterator first, iterator last) {
    if (first != last) {
      if (last != end())
        copy_foreward_(last, end(), first);
      destroy_until_(rbegin() + std::distance(&*first, &*last));
    }
    return first;
  }
  void swap(vector& x) {
    swap_(first_, x.first_);
    swap_(last_, x.last_);
    swap_(reserved_last_, x.reserved_last_);
  }
  void clear() { destroy_until_(rend()); }

  // allocator
  allocator_type get_allocator() const { return alc_; }

 private:
  Allocator alc_;
  pointer first_;
  pointer last_;
  pointer reserved_last_;

  void swap_(pointer& x, pointer& y) {
    pointer tmp = x;
    x = y;
    y = tmp;
  }
  void destroy_until_(reverse_iterator rend) {
    for (reverse_iterator it = rbegin(); it != rend; ++it, --last_)
      alc_.destroy(&*it);
  }
  size_type get_new_allocate_size_(size_type n, std::string errmsg) const {
    if (max_size() - size() < n)
      throw std::length_error(errmsg);
    
    const size_type len_ = size() + std::max(size(), n);
    return len_ > max_size() ? max_size() : len_;
  }
  void copy_foreward_(iterator first, iterator last, iterator result_begin) {
    for (iterator it = first; it != last; ++it) {
      *result_begin = *it;
      ++result_begin;
    }
  }
  void copy_backward_(iterator first, iterator last, iterator result_end) {
    for (iterator it = last - 1; it != first - 1; --it) {
      *result_end = *it;
      --result_end;
    }
  }
  void make_insert_space_backward_(iterator position, size_type n) {
    for (size_type i = 0; i < n; ++i) {
      alc_.construct(last_ + i, *(end() - n + i));
    }
    copy_backward_(position, end() - n, end() - 1);
    last_ += n;
  }
  void realloc_insert_(iterator position, size_type n, const_reference x) {
    const size_type new_len = get_new_allocate_size_(n, "vector::realloc_insert_");
    const size_type elems_before = &*position - first_;

    pointer new_first = alc_.allocate(new_len);
    pointer new_last = new_first;
    try {
      std::uninitialized_copy(begin(), position, new_first);
      std::uninitialized_fill(new_first + elems_before, new_first + elems_before + n, x);
      std::uninitialized_copy(position, end(), new_first + elems_before + n);
      new_last = new_first + size() + n;
    } catch(...) {//TODO
      destroy_until_(reverse_iterator(new_first));
      alc_.deallocate(new_first, new_len);
    }
    destroy_until_(rend());
    alc_.deallocate(first_, capacity());
    first_ = new_first;
    last_ = new_last;
    reserved_last_ = new_first + new_len;
  }
};

// compare operator
template <class T, class Allocator>
bool operator==(const vector<T, Allocator>& x, const vector<T, Allocator>& y) {
  return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
}
template <class T, class Allocator>
bool operator!=(const vector<T, Allocator>& x,const vector<T, Allocator>& y) {
  return !(x == y);
}
template <class T, class Allocator>
bool operator<(const vector<T, Allocator>& x, const vector<T, Allocator>& y) {
  return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}
template <class T, class Allocator>
bool operator<=(const vector<T, Allocator>& x, const vector<T, Allocator>& y) {
  return !(y < x);
}
template <class T, class Allocator>
bool operator>(const vector<T, Allocator>& x, const vector<T, Allocator>& y) {
  return y < x;
}
template <class T, class Allocator>
bool operator>=(const vector<T, Allocator>& x, const vector<T, Allocator>& y) {
  return !(x < y);
}

template <class T, class Allocator>
void swap(vector<T, Allocator>& x, vector<T, Allocator>& y) {
  x.swap(y);
}

} // namespace ft

#endif
