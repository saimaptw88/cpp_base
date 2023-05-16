// Copyright 2023 saito
#include "../../src/flyweight/flyweight.h"
#include <gtest/gtest.h>

TEST(flyweight, sum_test) {
  EXPECT_EQ(3, sum(1, 2));
}

