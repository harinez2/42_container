#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <functional>

namespace ft {

template <
      class Key,
      class T,
      class Compare = std::less<Key>,
      class Allocator = std::allocator<std::pair<const Key, T> >
>
class map {
 public:
  typedef Key                                    key_type;
  typedef std::pair<const Key, T>                value_type;
  typedef T                                      mapped_type;
  typedef Compare                                key_compare;
  typedef xx                                     value_compare;
  typedef Allocator                              allocator_type;
  typedef value_type&                            reference;
  typedef const value_type&                      const_reference;
  typedef xx                                     iterator;
  typedef xx                                     const_iterator;
  typedef size_t                                 size_type;
  typedef ptrdiff_t                              difference_type;
  typedef typename Allocator::pointer            pointer;
  typedef typename Allocator::const_pointer      const_pointer;
  typedef std::reverse_iterator<iterator>        reverse_iterator;
  typedef std::reverse_iterator<const_iterator>  const_reverse_iterator;

  // constructor
  map(const Compare& comp = Compare(), const Allocator& alloc = Allocator()) {}
  template <class InputIterator>
  map(InputIterator first, InputIterator last,
    const Compare& comp = Compare(), const Allocator& alloc = Allocator()) {}
  map(const map& x) {}

  // operator=
  map& operator=(const map& x) {}

  // destructor
  ~map() {}

  // get_allocator
  allocator_type get_allocator() const {}

  // iterator
  iterator       begin()       {}
  const_iterator begin() const {}
  iterator       end()       {}
  const_iterator end() const {}
  reverse_iterator       rbegin()       {}
  const_reverse_iterator rbegin() const {}
  reverse_iterator       rend()       {}
  const_reverse_iterator rend() const {}

  // area
  bool empty() const {}
  size_type size() const {}
  size_type max_size() const {}

  // container change
  void clear() {}
  pair<iterator, bool> insert(const value_type& x) {}
  iterator insert(iterator position, const value_type& x) {}
  template <class InputIterator>
  void insert(InputIterator first, InputIterator last) {} 
  void erase(iterator position) {}
  size_type erase(const key_type& x) {}
  void erase(iterator first, iterator last) {}
  void swap(map<Key,T, Compare,Allocator>& st) {}

  // element access
  T& operator[](const key_type& x) {}
  T& operator[](key_type&& x) {}
  size_type count(const key_type& x) const {}
  iterator find(const key_type& x) {}
  const_iterator find(const key_type& x) const {}
  pair<iterator, iterator> equal_range(const key_type& x) {}
  pair<const_iterator, const_iterator> equal_range(const key_type& x) const {}
  iterator lower_bound(const key_type& x) {}
  const_iterator lower_bound(const key_type& x) const {}
  iterator upper_bound(const key_type& x) {}
  const_iterator upper_bound(const key_type& x) const {}

  // observer
  key_compare key_comp() const {}
  value_compare value_comp() const {}


};

} // namespace ft

#endif
