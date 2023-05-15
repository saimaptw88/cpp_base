// Copyright 2023 saito
#ifndef SRC_SINGLETON_SINGLETON_H_
#define SRC_SINGLETON_SINGLETON_H_

#include <chrono>  // NOLINT
#include <iostream>
#include <mutex>  // NOLINT
#include <string>
#include <thread>  // NOLINT


int sum(int, int);

namespace singleton {
class Singleton {
 private:
  static Singleton* pinstance_;
  static std::mutex mutex_;

 protected:
  explicit Singleton(const std::string value): value_(value) {}
  ~Singleton() {}

  std::string value_;

 public:
  Singleton(Singleton &other) = delete;  // NOLINT
  void operator=(const Singleton &) = delete;

  static Singleton *GetInstance(const std::string &value);
  void SomeBusinessLogic() { return; }
  std::string value() const { return value_; }
};

void ThreadFoo();
void ThreadBar();

void execute();
}  // namespace singleton

#endif  // SRC_SINGLETON_SINGLETON_H_
