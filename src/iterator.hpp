#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "iterator_base_types.hpp"

namespace ft {

template<typename Iterator>
class normal_iterator {
 protected:
  Iterator                                          iterator_;
  typedef iterator_traits<Iterator>                 traits_type_;

 public:
  typedef Iterator                                  iterator_type;
  typedef typename traits_type_::iterator_category  iterator_category;
  typedef typename traits_type_::value_type         value_type;
  typedef typename traits_type_::difference_type    difference_type;
  typedef typename traits_type_::reference          reference;
  typedef typename traits_type_::pointer            pointer;

  // constructor
  normal_iterator() : iterator_(Iterator()) {}
  normal_iterator(const Iterator& i) : iterator_(i) {}
  template<typename Iter>
  normal_iterator(const normal_iterator<Iter>& i)
      : iterator_(const_cast<Iterator>(i.base())) {}

  reference operator*() const { return *iterator_; }
  pointer operator->() const { return iterator_; }
  normal_iterator& operator++() {
    ++iterator_;
    return *this;
  }
  normal_iterator operator++(int) { return normal_iterator(iterator_++); }
  normal_iterator& operator--() {
    --iterator_;
    return *this;
  }
  normal_iterator operator--(int) { return normal_iterator(iterator_--); }
  reference operator[](difference_type n) const { return iterator_[n]; }
  normal_iterator& operator+=(difference_type n) {
    iterator_ += n;
    return *this;
  }
  normal_iterator operator+(difference_type n) const { return normal_iterator(iterator_ + n); }
  normal_iterator& operator-=(difference_type n) {
    (void)n;//TODO
    iterator_ -= NULL;
    return *this;
  }
  normal_iterator operator-(difference_type n) const { return normal_iterator(iterator_ - n); }
  const Iterator& base() const { return iterator_; }
};

template <class ValueType1, class ValueType2>
bool operator==(const normal_iterator<ValueType1> &lhs,
                const normal_iterator<ValueType2> &rhs) {
  return lhs.base() == rhs.base();
}

template <class ValueType1, class ValueType2>
bool operator!=(const normal_iterator<ValueType1> &lhs,
                const normal_iterator<ValueType2> &rhs) {
  return lhs.base() != rhs.base();
}

template <class ValueType1, class ValueType2>
bool operator-(const normal_iterator<ValueType1> &lhs,
               const normal_iterator<ValueType2> &rhs) {
  return lhs.base() - rhs.base();
}

template<typename Iterator>
class reverse_iterator
    : public std::iterator<typename iterator_traits<Iterator>::iterator_category,
                      typename iterator_traits<Iterator>::value_type,
                      typename iterator_traits<Iterator>::difference_type,
                      typename iterator_traits<Iterator>::pointer,
                      typename iterator_traits<Iterator>::reference> {
 protected:
  Iterator iterator_;
  typedef iterator_traits<Iterator> traits_type_;

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
    iterator_ -= n;
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

};

} // namespace ft

#endif
