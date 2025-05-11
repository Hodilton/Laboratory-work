#pragma once

#include "./IFurnitureFactory.h"
#include "../furniture/VictorianFurniture.h"

class VictorianFactory : public IFurnitureFactory {
public:
    std::shared_ptr<IChair> createChair() const override {
        return std::make_shared<VictorianChair>();
    }

    std::shared_ptr<ISofa> createSofa() const override {
        return std::make_shared<VictorianSofa>();
    }

    std::shared_ptr<ICoffeeTable> createCoffeeTable() const override {
        return std::make_shared<VictorianCoffeeTable>();
    }
};