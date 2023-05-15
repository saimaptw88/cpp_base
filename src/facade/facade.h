// Copyright 2023 saito
#ifndef SRC_FACADE_FACADE_H_
#define SRC_FACADE_FACADE_H_

#include <iostream>
#include <memory>
#include <string>
#include <utility>


int sum(int, int);

namespace facade {
class Subsystem1 {
 public:
  std::string Operation1() const {
    return "Subsystem1: Ready!\n";
  }

  std::string OperationN() const {
    return "Subsystem1: Go!\n";
  }
};

class Subsystem2 {
 public:
  std::string Operation1() const {
    return "Subsystem2: Get ready!\n";
  }

  std::string OperationZ() const {
    return "Subsystem2: Fire!\n";
  }
};

class Facade {
 protected:
  std::unique_ptr<Subsystem1> subsystem1_ = nullptr;
  std::unique_ptr<Subsystem2> subsystem2_ = nullptr;

 public:
  Facade(
    std::unique_ptr<Subsystem1> subsystem1 = nullptr,
    std::unique_ptr<Subsystem2> subsystem2 = nullptr
  ) {
    this->subsystem1_ = subsystem1 ?
      std::move(subsystem1)
      : std::make_unique<Subsystem1>();

    this->subsystem2_ = subsystem2 ? std::move(subsystem2)
      : std::make_unique<Subsystem2>();
  }

  std::string Operation() {
    std::string result = "Facade initializes subsystems:\n";
    result += this->subsystem1_->Operation1();
    result += this->subsystem2_->Operation1();
    result += "Facade orders subsystems to perform the action:\n";
    result += this->subsystem1_->OperationN();
    result += this->subsystem2_->OperationZ();

    return result;
  }
};

void ClientCode(std::unique_ptr<Facade> facade) {
  std::cout << facade->Operation();
}

void execute() {
  std::unique_ptr<Subsystem1> subsystem1(new Subsystem1);
  std::unique_ptr<Subsystem2> subsystem2(new Subsystem2);
  std::unique_ptr<Facade> facade(
    new Facade(std::move(subsystem1), std::move(subsystem2)));

  ClientCode(std::move(facade));
}
}  // namespace facade
#endif  // SRC_FACADE_FACADE_H_
