#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

// Обработчик завершения — вызывается ПОСЛЕ return из main, но ДО уничтожения стека
void on_program_exit() {
    std::cout << "[atexit] main завершился. some_local_state УНИЧТОЖЕНА. "
              << "Поток, возможно, всё ещё работает...\n"
              << std::endl;
}

// Модифицируем переменную
void do_something(int& x) {
    // инкремент через ссылку
    x++;

    std::cout << "[Поток] Значение = " << x << ", адрес = " << &x << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

struct Worker {
    int& ref;
    Worker(int& r) : ref(r) {
    }

    void operator()() {
        std::cout << "[Поток] ЗАПУЩЕН. Работаем адресом: " << &ref << std::endl;

        for (int j = 0; j < 100; ++j) {
            std::cout << "[Поток] Итерация " << j << ": ";

            do_something(ref);
        }

        std::cout << "[Поток] Завершил работу." << std::endl;
    }
};

int main() {
    // Регистрируем обработчик
    std::atexit(on_program_exit);

    int some_local_state = 0;
    std::cout << "[main] some_local_state = " << some_local_state << " (адрес: " << &some_local_state << ")"
              << std::endl;

    Worker w(some_local_state);
    std::thread t(w);
    t.detach(); // Отсоединяем

    // Даём потоку начать, но НЕ ждём его
    std::cout << "[main] main завершается..." << std::endl;

    return 0;
    // Здесь some_local_state уничтожается!
    // Вызывается on_program_exit()
    // Поток продолжает работать на мёртвой памяти
}
