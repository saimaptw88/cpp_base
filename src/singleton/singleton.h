// Copyright 2023 saito
#ifndef SRC_SINGLETON_SINGLETON_H_
#define SRC_SINGLETON_SINGLETON_H_

#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>


int sum(int, int);

class Singleton {
 private:
  static Singleton* pinstance_;
  static std::mutex mutex_;

 protected:
  Singleton(const std::string value): value_(value) {}
  ~Singleton() {}

  std::string value_;

 public:
  Singleton(Singleton &other) = delete;
  void operator=(const Singleton &) = delete;

  static Singleton *GetInstance(const std::string &value);
  void SomeBusinessLogic() { return; }
  std::string value() const { return value_; }
};

void ThreadFoo();
void ThreadBar();

void execute_singleton();

#endif  // SRC_SINGLETON_SINGLETON_H_
