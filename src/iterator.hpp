#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "iterator_base_types.hpp"

namespace ft {

template<typename Iterator>
class reverse_iterator
    : public iterator<typename iterator_traits<Iterator>::iterator_category,
                      typename iterator_traits<Iterator>::value_type,
                      typename iterator_traits<Iterator>::difference_type,
                      typename iterator_traits<Iterator>::pointer,
                      typename iterator_traits<Iterator>::reference> {
 public:
  typedef Iterator                                iterator_type;
  typedef typename traits_type_::difference_type  difference_type;
  typedef typename traits_type_::pointer          pointer;
  typedef typename traits_type_::reference        reference;

  // constructor
  reverse_iterator() {}
  reverse_iterator(iterator_type x) : iterator_(x) {}
  template <class U>
  reverse_iterator(const reverse_iterator<U>& u) { *this = u; }

  // operator=
  template <class U>
  reverse_iterator& operator=(const reverse_iterator<U>& u) {
    if (this != u) {
      iterator_ = u.iterator_;
    }
    return *this;
  }

  // destructor
  ~reverse_iterator() {}

  // member funcs
  iterator_type base() const { return iterator_; }
  reference operator*() const {
    iterator_type tmp = iterator_;
    return *(--tmp);
  }
  pointer operator->() const { return operator*(); }
  reverse_iterator& operator++() {
    --iterator_;
    return *this;
  }
  reverse_iterator operator++(int) {
    reverse_iterator tmp = *this;
    --iterator_;
    return tmp;
  }
  reverse_iterator& operator--() {
    ++iterator_;
    return *this;
  }
  reverse_iterator operator--(int) {
    reverse_iterator tmp = *this;
    ++iterator_;
    return tmp;
  }
  reverse_iterator operator+(difference_type n) const {
    return reverse_iterator(iterator_ - n);
 }
  reverse_iterator& operator+=(difference_type n) {
    iterator -= n;
    return *this;
  }
  reverse_iterator operator-(difference_type n) const {
    return reverse_iterator(iterator_ + n);
  }
  reverse_iterator& operator-=(difference_type n) {
    iterator_ += n;
    return *this;
  }
  reference operator[](difference_type n) const { return *(*this + n); }

 protected:
  Iterator iterator_;

  typedef iterator_traits<Iterator> traits_type_;
};

} // namespace ft

#endif
