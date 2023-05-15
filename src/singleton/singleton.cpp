// Copyright 2023 saito
#include "../../src/singleton/singleton.h"


int sum(int a, int b) {
  return a + b;
}

namespace singleton {
Singleton *Singleton::pinstance_{ nullptr };
std::mutex Singleton::mutex_;

Singleton *Singleton::GetInstance(const std::string &value) {
  std::lock_guard<std::mutex> lock(mutex_);

  if (pinstance_ == nullptr) {
    pinstance_ = new Singleton(value);
  }

  return pinstance_;
}

void ThreadFoo() {
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  Singleton* singleton = Singleton::GetInstance("FOO");
  std::cout << singleton->value() << std::endl;
}

void ThreadBar() {
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  Singleton* singleton = Singleton::GetInstance("Bar");
  std::cout << singleton->value() << std::endl;
}

void execute() {
  std::cout << "If you see the same value, then singleton was reused (yay!\n"
  << "If you see different values 2 singletons were created (booo!)\n\n"
  << "RESULT:" << std::endl;

  std::thread t1(ThreadFoo);
  std::thread t2(ThreadBar);

  t1.join();
  t2.join();
}
}  // namespace singleton
