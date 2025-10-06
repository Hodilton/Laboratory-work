#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

int main() {
    std::mutex m1;
    std::mutex m2;

    auto f1 = [&m1, &m2]() {
        std::cout << "Stream " << std::this_thread::get_id() << " try capture m1 and m2..." << std::endl;
        std::scoped_lock lg(m1, m2);
        std::cout << "Stream " << std::this_thread::get_id() << " capture both mutex." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << "Stream " << std::this_thread::get_id() << " free both mutex." << std::endl;
    };

    auto f2 = [&m1, &m2]() {
        std::cout << "Stream " << std::this_thread::get_id() << " try capture m1 and m2..." << std::endl;
        std::scoped_lock lg(m1, m2);
        std::cout << "Stream " << std::this_thread::get_id() << " capture both mutex." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << "Stream " << std::this_thread::get_id() << " free both mutex." << std::endl;
    };

    std::thread thread1(f1);
    std::thread thread2(f2);

    thread1.join();
    thread2.join();

    std::cout << "Both streams end.\n";
    return 0;
}
