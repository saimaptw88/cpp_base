// Copyright 2022 saito
#include <gtest/gtest.h>
#include "../../src/hello_dll/hello.h"

namespace {
  class MyLibTest : public ::testing::Test{};

  Hello h;

  TEST_F(MyLibTest, helloCheck) {
    EXPECT_NO_THROW(h.hello());
  }
}  // namespace
