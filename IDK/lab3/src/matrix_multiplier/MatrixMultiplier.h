#ifndef MATRIX_MULTIPLIER_H
#define MATRIX_MULTIPLIER_H

#include <vector>
#include <thread>
#include <atomic>

class MatrixMultiplier {
public:
    MatrixMultiplier(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, size_t numThreads);

    void run();

private:
    void worker(size_t id);
    void printMatrix(const std::vector<std::vector<int>>& mat, const std::string& name);
    void printResult();
    void writeToFile();

private:
    const std::vector<std::vector<int>> A_;
    const std::vector<std::vector<int>> B_;
    size_t m_, n_, k_;
    std::vector<std::vector<int>> C_;

    const size_t numThreads_;

    std::atomic<size_t> nextIndex;
    std::vector<std::thread> workers;
};

#endif // MATRIX_MULTIPLIER_H
