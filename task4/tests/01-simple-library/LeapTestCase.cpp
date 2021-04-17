#include "LeapTestCase.h"

#include <Functions.h>

void LeapTestCase::TestLeapYears() {
  ASSERT_EQ(IsLeap(1764), true);
  ASSERT_EQ(IsLeap(1768), true);
  ASSERT_EQ(IsLeap(1772), true);
  ASSERT_EQ(IsLeap(1776), true);
  ASSERT_EQ(IsLeap(1780), true);
  ASSERT_EQ(IsLeap(1600), true);
}
void LeapTestCase::TestNotLeapYears() {
  ASSERT_EQ(IsLeap(1765), false);
  ASSERT_EQ(IsLeap(1766), false);
  ASSERT_EQ(IsLeap(1767), false);
  ASSERT_EQ(IsLeap(1769), false);
  ASSERT_EQ(IsLeap(1770), false);
  ASSERT_EQ(IsLeap(1771), false);
  ASSERT_EQ(IsLeap(1773), false);
  ASSERT_EQ(IsLeap(1774), false);
  ASSERT_EQ(IsLeap(1775), false);
  ASSERT_EQ(IsLeap(1700), false);
}
void LeapTestCase::TestLess0() {
  EXPECT_THROW(IsLeap(-10), std::invalid_argument);
}
void LeapTestCase::TestMonthDays() {
  ASSERT_EQ(GetMonthDays(2020, 2), 29);
  ASSERT_EQ(GetMonthDays(2021, 2), 28);
  ASSERT_EQ(GetMonthDays(2020, 4), 30);
  ASSERT_EQ(GetMonthDays(2020, 5), 31);
  EXPECT_THROW(GetMonthDays(-10, -10), std::invalid_argument);
  EXPECT_THROW(GetMonthDays(10, -10), std::invalid_argument);
}
void LeapTestCase::TestAdd() {
  EXPECT_EQ(Add(1, 2), 3);
  EXPECT_EQ(Add(-1, -2), -3);
  EXPECT_EQ(Add(-1, 2), 1);
}

TEST_F (LeapTestCase, TestIsLeap) {
  TestLeapYears();
  TestNotLeapYears();
  TestLess0();
}

TEST_F (LeapTestCase, TestGetMonthDays) {
  TestMonthDays();
}

TEST_F(LeapTestCase, TestAdd) {
  TestAdd();
}