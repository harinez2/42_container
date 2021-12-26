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

TEST_F(VectorTest, int_constructor_empty) {
  ft::vector<int> vft;
  std::vector<int> vstd;

  EXPECT_EQ(vft.size(), 0);
  EXPECT_TRUE(vft.empty());
  compare_with_std_vector(vft, vstd);
}

TEST_F(VectorTest, int_constructor_with_allocator) {
  std::allocator<int> alc;
  ft::vector<int> vft(alc);
  std::vector<int> vstd(alc);

  EXPECT_EQ(vft.size(), 0);
  EXPECT_TRUE(vft.empty());
  compare_with_std_vector(vft, vstd);
}

TEST_F(VectorTest, int_constructor_init_with_value) {
  ft::vector<int> vft(4);
  std::vector<int> vstd(4);

  EXPECT_EQ(vft.size(), 4);
  EXPECT_FALSE(vft.empty());
  compare_with_std_vector(vft, vstd);
}

TEST_F(VectorTest, int_constructor_init_with_value_two) {
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

TEST_F(VectorTest, int_constructor_init_with_value_two_with_allocator) {
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

// ======================================================
// constructor with iterator (int)

TEST_F(VectorTest, int_constructor_init_with_value_array) {
  int myints[] = {16, 2, 77, 29};
  ft::vector<int> vft(4, 2);
  std::vector<int> vstd(4, 2);
  // ft::vector<int> vft2< ft::vector<int>::iterator >(vft.begin(), vft.end());
  ft::vector<int> vft2(std::begin(myints), std::end(myints));
  std::vector<int> vstd2(std::begin(myints), std::end(myints));
  // std::vector<int> vstd2(vstd.begin(), vstd.end());

  EXPECT_EQ(vft2.size(), 4);
  EXPECT_EQ(vft2[0], 16);
  EXPECT_EQ(vft2[1], 2);
  EXPECT_EQ(vft2[2], 77);
  EXPECT_EQ(vft2[3], 29);
  EXPECT_FALSE(vft2.empty());
  compare_with_std_vector(vft2, vstd2);
}

// ======================================================
// constructor (int) border

TEST_F(VectorTest, int_constructor_init_err_bordermin) {
  ft::vector<int> vft(0, 0);
  std::vector<int> vstd(0, 0);

  EXPECT_EQ(vft.size(), 0);
  EXPECT_TRUE(vft.empty());
  compare_with_std_vector(vft, vstd);
}

TEST_F(VectorTest, int_constructor_init_err_bordermax) {
  ft::vector<int> vft(65535, 0);
  std::vector<int> vstd(65535, 0);

  EXPECT_EQ(vft.size(), 65535);
  EXPECT_FALSE(vft.empty());
  compare_with_std_vector(vft, vstd);
}

// ======================================================
// copy constructor (int)

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
// iterator (int)

// TEST_F(VectorTest, int_iterator) {
//   ft::vector<int> vft(3, 42);
//   std::vector<int> vstd(3, 42);

//   EXPECT_EQ(*(vft.begin()), *(vstd.begin()));
//   EXPECT_EQ(*(vft.end()), *(vstd.end()));
// }

//------------------------------------------------------
// iterator const (int)

// TEST_F(VectorTest, int_iterator_const) {
//   const ft::vector<int> vft(3, 42);
//   const std::vector<int> vstd(3, 42);

//   EXPECT_EQ(*(vft.begin()), *(vstd.begin()));
//   EXPECT_EQ(*(vft.end()), *(vstd.end()));
// }

//------------------------------------------------------
// iterator (int)

// TEST_F(VectorTest, int_iterator2) {
//   ft::vector<int>::iterator vft_it = vft_.begin();
//   std::vector<int>::iterator vstd_it = vstd_.begin();

//   EXPECT_EQ(*vft_it, *vstd_it);

//   ++vft_it;
//   ++vstd_it;
  
//   EXPECT_EQ(*vft_it, *vstd_it);

//   ft::vector<int>::iterator vft_it_end = vft_.end();
//   std::vector<int>::iterator vstd_it_end = vstd_.end();
  
//   EXPECT_EQ(*(vft_it_end - 1), *(vsvstd_it_endtd_it - 1));
// }

//------------------------------------------------------
// iterator const (int)

// TEST_F(VectorTest, int_iterator_const2) {
//   const ft::vector<int>::iterator vft_it = vft_.begin();
//   const std::vector<int>::iterator vstd_it = vstd_.begin();

//   EXPECT_EQ(*vft_it, *vstd_it);

//   const ft::vector<int>::iterator vft_it = vft_.end();
//   const std::vector<int>::iterator vstd_it = vstd_.end();
  
//   EXPECT_EQ(*(vft_it - 1), *(vstd_it - 1));
// }

//------------------------------------------------------
// iterator loop (int)

// TEST_F(VectorTest, int_iterator_loop) {
//   ft::vector<int>::iterator vft_it = vft_.begin();
//   std::vector<int>::iterator vstd_it = vstd_.begin();

//   for (; vft_it != vft_.end() && vstd_it != vstd_.end(); ++vft_it, ++vstd_it)
//     EXPECT_EQ(*vft_it, *vstd_it);
// }

// ======================================================
// riterator (int)

// TEST_F(VectorTest, int_riterator) {
//   ft::vector<int> vft(3, 42);
//   std::vector<int> vstd(3, 42);

//   EXPECT_EQ(*(vft.rbegin()), *(vstd.rbegin()));
//   EXPECT_EQ(*(vft.rend()), *(vstd.rend()));
// }

// ------------------------------------------------------
// riterator const (int)

// TEST_F(VectorTest, int_riterator_const) {
//   const ft::vector<int> vft(3, 42);
//   const std::vector<int> vstd(3, 42);

//   EXPECT_EQ(*(vft.rbegin()), *(vstd.rbegin()));
//   EXPECT_EQ(*(vft.rend()), *(vstd.rend()));
// }

// ------------------------------------------------------
// riterator (int)

// TEST_F(VectorTest, int_riterator2) {
//   ft::vector<int>::iterator vft_it = vft_.rbegin();
//   std::vector<int>::iterator vstd_it = vstd_.rbegin();

//   EXPECT_EQ(*vft_it, *vstd_it);

//   ++vft_it;
//   ++vstd_it;
  
//   EXPECT_EQ(*vft_it, *vstd_it);

//   ft::vector<int>::iterator vft_it_end = vft_.rend();
//   std::vector<int>::iterator vstd_it_end = vstd_.rend();
  
//   EXPECT_EQ(*(vft_it_end - 1), *(vsvstd_it_endtd_it - 1));
// }

// ------------------------------------------------------
// riterator const (int)

// TEST_F(VectorTest, int_riterator_const2) {
//   const ft::vector<int>::iterator vft_it = vft_.rbegin();
//   const std::vector<int>::iterator vstd_it = vstd_.rbegin();

//   EXPECT_EQ(*vft_it, *vstd_it);

//   const ft::vector<int>::iterator vft_it = vft_.rend();
//   const std::vector<int>::iterator vstd_it = vstd_.rend();
  
//   EXPECT_EQ(*(vft_it - 1), *(vstd_it - 1));
// }

// ------------------------------------------------------
// riterator loop (int)

// TEST_F(VectorTest, int_riterator_loop) {
//   ft::vector<int>::iterator vft_it = vft_.rbegin();
//   std::vector<int>::iterator vstd_it = vstd_.rbegin();

//   for (; vft_it != vft_.rend() && vstd_it != vstd_.rend(); ++vft_it, ++vstd_it)
//     EXPECT_EQ(*vft_it, *vstd_it);
// }

// ======================================================
// basic (int)

TEST_F(VectorTest, int_basic) {
  ft::vector<int> vft;
  std::vector<int> vstd;
  vft.push_back(42);
  vstd.push_back(42);

  EXPECT_EQ(vft[0], 42);
  compare_with_std_vector(vft, vstd);
  
  vft.push_back(21);
  vstd.push_back(21);

  EXPECT_EQ(vft[0], 42);
  EXPECT_EQ(vft[1], 21);
  compare_with_std_vector(vft, vstd);
}

// ======================================================
// resize (int)

TEST_F(VectorTest, int_resize) {
  ft::vector<int> vft;
  std::vector<int> vstd;
  vft.resize(0);
  vstd.resize(0);
  EXPECT_EQ(vft.size(), 0);
  compare_with_std_vector(vft, vstd);

  vft.resize(1);
  vstd.resize(1);
  EXPECT_EQ(vft.size(), 1);
  EXPECT_EQ(vft[0], 0);
  compare_with_std_vector(vft, vstd);
  
  vft.resize(1);
  vstd.resize(1);
  EXPECT_EQ(vft.size(), 1);
  EXPECT_EQ(vft[0], 0);
  compare_with_std_vector(vft, vstd);
  
  vft.resize(42, -4);
  vstd.resize(42, -4);
  EXPECT_EQ(vft.size(), 42);
  EXPECT_EQ(vft[0], 0);
  EXPECT_EQ(vft[1], -4);
  EXPECT_EQ(vft[41], -4);
  compare_with_std_vector(vft, vstd);

  vft.resize(65535, 2);
  vstd.resize(65535, 2);
  EXPECT_EQ(vft.size(), 65535);
  EXPECT_EQ(vft[0], 0);
  EXPECT_EQ(vft[1], -4);
  EXPECT_EQ(vft[41], -4);
  EXPECT_EQ(vft[42], 2);
  EXPECT_EQ(vft[65534], 2);
  compare_with_std_vector(vft, vstd);
  
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
// reserve (int)

TEST_F(VectorTest, int_reserve) {
  ft::vector<int> vft;
  std::vector<int> vstd;
  EXPECT_EQ(vft.size(), 0);
  compare_with_std_vector(vft, vstd);

  vft.reserve(0);
  vstd.reserve(0);
  EXPECT_EQ(vft.size(), 0);
  compare_with_std_vector(vft, vstd);

  vft.reserve(1);
  vstd.reserve(1);
  EXPECT_EQ(vft.size(), 0);
  EXPECT_EQ(vft.capacity(), 1);
  compare_with_std_vector(vft, vstd);

  vft.reserve(1);
  vstd.reserve(1);
  EXPECT_EQ(vft.size(), 0);
  EXPECT_EQ(vft.capacity(), 1);
  compare_with_std_vector(vft, vstd);

  vft.reserve(65535);
  vstd.reserve(65535);
  EXPECT_EQ(vft.size(), 0);
  EXPECT_EQ(vft.capacity(), 65535);
  compare_with_std_vector(vft, vstd);

  vft.reserve(1);
  vstd.reserve(1);
  EXPECT_EQ(vft.size(), 0);
  EXPECT_EQ(vft.capacity(), 65535);
  compare_with_std_vector(vft, vstd);

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

// TEST_F(VectorTest, int_size) {
//   ft::vector<int>::iterator vft_it = vft_.rbegin();
//   std::vector<int>::iterator vstd_it = vstd_.rbegin();

//   for (; vft_it != vft_.rend() && vstd_it != vstd_.rend(); ++vft_it, ++vstd_it)
//     EXPECT_EQ(*vft_it, *vstd_it);
// }







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

TEST_F(VectorTest, constructor_empty_string) {
  ft::vector<std::string> vft;
  std::vector<std::string> vstd;

  EXPECT_EQ(vft.size(), 0);
  EXPECT_TRUE(vft.empty());
  compare_with_std_vector(vft, vstd);
}

// TEST_F(VectorTest, constructor_init_with_same_value_int) {
//   ft::vector<std::string> vft(100, "hello");
//   std::vector<std::string> vstd(100, "hello");

//   EXPECT_EQ(vft.size(), 100);
//   EXPECT_EQ(vft[0], "hello");
//   EXPECT_EQ(vft[99], "hello");
//   EXPECT_FALSE(vft.empty());
//   compare_with_std_vector(vft, vstd);
// }
