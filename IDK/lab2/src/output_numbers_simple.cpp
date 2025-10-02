#include <iostream>
#include <thread>
#include <chrono>

void Counter(unsigned int n, unsigned int s) {
    for (unsigned int i = 0; i <= n; i++) {
        std::cout << std::this_thread::get_id() << ":\t" << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(s));
    }
}

int main() {
    std::thread th2(&Counter, 25, 500);
    std::thread th3(&Counter, 50, 1000);

    th2.join();
    th3.join();
}
