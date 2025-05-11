#pragma once

#include <iostream>
#include <string>

namespace adapter_1 {

    using Data = std::string;
    using SpecialData = std::string;

    class IInterface {
    public:
        virtual void method(const Data data) = 0;
    };

    class Service {
    public:
        void serviceMethod(const SpecialData& specialData) {
            std::cout << "Service: " << specialData << std::endl;
        }
    };

    class Adapter : public IInterface {
    private:
        Service* adapter;

    public:
        void method(const Data data) override {
            SpecialData specialData = convertToServiceFormat(data);
            adapter->serviceMethod(specialData);
        }

    private:
        SpecialData convertToServiceFormat(const Data& data) {
            return data + "_specialXML";
        }
    };
}

namespace adapter_2 {

    using Data = std::string;
    using SpecialData = std::string;

    class ExistingClass {
    public:
        virtual void method(const Data& data) {
            std::cout << "ExistingClass: " << data << std::endl;
        }
    };

    class Service {
    public:
        void serviceMethod(const SpecialData& specialData) {
            std::cout << "Service: " << specialData << std::endl;
        }
    };

    class Adapter : public ExistingClass, public Service {
    public:
        void method(const Data& data) override {
            SpecialData specialData = convertToServiceFormat(data);
            serviceMethod(specialData);
        }
    private:
        SpecialData convertToServiceFormat(const Data& data) {
            return data + "_specialXML";
        }
    };
}