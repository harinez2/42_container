#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft {

template <class T, T val>
struct integral_constant
{
  typedef mpl::integral_c_tag tag;
  typedef T value_type;
  typedef integral_constant<T, val> type;
  static const T value = val;

  template <class U>
  static U& dereference(U* p) { return *p; }
  operator const mpl::integral_c<T, val>& ()const
  {
    static const char data[sizeof(long)] = { 0 };
    return dereference(reinterpret_cast<const mpl::integral_c<T, val>*>(&data));
  }
  BOOST_CONSTEXPR operator T()const { return val; }
};


template <bool val>
bool const integral_constant<bool, val>::value;

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

template <class T>
struct is_integral {};

} // namespace ft

#endif
