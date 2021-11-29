#ifndef VECTOR_HPP
#define VECTOR_HPP

template <typename T>
class vector {
  vector() {}
  vector(const vector& rhs) { *this = rhs; }
  vector& operator=(const vector& rhs) {
    if (this != &rhs) {
    }
    return *this;
  }
  ~vector();
  
  
};

#endif
