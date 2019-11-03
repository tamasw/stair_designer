#include "gtest/gtest.h"

#include "util/Optional.hpp"

using namespace util;

TEST(UtilTest, optional_empty)
{
    Optional<int> optional = Optional<int>::empty();
    ASSERT_FALSE(optional.available());
}

TEST(UtilTest, optional_of)
{
    Optional<int> optional = Optional<int>::of(12);
    ASSERT_TRUE(optional.available());
    ASSERT_EQ(optional.get(), 12);
}

TEST(UtilTest, optional_changing_value)
{
    Optional<int> optional = Optional<int>::of(12);
    optional.get()++;
    ASSERT_TRUE(optional.available());
    ASSERT_EQ(optional.get(), 13);
}

TEST(UtilTest, optional_copy_construct)
{
    Optional<int> optional1 = Optional<int>::of(12);
    Optional<int> optional2(optional1);
    optional2.get()++;
    ASSERT_TRUE(optional1.available());
    ASSERT_EQ(optional1.get(), 12);
    ASSERT_TRUE(optional2.available());
    ASSERT_EQ(optional2.get(), 13);
}

TEST(UtilTest, optional_move_construct)
{
    Optional<int> optional1 = Optional<int>::of(12);
    Optional<int> optional2(std::move(optional1));
    optional2.get()++;
    ASSERT_FALSE(optional1.available());
    ASSERT_TRUE(optional2.available());
    ASSERT_EQ(optional2.get(), 13);
}