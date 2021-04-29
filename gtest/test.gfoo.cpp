#include "gtest/gtest.h"
//#include "gmock/gmock.h"

TEST(IntTest, AssertAndExpectInts)
{
  ASSERT_EQ(1, 1);
  EXPECT_EQ(2, 2);
}

TEST(BoolTest, AssertAndExpectBools)
{
  ASSERT_TRUE(true);
  EXPECT_FALSE(false);
}