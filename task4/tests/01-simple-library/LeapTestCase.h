#pragma once

#include <gtest/gtest.h>

class LeapTestCase : public ::testing::Test {
 public:
  void TestLeapYears();
  void TestNotLeapYears();
  void TestLess0();
  void TestMonthDays();
  void TestAdd();
};
