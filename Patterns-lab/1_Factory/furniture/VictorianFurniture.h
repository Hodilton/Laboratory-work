#pragma once

#include "./Interfaces.h"

#include <iostream>

class VictorianChair : public IChair {
public:
    void sitOn() const override {
        std::cout << "Сидите на викторианском кресле.\n";
    }

    bool hasLegs() const override {
        return true;
    }
};

class VictorianSofa : public ISofa {
public:
    void lieOn() const override {
        std::cout << "Лежите на викторианском диване.\n";
    }

    bool hasLegs() const override {
        return true;
    }
};

class VictorianCoffeeTable : public ICoffeeTable {
public:
    void placeItems() const override {
        std::cout << "Размещаете вещи на викторианском столике.\n";
    }

    bool hasLegs() const override {
        return true;
    }
};