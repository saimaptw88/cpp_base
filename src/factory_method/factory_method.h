// Copyright 2023 saito
#ifndef SRC_FACTORY_METHOD_FACTORY_METHOD_H_
#define SRC_FACTORY_METHOD_FACTORY_METHOD_H_

#include <iostream>
#include <string>


int sum(int, int);

class Product {
 public:
  virtual ~Product() {};
  virtual std::string Operation() const = 0;
};

class ConcreteProduct1 : public Product {
 public:
  std::string Operation() const override {
    return "{Result of the ConcreteProduct1}";
  }
};

class ConcreteProduct2 : public Product {
 public:
  std::string Operation() const override {
    return "{Result of the ConcreteProduct2}";
  }
};

class Creator {
 public:
  virtual ~Creator() {};
  virtual Product* FactoryMethod() const = 0;

  std::string SomeOperation() const {
    Product* product = this->FactoryMethod();

    std::string result = "Creator: The same creator's code has just worked with " + product->Operation();

    delete product;
    return result;
  }
};

class ConcreteCreator1 : public Creator {
 public:
  Product* FactoryMethod() const override {
    return new ConcreteProduct1();
  }
};

class ConcreteCreator2 : public Creator {
 public:
  Product* FactoryMethod() const override {
    return new ConcreteProduct2();
  }
};

void ClientCode(const Creator& creator) {
  std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
            << creator.SomeOperation() << std::endl;
}

void execute_factory_method() {
  ConcreteCreator1* creator1 = new ConcreteCreator1();
  ClientCode(*creator1);
  delete creator1;

  ConcreteCreator2* creator2 = new ConcreteCreator2();
  ClientCode(*creator2);
  delete creator2;
}
#endif  // SRC_FACTORY_METHOD_FACTORY_METHOD_H_
