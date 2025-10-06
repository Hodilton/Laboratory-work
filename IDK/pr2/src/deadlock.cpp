#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

int main() {
    std::mutex m1;
    std::mutex m2;

    auto f1 = [&m1, &m2]() {
        std::cout << "Stream " << std::this_thread::get_id() << " capture m1" << std::endl;
        std::lock_guard<std::mutex> lg1(m1);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << "Stream " << std::this_thread::get_id() << " capture m2" << std::endl;
        std::lock_guard<std::mutex> lg2(m2);
        std::cout << "Stream " << std::this_thread::get_id() << " end." << std::endl;
    };

    auto f2 = [&m1, &m2]() {
        std::cout << "Stream " << std::this_thread::get_id() << " capture m2" << std::endl;
        std::lock_guard<std::mutex> lg1(m2);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << "Stream " << std::this_thread::get_id() << " capture m1" << std::endl;
        std::lock_guard<std::mutex> lg2(m1);
        std::cout << "Stream " << std::this_thread::get_id() << " end." << std::endl;
    };

    std::thread thread1(f1);
    std::thread thread2(f2);

    thread1.join();
    thread2.join();

    return 0;
}
