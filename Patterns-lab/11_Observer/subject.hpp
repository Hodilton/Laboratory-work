#pragma once
#include "./observer.hpp"
#include <vector>

class Subject {
public:
    void Attach(Observer* observer) {
        observers.push_back(observer);
    }

    void Detach(Observer* observer) {
        observers.erase(
            std::remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }

    void Notify() {
        for (Observer* observer : observers) {
            observer->Update(this);
        }
    }

private:
    std::vector<Observer*> observers;
};