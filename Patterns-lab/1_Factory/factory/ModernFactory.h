#pragma once

#include "./IFurnitureFactory.h"
#include "../furniture/ModernFurniture.h"

class ModernFactory : public IFurnitureFactory {
public:
    std::shared_ptr<IChair> createChair() const override {
        return std::make_shared<ModernChair>();
    }

    std::shared_ptr<ISofa> createSofa() const override {
        return std::make_shared<ModernSofa>();
    }

    std::shared_ptr<ICoffeeTable> createCoffeeTable() const override {
        return std::make_shared<ModernCoffeeTable>();
    }
};