// Copyright 2023 saito
#include "../../src/prototype/prototype.h"


int sum(int a, int b) {
  return a + b;
}

namespace prototype {
void Client(PrototypeFactory &prototype_factory) {// NOLINT
  std::cout << "Let's create a Prototype 1\n";

  Prototype *prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_1);
  prototype->Method(90);
  delete prototype;

  std::cout << "\n";

  std::cout << "Let's create a Prototype 2\n";

  prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_2);
  prototype->Method(10);
  delete prototype;
}

void execute() {
  PrototypeFactory *prototype_factory = new PrototypeFactory();

  Client(*prototype_factory);

  delete prototype_factory;
}
}  // namespace prototype
