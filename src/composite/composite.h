// Copyright 2023 saito
#ifndef SRC_COMPOSITE_COMPOSITE_H_
#define SRC_COMPOSITE_COMPOSITE_H_

#include <algorithm>
#include <iostream>
#include <list>
#include <string>


int sum(int, int);

class Component {
 protected:
  Component *parent_;

 public:
  virtual ~Component() {}

  void SetParent(Component* parent) {
    this->parent_ = parent;
  }

  Component* GetParent() const {
    return this->parent_;
  }

  virtual void Add(Component *component) {}
  virtual void Remove(Component *component) {}
  virtual bool IsComposite() const {
    return false;
  }
  virtual std::string Operation() const = 0;
};

class Leaf : public Component {
 public:
  std::string Operation() const override {
    return "Leaf";
  }
};

class Composite : public Component {
 protected:
  std::list<Component*> children_;

 public:
  void Add(Component* component) override {
    this->children_.push_back(component);
    component->SetParent(this);
  }

  void Remove(Component* component) override {
    children_.remove(component);
    component->SetParent(nullptr);
  }

  bool IsComposite() const override {
    return true;
  }

  std::string Operation() const override {
    std::string result;

    for (const Component* c: children_) {
      if (c == children_.back()) {
        result += c->Operation();
      } else {
        result += c->Operation() + "+";
      }
    }

    return "Branch(" + result + ")";
  }
};

void ClientCode(Component* component) {
  std::cout << "RESULT: " << component->Operation();
}

void ClientCode(Component* component1, Component* component2) {
  if (component1->IsComposite()) {
    component1->Add(component2);
  }

  std::cout << "RESULT: " << component1->Operation();
}

void execute_composite() {
  Component* simple = new Leaf();
  std::cout << "Client: I've got a simple component:\n";
  ClientCode(simple);
  std::cout << "\n\n";

  Component* tree = new Composite;
  Component* branch1 = new Composite;

  Component* leaf1 = new Leaf;
  Component* leaf2 = new Leaf;
  Component* leaf3 = new Leaf;

  branch1->Add(leaf1);
  branch1->Add(leaf2);

  Component* branch2 = new Composite;

  branch2->Add(leaf3);
  tree->Add(branch1);
  tree->Add(branch2);

  std::cout << "Client: Now I've got composite tree:\n";
  ClientCode(tree);
  std::cout << "\n\n";

  std::cout << "Client: I done't need to check the components classes even when manging the tree:\n";

  ClientCode(tree, simple);
  std::cout << "\n";

  delete simple;
  delete tree;
  delete branch1;
  delete branch2;
  delete leaf1;
  delete leaf2;
  delete leaf3;
}


#endif  // SRC_COMPOSITE_COMPOSITE_H_
