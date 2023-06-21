// Copyright 2023 saito
#ifndef SRC_FACADE_FACADE_H_
#define SRC_FACADE_FACADE_H_


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
  Subsystem1 *subsystem1_;
  Subsystem2 *subsystem2_;

 public:
  Facade(Subsystem1 *subsystem1, Subsystem2 *subsystem2);
  ~Facade();
  std::string Operation();
};

void ClientCode(Facade *facade);
void execute();
}  // namespace facade
#endif  // SRC_FACADE_FACADE_H_
