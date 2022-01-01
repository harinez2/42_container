#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace ft {

template<bool, typename _Tp = void>
struct enable_if {};

template<typename _Tp>
struct enable_if<true, _Tp> {
  typedef _Tp type;
};

// template <class T>
// struct is_integral {

// };

} // namespace ft

#endif
