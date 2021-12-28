#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <algorithm>
#include <iterator>
#include <stdexcept>

#include <iostream> //TODO:remove
#include <limits> //TODO:remove

namespace ft {

template <typename T, typename Allocator = std::allocator<T> >
class vector {
 public:
  typedef T&                                    reference;
  typedef const T&                              const_reference;
  typedef T*                                    iterator; //TODO
  typedef const T*                              const_iterator; //TODO
  typedef std::size_t                           size_type;
  typedef std::ptrdiff_t                        difference_type;
  typedef T                                     value_type;
  typedef Allocator                             allocator_type;
  typedef typename Allocator::pointer           pointer;
  typedef typename Allocator::const_pointer     const_pointer;
  typedef std::reverse_iterator<iterator>       reverse_iterator; //TODO
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator; // TODO

  // constructors & destructor
  vector(const allocator_type& a = allocator_type())
      : alc(a), first_(NULL), last_(NULL), reserved_last_(NULL) {}

  vector(value_type n, const_reference v = value_type(), const allocator_type& a = allocator_type())
      : vector(a) {
    first_ = alc.allocate(n);
    last_ = first_ + n;
    reserved_last_ = first_ + n;
    for (size_type i = 0; i < n; ++i) {
      alc.construct(first_ + i, v);
    }
  }

  template <class InputIter>
  vector(InputIter first, InputIter last, const Allocator& a = Allocator())
      : vector(a) {
    reserve(std::distance(first, last));
    for (InputIter it = first; it != last; ++it)
      push_back(*it);
  }

  vector(const vector& rhs) : vector(rhs.alc) { *this = rhs; }

  vector& operator=(const vector& rhs) {
    if (this != &rhs) {
      // if (size() == rhs.size()) {
      //   for (const_iterator it = rhs.begin(); it != rhs.end(); ++it)
      //     push_back(*it);
      // }
      clear();
      reserve(std::distance(rhs.first_, rhs.last_));
      for (const_iterator it = rhs.begin(); it != rhs.end(); ++it)
        push_back(*it);
    }
    return *this;
  }

  ~vector() {
    clear();
    alc.deallocate(first_, capacity());
  }

  // iterator
  iterator begin() { return first_; }
  iterator end()   { return last_;  }
  const_iterator begin() const { return first_; }
  const_iterator end()   const { return last_;  }
  reverse_iterator rbegin() { return reverse_iterator{ last_  }; }
  reverse_iterator rend()   { return reverse_iterator{ first_ }; }
  const_reverse_iterator rbegin() const { return const_reverse_iterator{ last_  }; }
  const_reverse_iterator rend()   const { return const_reverse_iterator{ first_ }; }

  // area
  size_type size() const { return std::distance(first_, last_); }
  size_type max_size() const { return alc.max_size(); }
  void resize(size_type sz, value_type c = value_type()) {
    if (sz < size())
      erase(begin() + sz, end());
    else if (sz > size()) {
      reserve(sz);
      iterator it = last_;
      for (size_type i = 0; i < sz - size(); ++i, ++it)
        *it = c;
      last_ = it;
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

    value_type* tmp_first_ = alc.allocate(n);
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
  reference       front()       { return *begin(); }
  const_reference front() const { return *begin(); }
  reference       back()       { return *(end() - 1); }
  const_reference back() const { return *(end() - 1); }

  // changing container elements
  // template <class InputIterator>
  // void assign(InputIterator first, InputIterator last) {
    // size_type inputitr_size = std::distance(first, last);
    // if (inputitr_size < this->size()) {
    //   std::copy(first, last, begin());
    //   destroy_until(rend() - inputitr_size);
    // }
    // else {
    //   InputIterator it = first;
    //   std::advance(it, inputitr_size);
    //   std::copy(first, it, begin());
    //   insert(end(), it, last);
    // }
  // }
  void assign(size_type n, const_reference u) {
    if (n > capacity()) {
      value_type* tmp_first_ = alc.allocate(n);
      std::uninitialized_fill(tmp_first_, tmp_first_ + n, u);
      destroy_until(rend());
      alc.deallocate(begin(), capacity());
      first_ = tmp_first_;
      last_ = tmp_first_ + n;
      reserved_last_ = tmp_first_ + n;
    } else if (n > size()) {
      std::fill(begin(), end(), u);
      std::uninitialized_fill(end(), end() + n - size(), u);
      last_ += n - size();
    } else {
      std::fill_n(begin(), n, u);
      destroy_until(rbegin() + size() - n);
    }
  }
  void push_back(const_reference x) {
    if (last_ == reserved_last_) {
      if (size() == 0)
        reserve(default_size_);
      else
        reserve(size() * 2);
    }
    alc.construct(first_ + size(), x);
    ++last_;
  }
  void pop_back() {
    if (empty() == true)
      return;
    --last_;
  }
  iterator insert(iterator position, const_reference x) {
    insert(position, 1, x);
    return position;
  }
  void insert(iterator position, size_type n, const_reference x) {
    reserve(n);
    iterator it_from = end() - 1;
    iterator it_to = position + n;
    for (; it_from != position; --it_from) {
      *it_to = *it_from;
      --it_to;
    }
    *it_to = *it_from;
    for (size_type i = 0; i < n; ++i) {
      *(position + i) = x;
    }
    last_ += n;
  }
  template <class InputIterator>
  void insert(iterator position, InputIterator first, InputIterator last) {
    size_type n = std::distance(first, last);
    reserve(n);
    iterator it_from = end() - 1;
    iterator it_to = position + n;
    for (; it_from != position; --it_from) {
      *it_to = *it_from;
      --it_to;
    }
    *it_to = *it_from;
    for (size_type i = 0; i < n; ++i) {
      *(position + i) = *first;
      ++first;
    }
    last_ += n;
  }
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
      value_type* new_last_ = it_prev;
      while (it_prev != end()) {
        alc.destroy(it_prev++);
      }
      last_ = new_last_;
    }
    return it_ret;
  }
  void swap(vector& x) {
    if (capacity() < x.size())
      reserve(x.size());
    if (x.capacity() < size())
      x.reserve(size());
    int flg_end = 0;
    iterator it = begin();
    iterator it_rhs = x.begin();
    while (true) {
      if (it != end() && it_rhs != end()) {
        value_type tmp = *it;
        *it = *it_rhs;
        *it_rhs = tmp;
        ++it;
        ++it_rhs;
      } else if (it != end()) {
        *it_rhs = *it;
        if (flg_end == 0) {
          flg_end = 1;
          last_ = it;
        }
      } else if (it_rhs != end()) {
        *it = *it_rhs;
        if (flg_end == 0) {
          flg_end = 2;
          x.last_ = it_rhs;
        }
      } else
        break;
    }
    if (flg_end == 1)
      x.last_ = it_rhs;
    else if (flg_end == 2)
      last_ = it;
  }
  void clear() { destroy_until(rend()); }

  // allocator
  allocator_type get_allocator() const {}

  // compare operator
  bool operator==(const_reference rhs) {
    iterator it_lhs = begin();
    iterator it_rhs = rhs.begin();
    for (; it_lhs != end() && it_rhs != rhs.end(); ++it_lhs, ++it_rhs) {
      if (*this == *rhs)
        continue;
      else
        return false;
    }
    return (it_lhs == end() && it_rhs == rhs.end()) ? true : false;
  }
  bool operator!=(const_reference rhs) { return !(this == rhs); }
  bool operator<(const vector& rhs) {
    iterator it_lhs = begin();
    iterator it_rhs = rhs.begin();
    for (; it_lhs != end() && it_rhs != rhs.end(); ++it_lhs, ++it_rhs) {
      if (*this < *rhs)
        continue;
      else
        return false;
    }
    return (it_lhs == end() && it_rhs == rhs.end()) ? true : false;
  }
  bool operator<=(const vector& rhs) { return this < rhs || this == rhs; }
  bool operator>(const vector& rhs)  { return !(this <= rhs); }
  bool operator>=(const vector& rhs) { return this > rhs || this == rhs; }

 private:
  static const int default_size_ = 1;
  Allocator alc;
  value_type* first_;
  value_type* last_;
  value_type* reserved_last_;

  void destroy_until(reverse_iterator rend) {
    for (reverse_iterator it = rbegin(); it != rend; ++it, --last_)
      alc.destroy(&*it);
  }
};

// swap
// swap();

} // namespace ft

#endif
