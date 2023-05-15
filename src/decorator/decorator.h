// Copyright 2023 saito
#ifndef SRC_DECORATOR_DECORATOR_H_
#define SRC_DECORATOR_DECORATOR_H_

#include <iostream>
#include <memory>
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

// メール通知のみ提供していたサービスにSlackやFacebook、
// SMS通知を後から追加する必要が出てきた。
// また、SMSのみやメールのみだけでなく、SlackとSMSとメールに
// 通知が欲しいと組み合わせた通知の要望が増えた
class Notifier {
 public:
  virtual ~Notifier() {}
  virtual std::string send(const std::string&) const = 0;
};

// default notifier
class EmailNotifier : public Notifier {
 public:
  std::string send(const std::string& message) const override {
    return "email message: " + message;
  }
};

class NotifierDecorator : public Notifier {
 protected:
  Notifier* notifier_;

 public:
  NotifierDecorator(Notifier* notifier) : notifier_(notifier) {}

  std::string send(const std::string& message) const override {
    return this->notifier_->send(message);
  }
};

class FacebookDecorator : public NotifierDecorator {
 public:
  FacebookDecorator(Notifier* notifier) : NotifierDecorator(notifier) {}

  std::string send(const std::string& message) const override {
    return "facebook message: " + message + "\n" + NotifierDecorator::send(message);
  }
};

class SlackDecorator : public NotifierDecorator {
 public:
  SlackDecorator(Notifier* notifier) : NotifierDecorator(notifier) {}

  std::string send(const std::string& message) const override {
    return "slack message: " + message + "\n" + NotifierDecorator::send(message);
  }
};

class SmsDecorator : public NotifierDecorator {
 public:
  SmsDecorator(Notifier* notifier) : NotifierDecorator(notifier) {}

  std::string send(const std::string& message) const override {
    return "sms message: " + message + "\n" + NotifierDecorator::send(message);
  }
};

void client() {
  Notifier* notifier = new EmailNotifier;
  Notifier* facebook_notifier = new FacebookDecorator(notifier);
  Notifier* sms_notifier = new SmsDecorator(facebook_notifier);
  Notifier* slack_notifier = new SlackDecorator(sms_notifier);

  std::cout << slack_notifier->send("test message");

  delete slack_notifier;
  delete sms_notifier;
  delete facebook_notifier;
  delete notifier;
}

}  // namespace decorator

#endif  // SRC_DECORATOR_DECORATOR_H_
