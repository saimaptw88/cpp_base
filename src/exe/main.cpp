// Copyright 2022
#include "../my_math_dll/my_math.h"
#include "../hello_dll/hello.h"


int main(void) {
  std::cout << "my_math function sqr(3) = " << sqr(3) << std::endl;

  Hello h;
  h.hello();

  return 0;
}
