// Copyright 2023 saito
#ifndef SRC_DECORATOR_DECORATOR_H_
#define SRC_DECORATOR_DECORATOR_H_

#include <iostream>
#include <string>


int sum(int, int);

namespace decorator {
class Component {
 public:
  virtual ~Component() {}
  virtual std::string Operation() const = 0;
};

class ConcreteComponent : public Component {
 public:
  std::string Operation() const override {
    return "ConcreteComponent";
  }
};

class Decorator : public Component {
 protected:
  Component* component_;

 public:
  Decorator(Component* component): component_(component) {}

  std::string Operation() const override {
    return this->component_->Operation();
  }
};

class ConcreteDecoratorA : public Decorator {
 public:
  ConcreteDecoratorA(Component* component): Decorator(component) {}

  std::string Operation() const override {
    return "ConcreteDecotatorA(" + Decorator::Operation() + ")";
  }
};

class ConcreteDecoratorB : public Decorator {
 public:
  ConcreteDecoratorB(Component* component) : Decorator(component) {}

  std::string Operation() const override {
    return "ConcreteDecoratorB(" + Decorator::Operation() + ")";
  }
};

void ClientCode(Component* component) {
  std::cout << "Result: " << component->Operation();
}

void execute() {
  Component* simple = new ConcreteComponent;

  std::cout << "Client: I've got a simple component:\n";
  ClientCode(simple);
  std::cout << "\n\n";

  Component* decorator1 = new ConcreteDecoratorA(simple);
  Component* decorator2 = new ConcreteDecoratorB(decorator1);
  std::cout << "Client: Now I've got ad decorated component:\n";
  ClientCode(decorator2);
  std::cout << "\n";

  delete simple;
  delete decorator1;
  delete decorator2;
}
}  // namespace decorator

#endif  // SRC_DECORATOR_DECORATOR_H_
