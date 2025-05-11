#include "./Matrix/include/Matrix.h"

#include <Windows.h>
using namespace matrix;

void task_1() {
    Matrix<double> first_state = {{
       { 1.0, 0.0, 0.0, 0.0 }
    }};

    Matrix<double> A = {{
        { 0.0, 0.5, 0.0, 0.5 },
        { 0.0, 0.6, 0.4, 0.0 },
        { 0.0, 0.0, 1.0, 0.0 },
        { 0.0, 0.0, 0.5, 0.5 }
    }};

    Matrix<double> state_after_1 = first_state * A;
    Matrix<double> state_after_2 = state_after_1 * A;
    Matrix<double> state_after_3 = state_after_2 * A;

    std::cout << "После 1 проверки:\n" << state_after_1 << std::endl;
    std::cout << "После 2 проверки:\n" << state_after_2 << std::endl;
    std::cout << "После 3 проверки:\n" << state_after_3 << std::endl;
}

void task_2() {
    Matrix<double> first_state = {{
      { 1.0, 0.0, 0.0, 0.0 }
    }};

    Matrix<double> A = {{
        { 0.0, 0.5,  0.5, 0.0 },
        { 0.0, 0.45, 0.0, 0.55 },
        { 0.6, 0.0,  0.4, 0.0 },
        { 0.0, 0.3,  0.7, 0.0 }
    }};

    Matrix<double> state_after_1 = first_state * A;
    Matrix<double> state_after_2 = state_after_1 * A;
    Matrix<double> state_after_3 = state_after_2 * A;

    std::cout << "После 1 проверки:\n" << state_after_1 << std::endl;
    std::cout << "После 2 проверки:\n" << state_after_2 << std::endl;
    std::cout << "После 3 проверки:\n" << state_after_3 << std::endl;
}

int main() {
    SetConsoleOutputCP(1251);

    //task_1();
    task_2();

    return 0;
}