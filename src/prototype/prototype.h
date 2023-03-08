// Copyright 2023 saito
#ifndef SRC_PROTOTYPE_PROTOTYPE_H_
#define SRC_PROTOTYPE_PROTOTYPE_H_

#include <iostream>
#include <string>
#include <unordered_map>


enum Type {
  PROTOTYPE_1 = 0,
  PROTOTYPE_2,
};

int sum(int, int);

class Prototype {
 protected:
  std::string prototype_name_;
  float prototype_field_;

 public:
  Prototype() {}
  explicit Prototype(std::string prototype_name)
  : prototype_name_(prototype_name) {}

  virtual ~Prototype() {}
  virtual Prototype* Clone() const = 0;
  virtual void Method(float prototype_field) {
    this->prototype_field_ = prototype_field;

    std::cout << "Call Method() from " <<
    prototype_name_ << " with field : " <<
    prototype_field_ << std::endl;
  }
};

class ConcretePrototype1 : public Prototype {
 private:
  float concrete_prototype_field1_;

 public:
  ConcretePrototype1(std::string prototype_name,
                     float concrete_prototype_field)
    : Prototype(prototype_name),
      concrete_prototype_field1_(concrete_prototype_field) { }

  Prototype *Clone() const override {
    return new ConcretePrototype1(*this);
  }
};

class ConcretePrototype2 : public Prototype {
 private:
  float concrete_prototype_field2_;

 public:
  ConcretePrototype2(std::string prototype_name,
                     float concrete_prototype_field)
    : Prototype(prototype_name),
      concrete_prototype_field2_(concrete_prototype_field) {}

  Prototype *Clone() const override {
    return new ConcretePrototype2(*this);
  }
};

class PrototypeFactory {
 private:
  std::unordered_map<Type, Prototype *, std::hash<int>> prototypes_;

 public:
  PrototypeFactory() {
    prototypes_[Type::PROTOTYPE_1] = new ConcretePrototype1("prototype1", 50.f);
    prototypes_[Type::PROTOTYPE_2] = new ConcretePrototype2("prototype2", 60.f);
  }

  ~PrototypeFactory() {
    delete prototypes_[Type::PROTOTYPE_1];
    delete prototypes_[Type::PROTOTYPE_2];
  }

  Prototype *CreatePrototype(Type type) {
    return prototypes_[type]->Clone();
  }
};

void Client(PrototypeFactory &prototype_factory);
void execute_prototype();

#endif  // SRC_PROTOTYPE_PROTOTYPE_H_
