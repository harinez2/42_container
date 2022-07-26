#include "../src/vector.hpp"
#include "test_vector.hpp"

#include <vector>

class VectorTest : public ::testing::Test {
 public:
  VectorTest() {
    vft_.push_back(42);
    vft_.push_back(1);
    vft_.push_back(0);
    vft_.push_back(-42);
    vft_.push_back(4242);
    
    vstd_.push_back(42);
    vstd_.push_back(1);
    vstd_.push_back(0);
    vstd_.push_back(-42);
    vstd_.push_back(4242);
  }
  ~VectorTest() {
  }

 protected:
  ft::vector<int> vft_;
  std::vector<int> vstd_;
};

//------------------------------------------------------
// constructor (int)

// (1) vector(const allocator_type& a = allocator_type())
TEST_F(VectorTest, int_constructor_empty) {
  ft::vector<int> vft;
  std::vector<int> vstd;
  EXPECT_EQ(vft.size(), 0);
  EXPECT_TRUE(vft.empty());
  compare_with_std_vector(vft, vstd);
}

TEST_F(VectorTest, int_constructor_allocator) {
  std::allocator<int> alc;
  ft::vector<int> vft(alc);
  std::vector<int> vstd(alc);
  EXPECT_EQ(vft.size(), 0);
  EXPECT_TRUE(vft.empty());
  compare_with_std_vector(vft, vstd);
}

// (2) vector(size_type n, const value_type v = value_type(), const allocator_type& a = allocator_type())
TEST_F(VectorTest, int_constructor_size) {
  ft::vector<int> vft(4);
  std::vector<int> vstd(4);
  EXPECT_EQ(vft.size(), 4);
  EXPECT_FALSE(vft.empty());
  compare_with_std_vector(vft, vstd);
}

TEST_F(VectorTest, int_constructor_value_initvalue) {
  ft::vector<int> vft(4, 2);
  std::vector<int> vstd(4, 2);
  EXPECT_EQ(vft.size(), 4);
  EXPECT_EQ(vft[0], 2);
  EXPECT_EQ(vft[1], 2);
  EXPECT_EQ(vft[2], 2);
  EXPECT_EQ(vft[3], 2);
  EXPECT_FALSE(vft.empty());
  compare_with_std_vector(vft, vstd);
}

TEST_F(VectorTest, int_constructor_value_initvalue_allocator) {
  std::allocator<int> alc;
  ft::vector<int> vft(4, 2, alc);
  std::vector<int> vstd(4, 2, alc);
  EXPECT_EQ(vft.size(), 4);
  EXPECT_EQ(vft[0], 2);
  EXPECT_EQ(vft[1], 2);
  EXPECT_EQ(vft[2], 2);
  EXPECT_EQ(vft[3], 2);
  EXPECT_FALSE(vft.empty());
  compare_with_std_vector(vft, vstd);
}

// (3) vector(InputIter first, 
//       typename ft::enable_if<!ft::is_integral<InputIter>::value, InputIter>::type last,
//       const allocator_type& a = allocator_type())
TEST_F(VectorTest, int_constructor_valuearray) {
  int myints[4];
  myints[0] = 42;
  myints[1] = 2;
  myints[2] = -77;
  myints[3] = 29;
  ft::vector<int> vft(std::begin(myints), std::end(myints));
  std::vector<int> vstd(std::begin(myints), std::end(myints));

  EXPECT_EQ(vft.size(), 4);
  EXPECT_EQ(vft[0], 42);
  EXPECT_EQ(vft[1], 2);
  EXPECT_EQ(vft[2], -77);
  EXPECT_EQ(vft[3], 29);
  EXPECT_FALSE(vft.empty());
  compare_with_std_vector(vft, vstd);
}

TEST_F(VectorTest, int_constructor_valuearray_alloc) {
  std::allocator<int> alc;
  int myints[4];
  myints[0] = 42;
  myints[1] = 2;
  myints[2] = -77;
  myints[3] = 29;
  ft::vector<int> vft(std::begin(myints), std::end(myints), alc);
  std::vector<int> vstd(std::begin(myints), std::end(myints), alc);

  EXPECT_EQ(vft.size(), 4);
  EXPECT_EQ(vft[0], 42);
  EXPECT_EQ(vft[1], 2);
  EXPECT_EQ(vft[2], -77);
  EXPECT_EQ(vft[3], 29);
  EXPECT_FALSE(vft.empty());
  compare_with_std_vector(vft, vstd);
}

// (4) vector(const vector& rhs)
TEST_F(VectorTest, int_constructor_copy) {
  ft::vector<int> vft(65535);
  ft::vector<int> vft2(vft);
  std::vector<int> vstd(65535);
  std::vector<int> vstd2(vstd);
  EXPECT_EQ(vft2.size(), 65535);
  EXPECT_FALSE(vft2.empty());
  compare_with_std_vector(vft2, vstd2);
}

// ======================================================
// constructor (int) border

TEST_F(VectorTest, int_constructor_border) {
  // min size
  ft::vector<int> vft(0, 0);
  std::vector<int> vstd(0, 0);
  EXPECT_EQ(vft.size(), 0);
  EXPECT_TRUE(vft.empty());
  compare_with_std_vector(vft, vstd);

  // big size
  ft::vector<int> vft2(65535, 0);
  std::vector<int> vstd2(65535, 0);
  EXPECT_EQ(vft2.size(), 65535);
  EXPECT_FALSE(vft2.empty());
  compare_with_std_vector(vft2, vstd2);
}

// ======================================================
// iterator (int)

TEST_F(VectorTest, int_iterator) {
  ft::vector<int> vft(3, 42);
  std::vector<int> vstd(3, 42);

  EXPECT_EQ(*(vft.begin()), *(vstd.begin()));
  EXPECT_EQ(*(vft.end() - 1), *(vstd.end() - 1));
}

//------------------------------------------------------
// iterator const (int)

TEST_F(VectorTest, int_iterator_const) {
  const ft::vector<int> vft(3, 42);
  const std::vector<int> vstd(3, 42);

  EXPECT_EQ(*(vft.begin()), *(vstd.begin()));
  EXPECT_EQ(*(vft.end() - 1), *(vstd.end() - 1));
}

//------------------------------------------------------
// iterator (int)

TEST_F(VectorTest, int_iterator2) {
  ft::vector<int>::iterator vft_it = vft_.begin();
  std::vector<int>::iterator vstd_it = vstd_.begin();

  EXPECT_EQ(*vft_it, *vstd_it);

  ++vft_it;
  ++vstd_it;
  
  EXPECT_EQ(*vft_it, *vstd_it);

  ft::vector<int>::iterator vft_it_end = vft_.end();
  std::vector<int>::iterator vstd_it_end = vstd_.end();
  
  EXPECT_EQ(*(vft_it_end - 1), *(vstd_it_end - 1));
}

//------------------------------------------------------
// iterator const (int)

TEST_F(VectorTest, int_iterator_const2) {
  const ft::vector<int>::iterator vft_it = vft_.begin();
  const std::vector<int>::iterator vstd_it = vstd_.begin();

  EXPECT_EQ(*vft_it, *vstd_it);

  const ft::vector<int>::iterator vft_it_end = vft_.end();
  const std::vector<int>::iterator vstd_it_end = vstd_.end();
  
  EXPECT_EQ(*(vft_it_end - 1), *(vstd_it_end - 1));
}

//------------------------------------------------------
// iterator loop (int)

TEST_F(VectorTest, int_iterator_loop) {
  ft::vector<int>::iterator vft_it = vft_.begin();
  std::vector<int>::iterator vstd_it = vstd_.begin();

  for (; vft_it != vft_.end() && vstd_it != vstd_.end(); ++vft_it, ++vstd_it)
    EXPECT_EQ(*vft_it, *vstd_it);
}

// ======================================================
// riterator (int)

TEST_F(VectorTest, int_riterator) {
  ft::vector<int> vft(3, 42);
  std::vector<int> vstd(3, 42);

  EXPECT_EQ(*(vft.rbegin()), *(vstd.rbegin()));
  EXPECT_EQ(*(vft.rend() - 1), *(vstd.rend() - 1));
}

// ------------------------------------------------------
// riterator const (int)

TEST_F(VectorTest, int_riterator_const) {
  const ft::vector<int> vft(3, 42);
  const std::vector<int> vstd(3, 42);

  EXPECT_EQ(*(vft.rbegin()), *(vstd.rbegin()));
  EXPECT_EQ(*(vft.rend() - 1), *(vstd.rend() - 1));
}

// ------------------------------------------------------
// riterator (int)

TEST_F(VectorTest, int_riterator2) {
  ft::vector<int>::reverse_iterator vft_it = vft_.rbegin();
  std::vector<int>::reverse_iterator vstd_it = vstd_.rbegin();

  EXPECT_EQ(*vft_it, *vstd_it);

  ++vft_it;
  ++vstd_it;
  
  EXPECT_EQ(*vft_it, *vstd_it);

  ft::vector<int>::reverse_iterator vft_it_end = vft_.rend();
  std::vector<int>::reverse_iterator vstd_it_end = vstd_.rend();
  
  EXPECT_EQ(*(vft_it_end - 1), *(vstd_it_end - 1));
}

// ------------------------------------------------------
// riterator const (int)

TEST_F(VectorTest, int_riterator_const2) {
  const ft::vector<int>::reverse_iterator vft_it = vft_.rbegin();
  const std::vector<int>::reverse_iterator vstd_it = vstd_.rbegin();

  EXPECT_EQ(*vft_it, *vstd_it);

  const ft::vector<int>::reverse_iterator vft_it_end = vft_.rend();
  const std::vector<int>::reverse_iterator vstd_it_end = vstd_.rend();
  
  EXPECT_EQ(*(vft_it_end - 1), *(vstd_it_end - 1));
}

// ------------------------------------------------------
// riterator loop (int)

TEST_F(VectorTest, int_riterator_loop) {
  ft::vector<int>::reverse_iterator vft_it = vft_.rbegin();
  std::vector<int>::reverse_iterator vstd_it = vstd_.rbegin();

  for (; vft_it != vft_.rend() && vstd_it != vstd_.rend(); ++vft_it, ++vstd_it)
    EXPECT_EQ(*vft_it, *vstd_it);
}

// ======================================================
// basic (int)

TEST_F(VectorTest, int_basic) {
  // basic
  ft::vector<int> vft;
  std::vector<int> vstd;
  vft.push_back(42);
  vstd.push_back(42);
  EXPECT_EQ(vft[0], 42);
  compare_with_std_vector(vft, vstd);
  
  // push_back
  vft.push_back(21);
  vstd.push_back(21);
  EXPECT_EQ(vft[0], 42);
  EXPECT_EQ(vft[1], 21);
  compare_with_std_vector(vft, vstd);
}

// ======================================================
// size (int)

TEST_F(VectorTest, int_size) {
  // check size is 0
  ft::vector<int> vft;
  std::vector<int> vstd;
  EXPECT_EQ(vft.size(), 0);
  compare_with_std_vector(vft, vstd);
  
  // check size is 1 after push_back
  vft.push_back(21);
  vstd.push_back(21);
  EXPECT_EQ(vft.size(), 1);
  compare_with_std_vector(vft, vstd);

  // check size is 65535 after resizing 65535
  vft.resize(65535, 2);
  vstd.resize(65535, 2);
  EXPECT_EQ(vft.size(), 65535);
  compare_with_std_vector(vft, vstd);
}

// ======================================================
// max_size (int)

TEST_F(VectorTest, int_maxsize) {
  // check max_size
  ft::vector<int> vft;
  std::vector<int> vstd;
  EXPECT_EQ(vft.max_size(), vstd.max_size());
  compare_with_std_vector(vft, vstd);
}

// ======================================================
// resize (int)

TEST_F(VectorTest, int_resize) {
  // check resize 0
  ft::vector<int> vft;
  std::vector<int> vstd;
  vft.resize(0);
  vstd.resize(0);
  EXPECT_EQ(vft.size(), 0);
  compare_with_std_vector(vft, vstd);

  // check resize 1
  vft.resize(1);
  vstd.resize(1);
  EXPECT_EQ(vft.size(), 1);
  EXPECT_EQ(vft[0], 0);
  compare_with_std_vector(vft, vstd);
  
  // check resize another 1
  vft.resize(1);
  vstd.resize(1);
  EXPECT_EQ(vft.size(), 1);
  EXPECT_EQ(vft[0], 0);
  compare_with_std_vector(vft, vstd);
  
  // check resize 42 with minus value
  vft.resize(42, -4);
  vstd.resize(42, -4);
  EXPECT_EQ(vft.size(), 42);
  EXPECT_EQ(vft[0], 0);
  EXPECT_EQ(vft[1], -4);
  EXPECT_EQ(vft[41], -4);
  compare_with_std_vector(vft, vstd);

  // check resize big data with positive value
  vft.resize(65535, 2);
  vstd.resize(65535, 2);
  EXPECT_EQ(vft.size(), 65535);
  EXPECT_EQ(vft[0], 0);
  EXPECT_EQ(vft[1], -4);
  EXPECT_EQ(vft[41], -4);
  EXPECT_EQ(vft[42], 2);
  EXPECT_EQ(vft[65534], 2);
  compare_with_std_vector(vft, vstd);
  
  // check resize with reducing size
  vft.resize(50, 3);
  vstd.resize(50, 3);
  EXPECT_EQ(vft.size(), 50);
  EXPECT_EQ(vft[0], 0);
  EXPECT_EQ(vft[1], -4);
  EXPECT_EQ(vft[41], -4);
  EXPECT_EQ(vft[42], 2);
  EXPECT_EQ(vft[49], 2);
  compare_with_std_vector(vft, vstd);
}

// ======================================================
// capacity (int)

TEST_F(VectorTest, int_capacity) {
  // check capacoty is 0
  ft::vector<int> vft;
  std::vector<int> vstd;
  EXPECT_EQ(vft.capacity(), 0);
  compare_with_std_vector(vft, vstd);

  // check capacoty is 65535
  vft.resize(65535, 2);
  vstd.resize(65535, 2);
  EXPECT_EQ(vft.capacity(), 65535);
  compare_with_std_vector(vft, vstd);
}

// ======================================================
// empty (int)

TEST_F(VectorTest, int_empty) {
  // check empty is true
  ft::vector<int> vft;
  std::vector<int> vstd;
  EXPECT_TRUE(vft.empty());
  compare_with_std_vector(vft, vstd);

  // check empty is false
  vft.push_back(42);
  vstd.push_back(42);
  EXPECT_FALSE(vft.empty());
  compare_with_std_vector(vft, vstd);

  // check empty is true after resizing to 0
  vft.resize(0);
  vstd.resize(0);
  EXPECT_TRUE(vft.empty());
  compare_with_std_vector(vft, vstd);
}

// ======================================================
// reserve (int)

TEST_F(VectorTest, int_reserve) {
  // initial check
  ft::vector<int> vft;
  std::vector<int> vstd;
  EXPECT_EQ(vft.size(), 0);
  compare_with_std_vector(vft, vstd);

  // reserve 0
  vft.reserve(0);
  vstd.reserve(0);
  EXPECT_EQ(vft.size(), 0);
  compare_with_std_vector(vft, vstd);

  // reserve 1
  vft.reserve(1);
  vstd.reserve(1);
  EXPECT_EQ(vft.size(), 0);
  EXPECT_EQ(vft.capacity(), 1);
  compare_with_std_vector(vft, vstd);

  // reserve another 1
  vft.reserve(1);
  vstd.reserve(1);
  EXPECT_EQ(vft.size(), 0);
  EXPECT_EQ(vft.capacity(), 1);
  compare_with_std_vector(vft, vstd);

  // reserve 65535
  vft.reserve(65535);
  vstd.reserve(65535);
  EXPECT_EQ(vft.size(), 0);
  EXPECT_EQ(vft.capacity(), 65535);
  compare_with_std_vector(vft, vstd);

  // reserve extra 1
  vft.reserve(1);
  vstd.reserve(1);
  EXPECT_EQ(vft.size(), 0);
  EXPECT_EQ(vft.capacity(), 65535);
  compare_with_std_vector(vft, vstd);

  // reserve over max_size and check err msg
  std::string vft_err;
  std::string vstd_err;
  try {
    vft.reserve(vft.max_size() + 1);
  } catch(std::exception& e) {
    vft_err = e.what();
  }
  try {
    vstd.reserve(vstd.max_size() + 1);
  } catch(std::exception& e) {
    vstd_err = e.what();
  }
  EXPECT_EQ(vft_err, vstd_err);
  EXPECT_EQ(vft.size(), 0);
  EXPECT_EQ(vft.capacity(), 65535);
  compare_with_std_vector(vft, vstd);
}

// ======================================================
// operator[] (int)

TEST_F(VectorTest, int_operatorsqbracket) {
  // basic
  ft::vector<int> vft(4, 2);
  std::vector<int> vstd(4, 2);
  EXPECT_EQ(vft[0], 2);
  EXPECT_EQ(vft[1], 2);
  EXPECT_EQ(vft[0], vstd[0]);
  EXPECT_EQ(vft[1], vstd[1]);
  compare_with_std_vector(vft, vstd);

  // big data case (read)
  vft.resize(65535, -1);
  vstd.resize(65535, -1);
  EXPECT_EQ(vft[0], 2);
  EXPECT_EQ(vft[1], 2);
  EXPECT_EQ(vft[3], 2);
  EXPECT_EQ(vft[4], -1);
  EXPECT_EQ(vft[65534], -1);
  EXPECT_EQ(vft[0], vstd[0]);
  EXPECT_EQ(vft[1], vstd[1]);
  EXPECT_EQ(vft[3], vstd[3]);
  EXPECT_EQ(vft[4], vstd[4]);
  EXPECT_EQ(vft[65534], vstd[65534]);
  compare_with_std_vector(vft, vstd);

  // big data case (write)
  vft[0] = 3;
  vft[1] = 4;
  vft[2] = 5;
  vft[65534] = 6;
  vstd[0] = 3;
  vstd[1] = 4;
  vstd[2] = 5;
  vstd[65534] = 6;
  EXPECT_EQ(vft[0], 3);
  EXPECT_EQ(vft[1], 4);
  EXPECT_EQ(vft[2], 5);
  EXPECT_EQ(vft[65534], 6);
  EXPECT_EQ(vft[0], vstd[0]);
  EXPECT_EQ(vft[1], vstd[1]);
  EXPECT_EQ(vft[2], vstd[2]);
  EXPECT_EQ(vft[65534], vstd[65534]);
  compare_with_std_vector(vft, vstd);
}

// ======================================================
// at (int)

TEST_F(VectorTest, int_at) {
  // basic
  ft::vector<int> vft(4, 2);
  std::vector<int> vstd(4, 2);
  EXPECT_EQ(vft.at(0), 2);
  EXPECT_EQ(vft.at(1), 2);
  EXPECT_EQ(vft.at(0), vstd.at(0));
  EXPECT_EQ(vft.at(1), vstd.at(1));
  compare_with_std_vector(vft, vstd);

  // big data case (read)
  vft.resize(65535, -1);
  vstd.resize(65535, -1);
  EXPECT_EQ(vft.at(0), 2);
  EXPECT_EQ(vft.at(1), 2);
  EXPECT_EQ(vft.at(3), 2);
  EXPECT_EQ(vft.at(4), -1);
  EXPECT_EQ(vft.at(65534), -1);
  EXPECT_EQ(vft.at(0), vstd.at(0));
  EXPECT_EQ(vft.at(1), vstd.at(1));
  EXPECT_EQ(vft.at(3), vstd.at(3));
  EXPECT_EQ(vft.at(4), vstd.at(4));
  EXPECT_EQ(vft.at(65534), vstd.at(65534));
  compare_with_std_vector(vft, vstd);

  // big data case (write)
  vft.at(0) = 3;
  vft.at(1) = 4;
  vft.at(2) = 5;
  vft.at(65534) = 6;
  vstd.at(0) = 3;
  vstd.at(1) = 4;
  vstd.at(2) = 5;
  vstd.at(65534) = 6;
  EXPECT_EQ(vft.at(0), 3);
  EXPECT_EQ(vft.at(1), 4);
  EXPECT_EQ(vft.at(2), 5);
  EXPECT_EQ(vft.at(65534), 6);
  EXPECT_EQ(vft.at(0), vstd.at(0));
  EXPECT_EQ(vft.at(1), vstd.at(1));
  EXPECT_EQ(vft.at(2), vstd.at(2));
  EXPECT_EQ(vft.at(65534), vstd.at(65534));
  compare_with_std_vector(vft, vstd);
  
  // invalid op and check err msg
  std::string vft_err;
  std::string vstd_err;
  try {
    vft.at(65535);
  } catch(std::exception& e) {
    vft_err = e.what();
  }
  try {
    vstd.at(65535);
  } catch(std::exception& e) {
    vstd_err = e.what();
  }
  EXPECT_EQ(vft_err, vstd_err);
  compare_with_std_vector(vft, vstd);
}

// ======================================================
// data (int)

TEST_F(VectorTest, int_data) {
  ft::vector<int>::pointer vft_data = vft_.data();
  std::vector<int>::pointer vstd_data = vstd_.data();
  EXPECT_EQ(*vft_data, 42);
  EXPECT_EQ(*vft_data, *vstd_data);
}

TEST_F(VectorTest, int_data_const) {
  ft::vector<int>::const_pointer vft_data = vft_.data();
  std::vector<int>::const_pointer vstd_data = vstd_.data();
  EXPECT_EQ(*vft_data, 42);
  EXPECT_EQ(*vft_data, *vstd_data);
}

// ======================================================
// front (int)

TEST_F(VectorTest, int_front) {
  // return front in some data
  ft::vector<int> vft(vft_);
  std::vector<int> vstd(vstd_);
  EXPECT_EQ(vft.front(), 42);
  EXPECT_EQ(vft.front(), vft[0]);
  EXPECT_EQ(vft.front(), vstd.front());
  compare_with_std_vector(vft, vstd);

  // return front after doing some op
  vft.clear();
  vft.push_back(88);
  vft.resize(12, 99);
  vstd.clear();
  vstd.push_back(88);
  vstd.resize(12, 99);
  EXPECT_EQ(vft.front(), 88);
  EXPECT_EQ(vft.front(), vft[0]);
  EXPECT_EQ(vft.front(), vstd.front());
  compare_with_std_vector(vft, vstd);
}

// ======================================================
// back (int)

TEST_F(VectorTest, int_back) {
  // return back in some data
  ft::vector<int> vft(vft_);
  std::vector<int> vstd(vstd_);
  EXPECT_EQ(vft.back(), 4242);
  EXPECT_EQ(vft.back(), vft[vft.size() - 1]);
  EXPECT_EQ(vft.back(), vstd.back());
  compare_with_std_vector(vft, vstd);

  // return back after doing some op
  vft.clear();
  vft.push_back(88);
  vft.resize(12, 99);
  vstd.clear();
  vstd.push_back(88);
  vstd.resize(12, 99);
  EXPECT_EQ(vft.back(), 99);
  EXPECT_EQ(vft.back(), vft[vft.size() - 1]);
  EXPECT_EQ(vft.back(), vstd.back());
  compare_with_std_vector(vft, vstd);
}

// ======================================================
// assign (int)

TEST_F(VectorTest, int_assign_iterator) {
  // assinging the same size
  // ft::vector<int> vft(vft_);
  // std::vector<int> vstd(vstd_);
  // int data[] = {4, 3, 2, 1, 0};
  // vft.assign(std::begin(data), std::end(data));
  // vstd.assign(std::begin(data), std::end(data));
  // EXPECT_EQ(vft[0], 4);
  // EXPECT_EQ(vft[1], 3);
  // EXPECT_EQ(vft[2], 2);
  // EXPECT_EQ(vft[3], 1);
  // EXPECT_EQ(vft[4], 0);
  // EXPECT_EQ(vft.size(), 5);
  // compare_with_std_vector(vft, vstd);

  // // assinging smaller size
  // int data2[] = {40, 30};
  // vft.assign(std::begin(data2), std::end(data2));
  // vstd.assign(std::begin(data2), std::end(data2));
  // EXPECT_EQ(vft[0], 40);
  // EXPECT_EQ(vft[1], 30);
  // EXPECT_EQ(vft.size(), 2);
  // compare_with_std_vector(vft, vstd);

  // // assinging bigger size
  // int data3[] = {700, 600, 500, 400, 300, 200, 100};
  // vft.assign(std::begin(data3), std::end(data3));
  // vstd.assign(std::begin(data3), std::end(data3));
  // EXPECT_EQ(vft[0], 700);
  // EXPECT_EQ(vft[1], 600);
  // EXPECT_EQ(vft[2], 500);
  // EXPECT_EQ(vft[3], 400);
  // EXPECT_EQ(vft[4], 300);
  // EXPECT_EQ(vft[5], 200);
  // EXPECT_EQ(vft[6], 100);
  // EXPECT_EQ(vft.size(), 7);
  // compare_with_std_vector(vft, vstd);
}

TEST_F(VectorTest, int_assign_initializer) {
  // assinging the same size
  ft::vector<int> vft(vft_);
  std::vector<int> vstd(vstd_);
  vft.assign(5, 42);
  vstd.assign(5, 42);
  EXPECT_EQ(vft[0], 42);
  EXPECT_EQ(vft[1], 42);
  EXPECT_EQ(vft[2], 42);
  EXPECT_EQ(vft[3], 42);
  EXPECT_EQ(vft[4], 42);
  EXPECT_EQ(vft.size(), 5);
  compare_with_std_vector(vft, vstd);

  // assinging smaller size
  vft.assign(2, 420);
  vstd.assign(2, 420);
  EXPECT_EQ(vft[0], 420);
  EXPECT_EQ(vft[1], 420);
  EXPECT_EQ(vft.size(), 2);
  compare_with_std_vector(vft, vstd);

  // assinging bigger size
  vft.assign(7, 4200);
  vstd.assign(7, 4200);
  EXPECT_EQ(vft[0], 4200);
  EXPECT_EQ(vft[1], 4200);
  EXPECT_EQ(vft[2], 4200);
  EXPECT_EQ(vft[3], 4200);
  EXPECT_EQ(vft[4], 4200);
  EXPECT_EQ(vft[5], 4200);
  EXPECT_EQ(vft[6], 4200);
  EXPECT_EQ(vft.size(), 7);
  compare_with_std_vector(vft, vstd);
}

// ======================================================
// push_back (int)

TEST_F(VectorTest, int_pushback) {
  // push_back 4 times
  ft::vector<int> vft(2, 2);
  std::vector<int> vstd(2, 2);
  EXPECT_EQ(vft.at(0), 2);
  EXPECT_EQ(vft.at(1), 2);
  vft.push_back(3);
  vft.push_back(0);
  vft.push_back(-2147483648);
  vft.push_back(2147483647);
  vstd.push_back(3);
  vstd.push_back(0);
  vstd.push_back(-2147483648);
  vstd.push_back(2147483647);
  EXPECT_EQ(vft.at(2), 3);
  EXPECT_EQ(vft.at(3), 0);
  EXPECT_EQ(vft.at(4), -2147483648);
  EXPECT_EQ(vft.at(5), 2147483647);
  compare_with_std_vector(vft, vstd);

  // push_back BIG_TEST_SIZE times
  ft::vector<int> vft2;
  std::vector<int> vstd2;
  for (std::size_t i = 0; i < BIG_TEST_SIZE; ++i) {
    vft2.push_back(i);
    vstd2.push_back(i);
    compare_with_std_vector(vft2, vstd2);
  }
}

// ======================================================
// pop_back (int)

TEST_F(VectorTest, int_popback) {
  // pop_back 3 times
  ft::vector<int> vft(vft_);
  std::vector<int> vstd(vstd_);
  EXPECT_EQ(vft.at(0), 42);
  EXPECT_EQ(vft.at(1), 1);
  vft.pop_back();
  vft.pop_back();
  vft.pop_back();
  vstd.pop_back();
  vstd.pop_back();
  vstd.pop_back();
  EXPECT_EQ(vft.at(0), 42);
  EXPECT_EQ(vft.at(1), 1);
  compare_with_std_vector(vft, vstd);

  // pop_back BIG_TEST_SIZE / 2 times
  ft::vector<int> vft2(BIG_TEST_SIZE, 42);
  std::vector<int> vstd2(BIG_TEST_SIZE, 42);
  EXPECT_EQ(vft2.size(), BIG_TEST_SIZE);
  EXPECT_EQ(vft2.size(), vstd2.size());
  for (std::size_t i = 0; i < BIG_TEST_SIZE / 2; ++i) {
    vft2.pop_back();
    vstd2.pop_back();
    compare_with_std_vector(vft2, vstd2);
  }
  EXPECT_EQ(vft2.size(), BIG_TEST_SIZE - BIG_TEST_SIZE / 2);
  EXPECT_EQ(vft2[BIG_TEST_SIZE - BIG_TEST_SIZE / 2 - 1], 42);
  EXPECT_EQ(vft2.size(), vstd2.size());
  compare_with_std_vector(vft2, vstd2);

  // pop_back remain data until size() is zero
  for (std::size_t i = 0; i < BIG_TEST_SIZE - BIG_TEST_SIZE / 2; ++i) {
    vft2.pop_back();
    vstd2.pop_back();
    compare_with_std_vector(vft2, vstd2);
  }
  EXPECT_EQ(vft2.size(), 0);
  EXPECT_TRUE(vft2.empty());
}

// ======================================================
// insert (int)

TEST_F(VectorTest, int_insert_iterator) {
  // insert in empty vector
  ft::vector<int> vft;
  std::vector<int> vstd;
  vft.insert(vft.begin(), 42);
  vstd.insert(vstd.begin(), 42);
  EXPECT_EQ(vft[0], 42);
  EXPECT_EQ(vft.size(), 1);
  compare_with_std_vector(vft, vstd);

  // insert in head, tail, and middle
  ft::vector<int> vft2(vft_);
  std::vector<int> vstd2(vstd_);
  vft2.insert(vft2.begin(), 1111);
  vstd2.insert(vstd2.begin(), 1111);
  compare_with_std_vector(vft2, vstd2);
  vft2.insert(vft2.end(), 2222);
  vstd2.insert(vstd2.end(), 2222);
  compare_with_std_vector(vft2, vstd2);
  vft2.insert(vft2.begin() + 2, 3333);
  vstd2.insert(vstd2.begin() + 2, 3333);
  EXPECT_EQ(vft2[0], 1111);
  EXPECT_EQ(vft2[1], 42);
  EXPECT_EQ(vft2[2], 3333);
  EXPECT_EQ(vft2[3], 1);
  EXPECT_EQ(vft2[4], 0);
  EXPECT_EQ(vft2[5], -42);
  EXPECT_EQ(vft2[6], 4242);
  EXPECT_EQ(vft2[7], 2222);
  EXPECT_EQ(vft2.size(), 8);
  compare_with_std_vector(vft2, vstd2);
}

TEST_F(VectorTest, int_insert_iterator_size) {
  // insert in empty vector
  ft::vector<int> vft;
  std::vector<int> vstd;
  vft.insert(vft.begin(), 8, 42);
  vstd.insert(vstd.begin(), 8, 42);
  EXPECT_EQ(vft[0], 42);
  EXPECT_EQ(vft[1], 42);
  EXPECT_EQ(vft[7], 42);
  EXPECT_EQ(vft.size(), 8);
  compare_with_std_vector(vft, vstd);

  // insert in head, tail, and middle
  ft::vector<int> vft2(vft_);
  std::vector<int> vstd2(vstd_);
  vft2.insert(vft2.begin(), 2, 1111);
  vstd2.insert(vstd2.begin(), 2, 1111);
  compare_with_std_vector(vft2, vstd2);
  vft2.insert(vft2.end(), 4, 2222);
  vstd2.insert(vstd2.end(), 4, 2222);
  compare_with_std_vector(vft2, vstd2);
  vft2.insert(vft2.begin() + 2, 3, 3333);
  vstd2.insert(vstd2.begin() + 2, 3, 3333);
  EXPECT_EQ(vft2[0], 1111);
  EXPECT_EQ(vft2[1], 1111);
  EXPECT_EQ(vft2[2], 3333);
  EXPECT_EQ(vft2[3], 3333);
  EXPECT_EQ(vft2[4], 3333);
  EXPECT_EQ(vft2[5], 42);
  EXPECT_EQ(vft2[6], 1);
  EXPECT_EQ(vft2[7], 0);
  EXPECT_EQ(vft2[8], -42);
  EXPECT_EQ(vft2[9], 4242);
  EXPECT_EQ(vft2[10], 2222);
  EXPECT_EQ(vft2[13], 2222);
  EXPECT_EQ(vft2.size(), 14);
  compare_with_std_vector(vft2, vstd2);

  // add zero
  vft2.insert(vft2.begin() + 3, 0, 4444);
  compare_with_std_vector(vft2, vstd2);
}

TEST_F(VectorTest, int_insert_iterator_inputiterator) {
}

// ======================================================
// erase (int)

TEST_F(VectorTest, int_erase_one) {
  // erase top
  ft::vector<int> vft(vft_);
  std::vector<int> vstd(vstd_);
  vft.erase(vft.begin());
  vstd.erase(vstd.begin());
  compare_with_std_vector(vft, vstd);

  // erase middle
  vft.erase(vft.begin() + 1);
  vstd.erase(vstd.begin() + 1);
  compare_with_std_vector(vft, vstd);

  // erase end
  vft.erase(vft.end() - 1);
  vstd.erase(vstd.end() - 1);
  compare_with_std_vector(vft, vstd);
}

TEST_F(VectorTest, int_erase_iterator) {
  // erase top
  ft::vector<int> vft(vft_);
  std::vector<int> vstd(vstd_);
  vft.erase(vft.begin(), vft.begin() + 2);
  vstd.erase(vstd.begin(), vstd.begin() + 2);
  compare_with_std_vector(vft, vstd);

  // erase middle
  ft::vector<int> vft2(vft_);
  std::vector<int> vstd2(vstd_);
  vft2.erase(vft2.begin() + 1, vft2.begin() + 2);
  vstd2.erase(vstd2.begin() + 1, vstd2.begin() + 2);
  compare_with_std_vector(vft2, vstd2);

  // erase end
  ft::vector<int> vft3(vft_);
  std::vector<int> vstd3(vstd_);
  vft3.erase(vft3.end() - 2, vft3.end());
  vstd3.erase(vstd3.end() - 2, vstd3.end());
  compare_with_std_vector(vft3, vstd3);
}

// ======================================================
// swap (int)

TEST_F(VectorTest, int_swap) {
  // swap with some data
  ft::vector<int> vft(vft_);
  std::vector<int> vstd(vstd_);
  ft::vector<int> vft2;
  std::vector<int> vstd2;
  vft2.push_back(9);
  vstd2.push_back(9);
  vft.swap(vft2);
  vstd.swap(vstd2);
  for (std::size_t i = 0; i < vft_.size(); ++i)
    EXPECT_EQ(vft2[i], vft_[i]);
  compare_with_std_vector(vft, vstd);
  compare_with_std_vector(vft2, vstd2);

  // left is empty
  ft::vector<int> vft3;
  std::vector<int> vstd3;
  ft::vector<int> vft4(vft_);
  std::vector<int> vstd4(vstd_);
  vft3.swap(vft4);
  vstd3.swap(vstd4);
  for (std::size_t i = 0; i < vft_.size(); ++i)
    EXPECT_EQ(vft3[i], vft_[i]);
  compare_with_std_vector(vft3, vstd3);
  compare_with_std_vector(vft4, vstd4);

  // right is empty
  vft3.swap(vft4);
  vstd3.swap(vstd4);
  for (std::size_t i = 0; i < vft_.size(); ++i)
    EXPECT_EQ(vft4[i], vft_[i]);
  compare_with_std_vector(vft3, vstd3);
  compare_with_std_vector(vft4, vstd4);

  // both empty
  ft::vector<int> vft5;
  std::vector<int> vstd5;
  ft::vector<int> vft6;
  std::vector<int> vstd6;
  vft5.swap(vft6);
  vstd5.swap(vstd6);
  EXPECT_EQ(vft5.size(), 0);
  EXPECT_EQ(vft6.size(), 0);
  compare_with_std_vector(vft5, vstd5);
  compare_with_std_vector(vft6, vstd6);
}

// ======================================================
// clear (int)

TEST_F(VectorTest, int_clear) {
  // clear empty vector
  ft::vector<int> vft;
  std::vector<int> vstd;
  vft.clear();
  vstd.clear();
  EXPECT_EQ(vft.size(), 0);
  EXPECT_TRUE(vft.empty());
  EXPECT_EQ(vft.capacity(), 0);
  compare_with_std_vector(vft, vstd);

  // clear 65535 data
  ft::vector<int> vft2(65535);
  std::vector<int> vstd2(65535);
  EXPECT_EQ(vft2.size(), 65535);
  EXPECT_FALSE(vft2.empty());
  vft2.clear();
  vstd2.clear();
  EXPECT_EQ(vft2.size(), 0);
  EXPECT_TRUE(vft2.empty());
  EXPECT_EQ(vft2.capacity(), 65535);
  compare_with_std_vector(vft2, vstd2);
}

// ======================================================
// get_allocator (int)

TEST_F(VectorTest, int_getallocator) {
  // std
  std::allocator<int> std_alloc;
  std::vector<int> vstd(std_alloc);
  std::allocator<int> std_result = vstd.get_allocator();
  EXPECT_EQ(std_result, std_alloc);

  // ft
  ft::vector<int> vft(std_alloc);
  std::allocator<int> ft_result = vft.get_allocator();
  EXPECT_EQ(ft_result, std_alloc);

  // std const
  const std::allocator<int> std_alloc2;
  const std::vector<int> vstd2(std_alloc2);
  std::allocator<int> std_result2 = vstd2.get_allocator();
  EXPECT_EQ(std_result2, std_alloc2);

  // ft const
  const ft::vector<int> vft2(std_alloc2);
  std::allocator<int> ft_result2 = vft2.get_allocator();
  EXPECT_EQ(ft_result2, std_alloc2);

  // std const const
  const std::allocator<int> std_alloc3;
  const std::vector<int> vstd3(std_alloc3);
  const std::allocator<int> std_result3 = vstd3.get_allocator();
  EXPECT_EQ(std_result3, std_alloc3);

  // ft const const
  const ft::vector<int> vft3(std_alloc3);
  const std::allocator<int> ft_result3 = vft3.get_allocator();
  EXPECT_EQ(ft_result3, std_alloc3);
}

//======================================================
// swap (int)
//https://programming-place.net/ppp/contents/cpp/library/005.html
// TEST_F(VectorTest, int_swap) {

//   std::vector<int> v;
//   v.reserve(10000);
//   v.push_back(0);

//   EXPECT_EQ(v.capacity(), 10000);

//   std::vector<int>(v).swap(v);

//   EXPECT_EQ(v.capacity(), 1);
// }

//======================================================
// constructor (string)

TEST_F(VectorTest, str_constructor_empty) {
  ft::vector<std::string> vft;
  std::vector<std::string> vstd;

  EXPECT_EQ(vft.size(), 0);
  EXPECT_TRUE(vft.empty());
  compare_with_std_vector(vft, vstd);
}

// TEST_F(VectorTest, constructor_with_same_value_int) {
//   ft::vector<std::string> vft(100, "hello");
//   std::vector<std::string> vstd(100, "hello");

//   EXPECT_EQ(vft.size(), 100);
//   EXPECT_EQ(vft[0], "hello");
//   EXPECT_EQ(vft[99], "hello");
//   EXPECT_FALSE(vft.empty());
//   compare_with_std_vector(vft, vstd);
// }
