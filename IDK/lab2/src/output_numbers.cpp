#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

int counter1        = 1;    // Counter for first stream
int counter2        = 1;    // Counter for second stream
bool turn           = true; // Thread queue (true - first thread, false - second)
int numbersToPrint1 = 1;    // The number of numbers to output by first stream
int numbersToPrint2 = 1;    // The number of numbers to output by second stream
std::mutex mtx;             // Mutex for sync

void threadFirstFunction() {
    while (counter1 <= 100) {
        std::lock_guard<std::mutex> lock(mtx);

        if (turn) {
            for (int i = 0; i < numbersToPrint1 && counter1 <= 100; i++) {
                std::cout << counter1 << " ";
                counter1++;
            }

            turn = false;

            numbersToPrint1++;

            if (numbersToPrint1 > 10)
                numbersToPrint1 = 1;
        }
    }
}

void threadSecondFunction() {
    while (counter2 <= 100) {
        std::lock_guard<std::mutex> lock(mtx);

        if (!turn) {
            for (int i = 0; i < numbersToPrint2 && counter2 <= 100; i++) {
                std::cout << counter2 << " ";
                counter2++;
            }

            turn = true;

            numbersToPrint2++;

            if (numbersToPrint2 > 10)
                numbersToPrint2 = 1;
        }
    }
}

int main() {
    std::thread thread1(threadFirstFunction);
    std::thread thread2(threadSecondFunction);

    thread1.join();
    thread2.join();

    std::cout << std::endl;

    return 0;
}