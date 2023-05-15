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
  factory_method::execute();
  prototype::execute();
  builder::execute();
  singleton::execute();
  adapta::execute();
  bridge::execute();
  composite::execute();
  decorator::execute();

  return 0;
}
