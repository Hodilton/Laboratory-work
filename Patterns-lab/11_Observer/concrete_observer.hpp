#pragma once
#include "./observer.hpp"
#include "./concrete_subject.hpp"
#include <iostream>

class ConcreteObserver : public Observer {
public:
    ConcreteObserver(ConcreteSubject* subj) : subject(subj) {}

    void Update(Subject* changedSubject) override {
        if (changedSubject == subject) {
            observerState = subject->GetState();
            std::cout << "Observer State update to: " << observerState << std::endl;
        }
    }

private:
    ConcreteSubject* subject;
    int observerState = 0;
};