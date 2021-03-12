#include <gtest/gtest.h>
#include <B/lib.h>
#include <A/index.h>

TEST(mul, MulPositiveNumbers) {
  EXPECT_EQ(2, mul(1, 2));
  EXPECT_EQ(10340, mul(10, 1034));
  EXPECT_EQ(9, mul(9, 1));
}

TEST(sum, SumPositiveNumbers) {
  EXPECT_EQ(3, sum(1, 2));
  EXPECT_EQ(1044, sum(10, 1034));
  EXPECT_EQ(10, sum(9, 1));
  EXPECT_EQ(142842, sum(322, 142520));
}

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
