// Copyright 2022
#include "../abstract_factory/abstract_factory.h"
#include "../builder/builder.h"
#include "../factory_method/factory_method.h"
#include "../prototype/prototype.h"
#include "../singleton/singleton.h"
#include "../adapta/adapta.h"
#include "../bridge/bridge.h"
#include "../composite/composite.h"
#include "../decorator/decorator.h"


int main(void) {
  execute_abstract_factory();
  execute_factory_method();
  execute_prototype();
  execute_builder();
  execute_singleton();
  execute_adapta();
  execute_bridge();
  execute_composite();
  decorator::execute();

  return 0;
}
