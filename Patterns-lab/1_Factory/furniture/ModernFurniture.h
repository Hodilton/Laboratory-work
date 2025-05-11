#pragma once

#include "./Interfaces.h"

#include <iostream>

class ModernChair : public IChair {
public:
    void sitOn() const override {
        std::cout << "Сидите на модерн-кресле.\n";
    }

    bool hasLegs() const override {
        return true;
    }
};

class ModernSofa : public ISofa {
public:
    void lieOn() const override {
        std::cout << "Лежите на модерн-диване.\n";
    }

    bool hasLegs() const override {
        return true;
    }
};

class ModernCoffeeTable : public ICoffeeTable {
public:
    void placeItems() const override {
        std::cout << "Размещаете вещи на модерн-столике.\n";
    }

    bool hasLegs() const override {
        return true;
    }
};