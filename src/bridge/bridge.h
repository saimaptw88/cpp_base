// Copyright 2023 saito
#ifndef SRC_BRIDGE_BRIDGE_H_
#define SRC_BRIDGE_BRIDGE_H_

#include <iostream>
#include <memory>
#include <string>
#include <utility>


int sum(int, int);

namespace bridge {
class Implementation {
 public:
  virtual ~Implementation() {}
  virtual std::string OperationImplementation() const = 0;
};

class ConcreteImplementationA : public Implementation {
 public:
  std::string OperationImplementation() const override {
    return "ConcreteImplementationA: Here's the result on the platform A.\n";
  }
};

class ConcreteImplementationB : public Implementation {
 public:
  std::string OperationImplementation() const override {
    return "ConcreteImplementationB: Here's the result on the platform B.\n";
  }
};

class Abstraction {
 protected:
  std::unique_ptr<Implementation> implementation_ = nullptr;

 public:
  explicit Abstraction(std::unique_ptr<Implementation> implementation)
    : implementation_(std::move(implementation)) {}

  virtual ~Abstraction() {}
  virtual std::string Operation() const {
    return "Abstraction: Base operation with: \n" +
      this->implementation_->OperationImplementation();
  }
};

class ExtendedAbstraction : public Abstraction {
 public:
  explicit ExtendedAbstraction(std::unique_ptr<Implementation> implementation)
    : Abstraction(std::move(implementation)) {}

  std::string Operation() const override {
    return "ExtendedAbstraction: Extended operation with: \n" +
      this->implementation_->OperationImplementation();
  }
};

void ClientCode(std::unique_ptr<Abstraction> abstraction) {
  std::cout << abstraction->Operation();
}

void execute() {
  std::unique_ptr<Implementation> Implementation(new ConcreteImplementationA());
  std::unique_ptr<Abstraction> abstraction(
    new ExtendedAbstraction(std::move(Implementation)));

  ClientCode(std::move(abstraction));
  std::cout << std::endl;
}
}  // namespace bridge

#endif  // SRC_BRIDGE_BRIDGE_H_
