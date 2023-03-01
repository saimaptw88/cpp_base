// Copyright 2022
#include "../my_math_dll/my_math.h"
#include "../hello_dll/hello.h"
#include "../abstract_factory/abstract_factory.h"


int main(void) {
  ModenFurnitureFactory* moden_furniture = new ModenFurnitureFactory();
  application(*moden_furniture);
  delete moden_furniture;

  VictorianFurnitureFactory* victorian_furniture = new VictorianFurnitureFactory();
  application(*victorian_furniture);
  delete victorian_furniture;

  return 0;
}
