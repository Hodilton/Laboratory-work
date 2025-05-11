#include <iostream>
#include <memory>

#include "./factory/ArdekoFactory.h"
#include "./factory/VictorianFactory.h"
#include "./factory/ModernFactory.h"

#include <Windows.h>

class Client {
private:
    std::shared_ptr<IFurnitureFactory> factory;

public:
    void SetFactory(std::shared_ptr<IFurnitureFactory> newFactory) {
        factory = std::move(newFactory);
    }

    std::shared_ptr<IFurnitureFactory> getFactory() {
        return factory;
    }

    void getFurniture() {
        if (!factory) {
            std::cout << "Фабрика не установлена!\n";
            return;
        }

        auto chair = factory->createChair();
        auto sofa = factory->createSofa();
        auto table = factory->createCoffeeTable();

        chair->sitOn();
        sofa->lieOn();
        table->placeItems();
    }
};

int main() {
    SetConsoleOutputCP(1251);

    Client client;

    std::cout << "Создание мебели в модерн-стиле:\n";
    client.SetFactory(std::make_shared<ModernFactory>());
    client.getFurniture();

    std::cout << "\nСоздание мебели в викторианском стиле:\n";
    client.SetFactory(std::make_shared<VictorianFactory>());
    client.getFurniture();

    std::cout << "\nСоздание мебели в стиле ар-деко:\n";
    client.SetFactory(std::make_shared<ArdekoFactory>());
    client.getFurniture();

    return 0;
}