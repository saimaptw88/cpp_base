// Copyright 2023 saito
#include "../../src/builder/builder.h"


int sum(int a, int b) {
  return a + b;
}

void builder::ClientCode(Director& director) { // NOLINT
  ConcreteBuilder1* builder = new ConcreteBuilder1();
  director.set_builder(builder);
  std::cout << "Standard basic product:\n";
  director.BuildMinimalViableProduct();

  Product1* p = builder->GetProduct();
  p->ListParts();
  delete p;

  std::cout << "Standard full feature product:\n";
  director.BuildFullFeaturedProduct();

  p = builder->GetProduct();
  p->ListParts();
  delete p;

  std::cout << "Custom product:\n";
  builder->ProducePartA();
  builder->ProducePartC();
  p = builder->GetProduct();
  p->ListParts();
  delete p;

  delete builder;
}

void builder::execute() {
  Director* director = new Director();
  ClientCode(*director);
  delete director;
}
