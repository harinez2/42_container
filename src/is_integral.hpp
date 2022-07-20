#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft {

// integral_constant
template <typename T, T val>
struct integral_constant
{
  typedef T                           value_type;
  typedef integral_constant<T, val>   type;
  enum { value = val };

  operator T() const { return val; }
};

// true_type, false_type
typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

// remove_const
template<typename T>
struct remove_const {
  typedef T     type;
};
template<typename T>
struct remove_const<T const> {
  typedef T     type;
};

// remove_volatile
template<typename T>
struct remove_volatile {
  typedef T     type;
};
template<typename T>
struct remove_volatile<T volatile> {
  typedef T     type;
};

// remove_cv
template <class T>
struct remove_cv {
  typedef typename remove_const<typename remove_volatile<T>::type>::type  type;
};

// is_integral_helper
template<class T> struct is_integral_helper : public false_type {};
template<> struct is_integral_helper<unsigned char> : public true_type {};
template<> struct is_integral_helper<unsigned short> : public true_type{};
template<> struct is_integral_helper<unsigned int> : public true_type{};
template<> struct is_integral_helper<unsigned long> : public true_type{};
template<> struct is_integral_helper<signed char> : public true_type{};
template<> struct is_integral_helper<short> : public true_type{};
template<> struct is_integral_helper<int> : public true_type{};
template<> struct is_integral_helper<long> : public true_type{};
template<> struct is_integral_helper<char> : public true_type{};
template<> struct is_integral_helper<bool> : public true_type{};

// is_integral
template<typename T>
struct is_integral : public is_integral_helper<typename remove_cv<T>::type>::type { };

} // namespace ft

#endif
