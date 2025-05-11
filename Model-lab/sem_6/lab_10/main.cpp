#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cmath>

using namespace std;

const double g = 9.81;       // Ускорение свободного падения (м/с²)
const double v0 = 50.0;      // Начальная скорость (м/с)
const double k1 = 0.33;      // Коэффициент линейного сопротивления (кг/с)
const double k2 = 0.011;     // Коэффициент квадратичного сопротивления (кг/м)
const double m = 1.0;        // Масса тела (кг)
const double dt = 0.001;     // Шаг времени (с)

// Модель без сопротивления воздуха
void no_resistance() {
    ofstream file("no_resistance.csv");
    file << "time,velocity,acceleration,height\n";

    double t = 0.0, v = v0, y = 0.0;
    double t_up = v0 / g;
    double h_max = v0 * v0 / (2 * g);

    // Фаза подъема
    while (t < t_up) {
        double a = -g;
        file << t << "," << v << "," << a << "," << y << "\n";
        y += v * dt;
        v += a * dt;
        t += dt;
    }

    // Фаза спуска
    while (y > 0) {
        double a = -g;
        file << t << "," << v << "," << a << "," << y << "\n";
        y += v * dt;
        v += a * dt;
        t += dt;
    }

    file.close();

    cout << "Без сопротивления:\n";
    cout << "Максимальная высота: " << h_max << " м\n";
    cout << "Время подъема: " << t_up << " с\n";
    cout << "Время спуска: " << t_up << " с\n";
    cout << "Общее время: " << 2 * t_up << " с\n\n";
}

// Модель с линейным сопротивлением (Fc = k₁v)
void linear_resistance() {
    ofstream file("linear.csv");
    file << "time,velocity,acceleration,height\n";

    double t = 0.0, v = v0, y = 0.0, h_max = 0.0, t_up = 0.0, t_down = 0.0;

    // Фаза подъема
    while (v > 0) {
        double a = -g - k1 / m * v;
        file << t << "," << v << "," << a << "," << y << "\n";
        y += v * dt;
        v += a * dt;
        t += dt;
    }
    t_up = t;
    h_max = y;

    // Фаза спуска
    while (y > 0) {
        double a = -g - k1 / m * v;
        file << t << "," << v << "," << a << "," << y << "\n";
        y += v * dt;
        v += a * dt;
        t += dt;
        if (y < 0) break;
    }
    t_down = t - t_up;

    file.close();

    cout << "Линейное сопротивление:\n";
    cout << "Максимальная высота: " << h_max << " м\n";
    cout << "Время подъема: " << t_up << " с\n";
    cout << "Время спуска: " << t_down << " с\n";
    cout << "Общее время: " << t << " с\n\n";
}

// Модель с квадратичным сопротивлением (Fc = k₂v²)
void quadratic_resistance() {
    ofstream file("quadratic.csv");
    file << "time,velocity,acceleration,height\n";

    double t = 0.0, v = v0, y = 0.0, h_max = 0.0, t_up = 0.0, t_down = 0.0;

    // Фаза подъема
    while (v > 0) {
        double a = -g - (k2 / m) * v * abs(v);
        file << t << "," << v << "," << a << "," << y << "\n";
        y += v * dt;
        v += a * dt;
        t += dt;
    }
    t_up = t;
    h_max = y;

    // Фаза спуска
    while (y > 0) {
        double a = -g - (k2 / m) * v * abs(v);
        file << t << "," << v << "," << a << "," << y << "\n";
        y += v * dt;
        v += a * dt;
        t += dt;
        if (y < 0) break;
    }
    t_down = t - t_up;

    file.close();

    cout << "Квадратичное сопротивление:\n";
    cout << "Максимальная высота: " << h_max << " м\n";
    cout << "Время подъема: " << t_up << " с\n";
    cout << "Время спуска: " << t_down << " с\n";
    cout << "Общее время: " << t << " с\n\n";
}

int main() {
    SetConsoleOutputCP(1251);

    no_resistance();
    linear_resistance();
    quadratic_resistance();

    return 0;
}