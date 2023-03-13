// Copyright 2023 saito
#include "../../src/factory_method/factory_method.h"
#include <gtest/gtest.h>

TEST(factory_method, sum_test) {
  EXPECT_EQ(3, sum(1, 2));
}

