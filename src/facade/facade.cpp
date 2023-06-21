// Copyright 2023 saito
#include <iostream>

#include "../../src/facade/facade.h"


namespace facade {
std::string Subsystem1::Operation1() const {
  return "Subsystem1: Ready!\n";
}

std::string Subsystem1::OperationN() const {
  return "Subsystem1: Go!\n";
}

std::string Subsystem2::Operation1() const {
  return "Subsystem2: Get ready!\n";
}

std::string Subsystem2::OperationZ() const {
  return "Subsystem2: Fire!\n";
}

Facade::Facade(std::unique_ptr<Subsystem1> subsystem1=nullptr,
               std::unique_ptr<Subsystem2> subsystem2=nullptr) {
  if (!this->subsystem1_)
    this->subsystem1_ = std::make_unique<Subsystem1>();

  if (!this->subsystem2_)
    this->subsystem2_ = std::make_unique<Subsystem2>();
}


std::string Facade::Operation() {
  std::string result = "Facade initializes subsystems: \n";

  result += this->subsystem1_->Operation1();
  result += this->subsystem2_->Operation1();
  result += "Facade orders subsystems to perform the action:\n";
  result += this->subsystem1_->OperationN();
  result += this->subsystem2_->OperationZ();

  return result;
}

void ClientCode(std::unique_ptr<Facade> facade) {
  std::cout << facade->Operation() << std::endl;
}

void execute() {
  std::unique_ptr<Subsystem1> subsystem1(new Subsystem1());
  std::unique_ptr<Subsystem2> subsystem2(new Subsystem2());

  std::unique_ptr<Facade> facade(new Facade(
    std::move(subsystem1), std::move(subsystem2)));

  ClientCode(std::move(facade));
}
}  // namespace facade
