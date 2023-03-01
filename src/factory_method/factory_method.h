// Copyright 2023 saito
#ifndef SRC_FACTORY_METHOD_FACTORY_METHOD_H_
#define SRC_FACTORY_METHOD_FACTORY_METHOD_H_

#include <iostream>
#include <string>


int sum(int, int);

class Transport {
 public:
  virtual ~Transport() {};
  virtual std::string deliver() const = 0;
};

class Truck : public Transport {
 public:
  std::string deliver() const override {
    return "transport by truck";
  }
};

class Ship : public Transport {
 public:
  std::string deliver() const override {
    return "transport by ship";
  }
};

class Logistics {
 public:
  virtual ~Logistics() {};
  virtual Transport* createTransport() const = 0;

  std::string deliveration() const {
    Transport* transport = this->createTransport();

    std::string result = transport->deliver();

    delete transport;
    return result;
  }
};

class RoadLogistics : public Logistics {
 public:
  Transport* createTransport() const override {
    return new Truck();
  }
};

class SeaLogistics : public Logistics {
 public:
  Transport* createTransport() const override {
    return new Ship();
  }
};

void ClientCode(const Logistics& logistics) {
  std::cout << logistics.deliveration() << std::endl;
}

void execute_factory_method() {
  Logistics* road_logistics = new RoadLogistics();
  ClientCode(*road_logistics);
  delete road_logistics;

  Logistics* sea_logistics = new SeaLogistics();
  ClientCode(*sea_logistics);
  delete sea_logistics;
}
#endif  // SRC_FACTORY_METHOD_FACTORY_METHOD_H_
