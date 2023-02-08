// Copyright 2022 saito
#include "../../src/my_math_dll/my_math.h"
#include <gtest/gtest.h>


TEST(my_math_dll, sum_test) {
  EXPECT_EQ(3.0, sum(1.0, 2.0));
}

TEST(my_math_dll, sqr_test) {
  EXPECT_EQ(4.0, sqr(2.0));
}
