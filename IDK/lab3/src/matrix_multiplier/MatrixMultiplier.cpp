#include "MatrixMultiplier.h"

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <string>

MatrixMultiplier::MatrixMultiplier(
    const std::vector<std::vector<int>>& A,
    const std::vector<std::vector<int>>& B,
    size_t numThreads) :
    A_(A),
    B_(B),
    m_(A.size()),
    n_(A[0].size()),
    k_(B[0].size()),
    C_(m_, std::vector<int>(k_, 0)),
    numThreads_(numThreads),
    nextIndex(0) {
}

void MatrixMultiplier::run() {
    printMatrix(A_, "A");
    printMatrix(B_, "B");

    // Запуск потоков
    for (size_t i = 0; i < numThreads_; ++i) {
        workers.emplace_back(&MatrixMultiplier::worker, this, i);
    }

    // Ожидание завершения всех потоков
    for (auto& t : workers) {
        t.join();
    }

    printResult();

    // Запись в файл
    writeToFile();
}

void MatrixMultiplier::printMatrix(const std::vector<std::vector<int>>& mat, const std::string& name) {
    std::cout << "Matrix " << name << " (" << mat.size() << "x" << mat[0].size() << "):\n";
    for (const auto& row : mat) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void MatrixMultiplier::printResult() {
    std::cout << "Matrix C = A * B:\n";
    for (const auto& row : C_) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void MatrixMultiplier::worker(size_t id) {
    while (true) {
        size_t idx = nextIndex.fetch_add(1);
        if (idx >= m_ * k_)
            break;

        size_t i = idx / k_;
        size_t j = idx % k_;

        // Задержка для симуляции вычислений
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        int sum = 0;
        for (size_t l = 0; l < n_; ++l) {
            sum += A_[i][l] * B_[l][j];
        }
        C_[i][j] = sum;
    }
}

void MatrixMultiplier::writeToFile() {
    std::ofstream file("matrix_log.txt", std::ios::app);
    if (file.is_open()) {
        file << "Matrix A:\n";
        for (const auto& row : A_) {
            for (int val : row)
                file << val << " ";
            file << "\n";
        }
        file << "\nMatrix B:\n";
        for (const auto& row : B_) {
            for (int val : row)
                file << val << " ";
            file << "\n";
        }
        file << "\nResult matrix C (" << m_ << "x" << k_ << "):\n";
        for (const auto& row : C_) {
            for (int val : row) {
                file << val << " ";
            }
            file << "\n";
        }
        file << "--------------------------\n\n";
        file.close();
    }
}
