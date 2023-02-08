// Copyright 2022 saito
#include "../../src/hello_dll/hello.h"
#include <gtest/gtest.h>


TEST(hello_dll, hello_test) {
  Hello h;
  EXPECT_EQ(0, h.hello());
}
