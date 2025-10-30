#pragma once
#include <vector>

std::vector<std::vector<int>> createMatrix(size_t rows, size_t cols, int start) {
    std::vector<std::vector<int>> mat(rows, std::vector<int>(cols));
    int val = start;
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
            mat[i][j] = val++;
    return mat;
}
