#include "MatrixMultiplier.h"
#include "utils.hpp"

int main() {
    auto A = createMatrix(2, 3, 1); // [ [1,2,3], [4,5,6] ]
    auto B = createMatrix(3, 2, 1); // [ [1,2], [3,4], [5,6]]

    const size_t p = 4; // количество потоков

    MatrixMultiplier mm(A, B, p);
    mm.run();

    return 0;
}
