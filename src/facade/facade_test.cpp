// Copyright 2023 saito
#include "../../src/facade/facade.h"
#include <gtest/gtest.h>

TEST(facade, sum_test) {
  EXPECT_EQ(3, sum(1, 2));
}

