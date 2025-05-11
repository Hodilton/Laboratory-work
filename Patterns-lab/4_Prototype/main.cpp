#include "./Prototype.h"

#include <iostream>
#include <Windows.h>

using namespace prototype;

int main() {
	SetConsoleOutputCP(1251);

    CarPrototypeA original(100);
    
    IPrototype* copy = original.clone();
    copy->print();

    // Создание оригинала подкласса прототипа
    SubclassPrototype subclassOriginal(50, 200);
    // Клонирование подкласса
    Prototype* subclassCopy = subclassOriginal.clone();
    subclassCopy->print();


    // Очистка памяти
    delete copy;
    delete subclassCopy;

	return 0;
}