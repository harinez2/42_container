#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace ft {

// pair
template <class T1, class T2>
struct pair {
  typedef T1    first_type;
  typedef T1    second_type;

  T1 first;
  T2 second;

  // constructor
  pair() : first(), second() {}

  pair(const T1& x, const T2& y) : first(x), second(y) {}

  template <class U, class V>
  pair(const pair<U, V>& p) : first(p.first), second(p.second) {}

  // copy constructor
  pair(const pair& rhs) : first(rhs.first), second(rhs.second) {}

  // assignment operator
  pair& operator=(const pair& rhs) {
    if (this != rhs) {
      first = rhs.first;
      second = rhs.second;
    }
    return *this;
  }

  // destructor
  ~pair() {}
};

// non-member operators of the pair
template <typename T1, typename T2>
bool operator==(const pair<T1, T2>& x, const pair<T1, T2>& y) {
  return x.first == y.first && x.second == y.second;
}

template <typename T1, typename T2>
bool operator!=(const pair<T1, T2>& x, const pair<T1, T2>& y) {
  return !(x == y);
}

template <typename T1, typename T2>
bool operator<(const pair<T1, T2>& x, const pair<T1, T2>& y) {
  return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
}

template <typename T1, typename T2>
bool operator>(const pair<T1, T2>& x, const pair<T1, T2>& y) {
  return y < x;
}

template <typename T1, typename T2>
bool operator<=(const pair<T1, T2>& x, const pair<T1, T2>& y) {
  return !(x > y);
}

template <typename T1, typename T2>
bool operator>=(const pair<T1, T2>& x, const pair<T1, T2>& y) {
  return !(x < y);
}

// make_pair
template <class T1, class T2>
pair<T1, T2> make_pair(T1 x, T2 y) {
  return pair<T1, T2>(x, y);
}

} // namespace ft

#endif
