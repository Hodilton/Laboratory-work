#pragma once

#include <iostream>
#include <string>

namespace prototype {

    class IPrototype {
    public:
        virtual IPrototype* clone() const = 0;
        virtual void print() const = 0;
    };

    class CarPrototypeA : public IPrototype {
    protected:
        int _power;
        int* _axel;
        std::string _model;

    public:
        CarPrototypeA(int power, int* axel, std::string model)
            : _power(power), _axel(axel), _model(model) {}

        CarPrototypeA(const CarPrototypeA& prototype) {
            _power = prototype._power;
            _axel = new int(*(prototype._axel));
            _model = prototype._model;
        }

    public:
        CarPrototypeA* clone() const override {
            return new CarPrototypeA(*this);
        }

        void print() const override {
            std::cout << "CarPrototypeA:\n"
                << "power: " << _power << ";\n"
                << "axel: " << _axel << ";\n"
                << "model: " << _model << ".\n"
                << std::endl;
        }
    };

    class CarPrototypeB : public CarPrototypeA {
    private:
        int field2;
    public:
        CarPrototypeB(int f1 = 0, int f2 = 0) : CarPrototypeA(f1), field2(f2) {}

        // Конструктор копирования подкласса
        SubclassPrototype(const SubclassPrototype& prototype) : ConcretePrototype(prototype) {
            field2 = prototype.field2;
        }

        // Метод клонирования для подкласса
        Prototype* clone() const override {
            return new SubclassPrototype(*this);
        }

        void print() const override {
            std::cout << "SubclassPrototype: field1 = " << field1 << ", field2 = " << field2 << std::endl;
        }
    };
}