// Copyright 2023 saito
#ifndef SRC_FACADE_FACADE_H_
#define SRC_FACADE_FACADE_H_


#include <memory>
#include <string>

namespace facade {
class Subsystem1 {
 public:
  std::string Operation1() const;
  std::string OperationN() const;
};

class Subsystem2 {
 public:
  std::string Operation1() const;
  std::string OperationZ() const;
};

class Facade {
 protected:
  std::unique_ptr<Subsystem1> subsystem1_;
  std::unique_ptr<Subsystem2> subsystem2_;

 public:
  Facade(std::unique_ptr<Subsystem1>, std::unique_ptr<Subsystem2>);
  virtual ~Facade() {};

  std::string Operation();
};

void ClientCode(std::unique_ptr<Facade>);
void execute();
}  // namespace facade
#endif  // SRC_FACADE_FACADE_H_
