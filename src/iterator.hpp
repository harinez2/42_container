#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "iterator_base_types.hpp"

namespace ft {

// iterator
template<class Category,
         class T,
         class Distance = std::ptrdiff_t,
         class Pointer = T*,
         class Reference = T&>
struct iterator {
  typedef Category           iterator_category;
  typedef T                  value_type;
  typedef Distance           difference_type;
  typedef Pointer            pointer;
  typedef Reference          reference;
};

//-------------------------------------------------------------------------------
// normal iterator
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

//-------------------------------------------------------------------------------
// reverse iterator
template<typename Iterator>
class reverse_iterator
    : public iterator<typename iterator_traits<Iterator>::iterator_category,
                      typename iterator_traits<Iterator>::value_type,
                      typename iterator_traits<Iterator>::difference_type,
                      typename iterator_traits<Iterator>::pointer,
                      typename iterator_traits<Iterator>::reference> {
 protected:
  Iterator                                        current_;
  typedef iterator_traits<Iterator>               traits_type_;

 public:
  typedef Iterator                                iterator_type;
  typedef typename traits_type_::difference_type  difference_type;
  typedef typename traits_type_::pointer          pointer;
  typedef typename traits_type_::reference        reference;

  // constructor
  reverse_iterator() : current_() {}
  reverse_iterator(iterator_type x) : current_(x) {}
  template <class U>
  reverse_iterator(const reverse_iterator<U>& u) : current_(u.base()) {}

  // operator=
  template <class U>
  reverse_iterator& operator=(const reverse_iterator<U>& u) {
    if (this != u) {
      current_ = u.current_;
    }
    return *this;
  }

  // destructor
  ~reverse_iterator() {}

  // member funcs
  iterator_type base() const {
    return current_;
  }
  reference operator*() const {
    iterator_type tmp = current_;
    return *(--tmp);
  }
  pointer operator->() const {
    return &(operator*());
  }
  reverse_iterator& operator++() {
    --current_;
    return *this;
  }
  reverse_iterator operator++(int) {
    reverse_iterator tmp = *this;
    --current_;
    return tmp;
  }
  reverse_iterator& operator--() {
    ++current_;
    return *this;
  }
  reverse_iterator operator--(int) {
    reverse_iterator tmp = *this;
    ++current_;
    return tmp;
  }
  reverse_iterator operator+(difference_type n) const {
    return reverse_iterator(current_ - n);
 }
  reverse_iterator& operator+=(difference_type n) {
    current_ -= n;
    return *this;
  }
  reverse_iterator operator-(difference_type n) const {
    return reverse_iterator(current_ + n);
  }
  reverse_iterator& operator-=(difference_type n) {
    current_ += n;
    return *this;
  }
  reference operator[](difference_type n) const {
    return *(*this + n);
  }

};

template<typename Iterator>
bool operator==(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
{ return x.base() == y.base(); }

template<typename Iterator>
bool operator<(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
{ return y.base() < x.base(); }

template<typename Iterator>
bool operator!=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
{ return !(x == y); }

template<typename Iterator>
bool operator>(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
{ return y < x; }

template<typename Iterator>
bool operator<=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
{ return !(y < x); }

template<typename Iterator>
bool operator>=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
{ return !(x < y); }

template<typename Iterator>
typename reverse_iterator<Iterator>::difference_type operator-(
  const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
{ return y.base() - x.base(); }

template<typename Iterator>
reverse_iterator<Iterator>operator+(typename reverse_iterator<Iterator>::difference_type n,
  const reverse_iterator<Iterator>& x)
{ return reverse_iterator<Iterator>(x.base() - n); }

template<typename IteratorL, typename IteratorR>
bool operator==(const reverse_iterator<IteratorL>& x, const reverse_iterator<IteratorR>& y)
{ return x.base() == y.base(); }

template<typename IteratorL, typename IteratorR>
bool operator<(const reverse_iterator<IteratorL>& x, const reverse_iterator<IteratorR>& y)
{ return y.base() < x.base(); }

template<typename IteratorL, typename IteratorR>
bool operator!=(const reverse_iterator<IteratorL>& x, const reverse_iterator<IteratorR>& y)
{ return !(x == y); }

template<typename IteratorL, typename IteratorR>
bool operator>(const reverse_iterator<IteratorL>& x, const reverse_iterator<IteratorR>& y)
{ return y < x; }

template<typename IteratorL, typename IteratorR>
bool operator<=(const reverse_iterator<IteratorL>& x, const reverse_iterator<IteratorR>& y)
{ return !(y < x); }

template<typename IteratorL, typename IteratorR>
bool operator>=(const reverse_iterator<IteratorL>& x, const reverse_iterator<IteratorR>& y)
{ return !(x < y); }

template<typename IteratorL, typename IteratorR>
typename reverse_iterator<IteratorL>::difference_type operator-(
  const reverse_iterator<IteratorL>& x, const reverse_iterator<IteratorR>& y)
{ return y.base() - x.base(); }

} // namespace ft

#endif
