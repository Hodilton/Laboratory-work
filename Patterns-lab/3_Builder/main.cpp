#include "./Builder.h"

#include <iostream>

using namespace builder;

int main() {
    Director director;

    CarBuilder carBuilder;
    director.constructCar(carBuilder, CarType::SPORTS_CAR);
    Car* car = carBuilder.getResult();
    car->show();

    ManualBuilder manualBuilder;
    director.constructManual(manualBuilder, ManualType::SPORTS_CAR_MANUAL);
    Manual* manual = manualBuilder.getResult();
    manual->show();

	return 0;
}