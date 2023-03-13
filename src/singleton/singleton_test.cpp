// Copyright 2023 saito
#include "../../src/singleton/singleton.h"
#include <gtest/gtest.h>

TEST(singleton, sum_test) {
  EXPECT_EQ(3, sum(1, 2));
}

