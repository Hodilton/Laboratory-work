#pragma once

//class IFurniture {
//public:
//    virtual void getType() const = 0;
//    virtual ~IFurniture() = default;
//};


class IChair /*: public IFurniture*/ {
public:
    virtual bool hasLegs() const = 0;
    virtual void sitOn() const = 0;
    virtual ~IChair() = default;
};

class ISofa /*: public IFurniture*/ {
public:
    virtual bool hasLegs() const = 0;
    virtual void lieOn() const = 0;
    virtual ~ISofa() = default;
};

class ICoffeeTable /*: public IFurniture*/ {
public:
    virtual bool hasLegs() const = 0;
    virtual void placeItems() const = 0;
    virtual ~ICoffeeTable() = default;
};