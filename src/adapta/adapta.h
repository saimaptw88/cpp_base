// Copyright 2023 saito
#ifndef SRC_ADAPTA_ADAPTA_H_
#define SRC_ADAPTA_ADAPTA_H_

#include <algorithm>
#include <iostream>
#include <string>


int sum(int, int);

class Target {
 public:
  virtual ~Target() = default;

  virtual std::string Request() const {
    return "Traget: The default target's behavior.";
  }
};

class Adaptee {
 public:
    std::string SpecificRequest() const {
      return ".eetpadA eht fo roivaheb laicepS";
    }
};

class Adapter: public Target {
 private:
    Adaptee *adaptee_;

 public:
    explicit Adapter(Adaptee *adaptee) : adaptee_(adaptee) {}
    std::string Request() const override {
      std::string to_reverse = this->adaptee_->SpecificRequest();
      std::reverse(to_reverse.begin(), to_reverse.end());
      return "Adapter: (TRANSLATED) " + to_reverse;
    }
};

void ClientCode(const Target *target) {
  std::cout << target->Request() << std::endl;
}

void execute_adapta() {
  std::cout << "Client: I can work just fine with the Target objects:"
            << std::endl;
  Target *target = new Target;
  ClientCode(target);

  std::cout << "\n\n";
  Adaptee *adaptee = new Adaptee;
  std::cout << "Client: The Adaptee class has a weird interface.";
  std::cout << " See, I don't understand it:\n";
  std::cout << "\n\n";
  std::cout << "Client: But I can work with it via the Adapter:\n";
  Adapter *adapter = new Adapter(adaptee);
  ClientCode(adapter);
  std::cout << "\n";

  delete target;
  delete adaptee;
  delete adapter;
}
#endif  // SRC_ADAPTA_ADAPTA_H_
