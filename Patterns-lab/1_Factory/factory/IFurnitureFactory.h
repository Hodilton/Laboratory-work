#pragma once

#include "../furniture/Interfaces.h"

#include <memory>

class IFurnitureFactory {
public:
    virtual std::shared_ptr<IChair> createChair() const = 0;
    virtual std::shared_ptr<ISofa> createSofa() const = 0;
    virtual std::shared_ptr<ICoffeeTable> createCoffeeTable() const = 0;
    virtual ~IFurnitureFactory() = default;
};