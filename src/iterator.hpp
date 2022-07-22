#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "iterator_base_types.hpp"
#include "type_traits.hpp"

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
template<typename Iterator, typename Container>
class normal_iterator {
 protected:
  Iterator                                          current_;
  typedef iterator_traits<Iterator>                 traits_type_;

 public:
  typedef Iterator                                  iterator_type;
  typedef typename traits_type_::iterator_category  iterator_category;
  typedef typename traits_type_::value_type         value_type;
  typedef typename traits_type_::difference_type    difference_type;
  typedef typename traits_type_::pointer            pointer;
  typedef typename traits_type_::reference          reference;

  // constructor
  normal_iterator() : current_(Iterator()) {}
  normal_iterator(const Iterator& i) : current_(i) {}
  template<typename Iter>
  normal_iterator(const normal_iterator<Iter>& i)
      : current_(const_cast<Iterator>(i.base())) {}

  // Allow iterator to const_iterator conversion
  template<typename Iter>
  normal_iterator(const normal_iterator<Iter,
      typename ft::enable_if<
          (std::__are_same<Iter, typename Container::pointer>::__value),
          Container>::__type>& i)
      : current_(i.base()) { }

  // Forward iterator requirements
  reference operator*() const {
    return *current_;
  }
  pointer operator->() const {
    return current_;
  }
  normal_iterator& operator++() {
    ++current_;
    return *this;
  }
  normal_iterator operator++(int) {
    return normal_iterator(current_++);
  }
  normal_iterator& operator--() {
    --current_;
    return *this;
  }
  normal_iterator operator--(int) {
    return normal_iterator(current_--);
  }

  // Random access iterator requirements
  reference operator[](const difference_type& n) const {
    return current_[n];
  }
  normal_iterator& operator+=(const difference_type& n) {
    current_ += n;
    return *this;
  }
  normal_iterator operator+(const difference_type& n) const {
    return normal_iterator(current_ + n);
  }
  normal_iterator& operator-=(const difference_type& n) {
    current_ -= n;
    return *this;
  }
  normal_iterator operator-(const difference_type& n) const {
    return normal_iterator(current_ - n);
  }
  const Iterator& base() const {
    return current_;
  }
};

// Forward iterator requirements
template<typename IteratorL, typename IteratorR, typename Container>
bool operator==(const normal_iterator<IteratorL, Container>& lhs,
    const normal_iterator<IteratorR, Container>& rhs) {
  return lhs.base() == rhs.base();
}

template<typename Iterator, typename Container>
bool operator==(const normal_iterator<Iterator, Container>& lhs,
    const normal_iterator<Iterator, Container>& rhs) {
  return lhs.base() == rhs.base();
}

template<typename IteratorL, typename IteratorR, typename Container>
bool operator!=(const normal_iterator<IteratorL, Container>& lhs,
    const normal_iterator<IteratorR, Container>& rhs) {
  return lhs.base() != rhs.base();
}

template<typename Iterator, typename Container>
bool operator!=(const normal_iterator<Iterator, Container>& lhs,
    const normal_iterator<Iterator, Container>& rhs) {
  return lhs.base() != rhs.base();
}

// Random access iterator requirements
template<typename IteratorL, typename IteratorR, typename Container>
bool operator<(const normal_iterator<IteratorL, Container>& lhs,
    const normal_iterator<IteratorR, Container>& rhs) {
  return lhs.base() < rhs.base();
}

template<typename Iterator, typename Container>
bool operator<(const normal_iterator<Iterator, Container>& lhs,
    const normal_iterator<Iterator, Container>& rhs) {
  return lhs.base() < rhs.base();
}

template<typename IteratorL, typename IteratorR, typename Container>
bool operator>(const normal_iterator<IteratorL, Container>& lhs,
    const normal_iterator<IteratorR, Container>& rhs) {
  return lhs.base() > rhs.base();
}

template<typename Iterator, typename Container>
bool operator>(const normal_iterator<Iterator, Container>& lhs,
    const normal_iterator<Iterator, Container>& rhs) {
  return lhs.base() > rhs.base();
}

template<typename IteratorL, typename IteratorR, typename Container>
bool operator<=(const normal_iterator<IteratorL, Container>& lhs,
    const normal_iterator<IteratorR, Container>& rhs) {
  return lhs.base() <= rhs.base();
}

template<typename Iterator, typename Container>
bool operator<=(const normal_iterator<Iterator, Container>& lhs,
    const normal_iterator<Iterator, Container>& rhs) {
  return lhs.base() <= rhs.base();
}

template<typename IteratorL, typename IteratorR, typename Container>
bool operator>=(const normal_iterator<IteratorL, Container>& lhs,
    const normal_iterator<IteratorR, Container>& rhs) {
  return lhs.base() >= rhs.base();
}

template<typename Iterator, typename Container>
bool operator>=(const normal_iterator<Iterator, Container>& lhs,
    const normal_iterator<Iterator, Container>& rhs) {
  return lhs.base() >= rhs.base();
}

template<typename IteratorL, typename IteratorR, typename Container>
typename normal_iterator<IteratorL, Container>::difference_type operator-(
    const normal_iterator<IteratorL, Container>& lhs,
    const normal_iterator<IteratorR, Container>& rhs) {
  return lhs.base() - rhs.base();
}

template<typename Iterator, typename Container>
typename normal_iterator<Iterator, Container>::difference_type operator-(
    const normal_iterator<Iterator, Container>& lhs,
    const normal_iterator<Iterator, Container>& rhs) {
  return lhs.base() - rhs.base();
}

template<typename Iterator, typename Container>
normal_iterator<Iterator, Container> operator+(
    typename normal_iterator<Iterator, Container>::difference_type n,
    const normal_iterator<Iterator, Container>& i) {
  return normal_iterator<Iterator, Container>(i.base() + n);
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

  // Forward iterator requirements
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

  // Random access iterator requirements
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
  iterator_type base() const {
    return current_;
  }

};

template<typename Iterator>
bool operator==(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y) {
  return x.base() == y.base();
}

template<typename Iterator>
bool operator<(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y) {
  return y.base() < x.base();
}

template<typename Iterator>
bool operator!=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y) {
  return !(x == y);
}

template<typename Iterator>
bool operator>(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y) {
  return y < x;
}

template<typename Iterator>
bool operator<=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y) {
  return !(y < x);
}

template<typename Iterator>
bool operator>=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y) {
  return !(x < y);
}

template<typename Iterator>
typename reverse_iterator<Iterator>::difference_type operator-(
    const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y) {
  return y.base() - x.base();
}

template<typename Iterator>
reverse_iterator<Iterator>operator+(typename reverse_iterator<Iterator>::difference_type n,
    const reverse_iterator<Iterator>& x) {
  return reverse_iterator<Iterator>(x.base() - n);
}

template<typename IteratorL, typename IteratorR>
bool operator==(const reverse_iterator<IteratorL>& x, const reverse_iterator<IteratorR>& y) {
  return x.base() == y.base();
}

template<typename IteratorL, typename IteratorR>
bool operator<(const reverse_iterator<IteratorL>& x, const reverse_iterator<IteratorR>& y) {
  return y.base() < x.base();
}

template<typename IteratorL, typename IteratorR>
bool operator!=(const reverse_iterator<IteratorL>& x, const reverse_iterator<IteratorR>& y) {
  return !(x == y);
}

template<typename IteratorL, typename IteratorR>
bool operator>(const reverse_iterator<IteratorL>& x, const reverse_iterator<IteratorR>& y) {
  return y < x;
}

template<typename IteratorL, typename IteratorR>
bool operator<=(const reverse_iterator<IteratorL>& x, const reverse_iterator<IteratorR>& y) {
  return !(y < x);
}

template<typename IteratorL, typename IteratorR>
bool operator>=(const reverse_iterator<IteratorL>& x, const reverse_iterator<IteratorR>& y) {
  return !(x < y);
}

template<typename IteratorL, typename IteratorR>
typename reverse_iterator<IteratorL>::difference_type operator-(
    const reverse_iterator<IteratorL>& x, const reverse_iterator<IteratorR>& y) {
  return y.base() - x.base();
}

} // namespace ft

#endif
