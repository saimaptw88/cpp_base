// Copyright 2023 saito
#ifndef SRC_ABSTRACT_FACTORY_ABSTRACT_FACTORY_H_
#define SRC_ABSTRACT_FACTORY_ABSTRACT_FACTORY_H_

#include <iostream>


int sum(int, int);

namespace abstract_factory {
class Chair {
 public:
  virtual ~Chair() {}
  virtual bool hasLegs() const = 0;
  virtual void sitOn() const = 0;
};

class VictorianChair : public Chair {
 public:
  bool hasLegs() const override {
    return true;
  }
  void sitOn() const override {
    std::cout << "sit on the victorian chair" << std::endl;
  }
};

class ModenChair : public Chair {
 public:
  bool hasLegs() const override {
    return false;
  }
  void sitOn() const override {
    std::cout << "sit on the moden chair" << std::endl;
  }
};

class CoffeeTable {
 public:
  virtual ~CoffeeTable() {}
  virtual bool hasLegs() const = 0;
  virtual void putOn() const = 0;
};

class VictorianCoffeeTable : public CoffeeTable {
 public:
  bool hasLegs() const override {
    return true;
  }
  void putOn() const override {
    std::cout << "put on something on the victroan coffee table" << std::endl;
  }
};

class ModenCoffeeTable : public CoffeeTable {
 public:
  bool hasLegs() const override {
    return false;
  }
  void putOn() const override {
    std::cout << "put on something on the moden coffee table" << std::endl;
  }
};

class FurnitureFactory {
 public:
  virtual Chair* createChair() const = 0;
  virtual CoffeeTable* createCoffeeTable() const = 0;
};

class VictorianFurnitureFactory : public FurnitureFactory {
 public:
  Chair* createChair() const override {
    return new VictorianChair();
  }
  CoffeeTable* createCoffeeTable() const override {
    return new VictorianCoffeeTable();
  }
};

class ModenFurnitureFactory : public FurnitureFactory {
 public:
  Chair* createChair() const override {
    return new ModenChair();
  }
  CoffeeTable* createCoffeeTable() const override {
    return new ModenCoffeeTable();
  }
};

inline void application(const FurnitureFactory& furniture) {
  const Chair* chair = furniture.createChair();
  const CoffeeTable* coffee_table = furniture.createCoffeeTable();

  std::cout << "furnitures have legs?" << std::endl;
  std::cout << "chair: " << chair->hasLegs() << std::endl;
  std::cout << "coffee table: " << coffee_table->hasLegs() << std::endl;

  std::cout << "\nfurnitures actions" << std::endl;
  chair->sitOn();
  coffee_table->putOn();

  delete chair;
  delete coffee_table;
}

inline void execute() {
  ModenFurnitureFactory* moden_furniture = new ModenFurnitureFactory();
  application(*moden_furniture);
  delete moden_furniture;

  VictorianFurnitureFactory* victorian_furniture =
  new VictorianFurnitureFactory();
  application(*victorian_furniture);
  delete victorian_furniture;
}
}  // namespace abstract_factory

#endif  // SRC_ABSTRACT_FACTORY_ABSTRACT_FACTORY_H_
