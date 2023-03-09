// Copyright 2022
#include "../my_math_dll/my_math.h"
#include "../hello_dll/hello.h"
#include "../abstract_factory/abstract_factory.h"
#include "../builder/builder.h"
#include "../factory_method/factory_method.h"
#include "../prototype/prototype.h"


int main(void) {
  execute_abstract_factory();
  execute_factory_method();
  execute_prototype();
  execute_builder();

  return 0;
}
