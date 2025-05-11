#pragma once

#include "./IFurnitureFactory.h"
#include "../furniture/ArdekoFurniture.h"

class ArdekoFactory : public IFurnitureFactory {
public:
    std::shared_ptr<IChair> createChair() const override {
        return std::make_shared<ArdekoChair>();
    }

    std::shared_ptr<ISofa> createSofa() const override {
        return std::make_shared<ArdekoSofa>();
    }

    std::shared_ptr<ICoffeeTable> createCoffeeTable() const override {
        return std::make_shared<ArdekoCoffeeTable>();
    }
};