#pragma once

#include <iostream>
#include <string>

namespace builder {

    enum class CarType { COMMON_CAR, SPORTS_CAR, ELECTRIC_CAR };
    enum class ManualType { COMMON_CAR_MANUAL, SPORTS_CAR_MANUAL, ELECTRIC_CAR_MANUAL };

    class Car {
    private:
        std::string _engine;
        int _seats;
        bool _isGPS;
        bool _isAutopilot;

    public:
        Car() : _engine(""), _seats(0), _isGPS(false), _isAutopilot(false) {}

    public:
        void setEngine(const std::string& engine) {
            this->_engine = engine;
        }

        void setSeats(const int seats) {
            this->_seats = seats;
        }

        void setGPS(const bool GPS) {
            this->_isGPS = GPS;
        }

        void setAutopilot(const bool autopilot) {
            _isAutopilot = autopilot;
        }

        void show() const {
            std::cout << "Car:\n"
                << "Engine: " << _engine << "\n"
                << "Seats: " << _seats << "\n"
                << "GPS: " << (_isGPS ? "Yes" : "No") << "\n"
                << "Autopilot: " << (_isAutopilot ? "Yes" : "No") << "\n"
                << std::endl;
        }
    };

    class Manual {
    private:
        std::string _content = "Car Manual:\n";

    private:
        void addContent(const std::string& part) {
            _content += part + "\n";
        }

    public:
        void setEngine(const std::string& engine) {
            addContent("Engine: " + engine);
        }

        void setSeats(int seats) {
            addContent("Seats: " + std::to_string(seats));
        }

        void setGPS(bool isGPS) {
            addContent("GPS: " + std::string(isGPS ? "Yes" : "No"));
        }

        void setAutopilot(bool isAutopilot) {
            addContent("Autopilot: " + std::string(isAutopilot ? "Yes" : "No"));
        }

        void show() const {
            std::cout << _content << std::endl;
        }
    };

    class IBuilder {
    public:
        virtual void reset() = 0;
        virtual void setEngine(const std::string& engine) = 0;
        virtual void setSeats(const int seats) = 0;
        virtual void setGPS(const bool isGPS) = 0;
        virtual void setAutopilot(bool isAutopilot) = 0;
        virtual ~IBuilder() {}
    };


    class CarBuilder : public IBuilder {
    private:
        Car* _car;

    public:
        CarBuilder() : _car(nullptr) { reset(); }
        ~CarBuilder() { delete _car; }

    public:
        void reset() override {
            if (_car) {
                delete _car;
                _car = nullptr;
            }

            _car = new Car();
        }

        void setEngine(const std::string& engine) override {
            _car->setEngine(engine);
        }

        void setSeats(int seats) override {
            _car->setSeats(seats);
        }

        void setGPS(bool isGPS) override {
            _car->setGPS(isGPS);
        }

        void setAutopilot(bool isAutopilot) override {
            _car->setAutopilot(isAutopilot);
        }

        Car* getResult() {
            return _car;
        }
    };

    class ManualBuilder : public IBuilder {
    private:
        Manual* _manual;

    public:
        ManualBuilder() : _manual(nullptr) { reset(); }

        ~ManualBuilder() { delete _manual; }

    public:
        void reset() override {
            if (_manual) {
                delete _manual;
                _manual = nullptr;
            }

            _manual = new Manual();
        }

        void setEngine(const std::string& engine) override {
            _manual->setEngine(engine);
        }

        void setSeats(int seats) override {
            _manual->setSeats(seats);
        }

        void setGPS(bool isGPS) override {
            _manual->setGPS(isGPS);
        }

        void setAutopilot(bool isAutopilot) override {
            _manual->setAutopilot(isAutopilot);
        }

        Manual* getResult() {
            return _manual;
        }
    };

    class Director {
    public:
        void constructCar(IBuilder& builder, const CarType type) {
            builder.reset();

            switch (type) {
            case CarType::COMMON_CAR:
                builder.setEngine("Standard Engine");
                builder.setSeats(4);
                builder.setGPS(false);
                builder.setAutopilot(false);
                break;
            case CarType::SPORTS_CAR:
                builder.setEngine("V8 Turbo");
                builder.setSeats(2);
                builder.setGPS(true);
                builder.setAutopilot(false);
                break;
            case CarType::ELECTRIC_CAR:
                builder.setEngine("Electric Motor");
                builder.setSeats(5);
                builder.setGPS(true);
                builder.setAutopilot(true);
                break;
            }
        }

        void constructManual(IBuilder& builder, ManualType type) {
            builder.reset();

            switch (type) {
            case ManualType::COMMON_CAR_MANUAL:
                builder.setEngine("Standard Engine");
                builder.setSeats(4);
                builder.setGPS(false);
                builder.setAutopilot(false);
                break;
            case ManualType::SPORTS_CAR_MANUAL:
                builder.setEngine("V8 Turbo");
                builder.setSeats(2);
                builder.setGPS(true);
                builder.setAutopilot(false);
                break;
            case ManualType::ELECTRIC_CAR_MANUAL:
                builder.setEngine("Electric Motor");
                builder.setSeats(5);
                builder.setGPS(true);
                builder.setAutopilot(true);
                break;
            }
        }
    };
}