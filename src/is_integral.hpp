#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft {

// integral_constant
template <class T, T val>
struct integral_constant
{
  typedef T                           value_type;
  typedef integral_constant<T, val>   type;
  static const T value = val;

  operator T() const { return val; }
};

// true_type, false_type
typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

// is_integral
template<class T> struct is_integral : public false_type {};
template<> struct is_integral<unsigned char> : public true_type {};
template<> struct is_integral<unsigned short> : public true_type{};
template<> struct is_integral<unsigned int> : public true_type{};
template<> struct is_integral<unsigned long> : public true_type{};
template<> struct is_integral<signed char> : public true_type{};
template<> struct is_integral<short> : public true_type{};
template<> struct is_integral<int> : public true_type{};
template<> struct is_integral<long> : public true_type{};
template<> struct is_integral<char> : public true_type{};
template<> struct is_integral<bool> : public true_type{};

} // namespace ft

#endif
