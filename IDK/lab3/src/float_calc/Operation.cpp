#include "Operation.h"

#include <numeric>
#include <cmath>

double Addition::execute(const std::vector<double>& numbers) const {
    return std::accumulate(numbers.begin(), numbers.end(), 0.0);
}

double Multiplication::execute(const std::vector<double>& numbers) const {
    if (numbers.empty())
        return 0.0;
    return std::accumulate(numbers.begin(), numbers.end(), 1.0, std::multiplies<double>());
}

double SumOfSquares::execute(const std::vector<double>& numbers) const {
    double sum = 0.0;
    for (double x : numbers) {
        sum += x * x;
    }
    return sum;
}
