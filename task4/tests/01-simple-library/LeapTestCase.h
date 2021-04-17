#pragma once

#include <gtest/gtest.h>

class LeapTestCase : public ::testing::Test {
 public:
  void TestLeapYears();
  void TestNotLeapYears();
  void Less0();
  void TestMonthDays();
};
