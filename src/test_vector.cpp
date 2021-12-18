#include "vector.hpp"

class VectorTest : public ::testing::Test {
    protected:
    VectorTest() {
        // v_ = new ft::vector<int>();
    }
    ~VectorTest() {
        // delete v_;
    }
    ft::vector<int> v_;
};

TEST_F(VectorTest, test_vector_fixturetest)
{
    v_.push_back(42);
    EXPECT_EQ(v_[0], 42);
    EXPECT_EQ(v_.size(), 1);
}

TEST(vector, test_vector_constructor)
{
    ft::vector<int> v;
    v.push_back(42);
    EXPECT_EQ(v[0], 42);
    EXPECT_EQ(v.size(), 1);
    
    EXPECT_TRUE(true);
    EXPECT_FALSE(false);
}

TEST(vector, test_vector_basic)
{
    ft::vector<int> v;
    v.push_back(42);
    v.push_back(21);
    EXPECT_EQ(v[0], 42);
    EXPECT_EQ(v[1], 21);
    EXPECT_EQ(v.size(), 2);
}

TEST(vector, test_vector_basic_compare)
{
    std::vector<int> vstd;
    ft::vector<int> vft;
    vstd.push_back(42);
    vft.push_back(42);
    vstd.push_back(21);
    vft.push_back(21);
    EXPECT_EQ(vstd[0], vft[0]);
    EXPECT_EQ(vstd[1], vft[1]);
    EXPECT_EQ(vstd.size(), vft.size());
}

