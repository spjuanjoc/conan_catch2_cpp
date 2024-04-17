#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace testing;

TEST(IntTest, AssertAndExpectInts) {
  // AAA
  // Arrange
  // Act
  // Assert
  ASSERT_THAT(1, Eq(1));
  EXPECT_THAT(2, Eq(2));
}

TEST(BoolTest, AssertAndExpectBools) {
  ASSERT_THAT(true, Eq(true));
  EXPECT_THAT(false, Eq(false));
}
