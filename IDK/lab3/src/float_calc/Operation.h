#ifndef OPERATION_H
#define OPERATION_H

#include <vector>

class Operation {
public:
    virtual double execute(const std::vector<double>& numbers) const = 0;
    virtual ~Operation()                                             = default;
};

class Addition : public Operation {
public:
    double execute(const std::vector<double>& numbers) const override;
};

class Multiplication : public Operation {
public:
    double execute(const std::vector<double>& numbers) const override;
};

class SumOfSquares : public Operation {
public:
    double execute(const std::vector<double>& numbers) const override;
};

#endif // OPERATION_H
