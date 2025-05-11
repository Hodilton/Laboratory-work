#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <fstream>

using std::vector;
using std::ofstream;
using std::string;

vector<double> solveTridiagonal(int n, const vector<double>& a,
                                       const vector<double>& b,
                                       const vector<double>& c,
                                       const vector<double>& d) {
    vector<double> x(n);
    vector<double> c_support(n);
    vector<double> d_support(n);

    c_support[0] = c[0] / b[0];
    d_support[0] = d[0] / b[0];

    for (int i = 1; i < n; i++) {
        c_support[i] = c[i] / (b[i] - a[i] * c_support[i - 1]);
        d_support[i] = (d[i] - a[i] * d_support[i - 1]) / (b[i] - a[i] * c_support[i - 1]);
    }

    x[n - 1] = d_support[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        x[i] = d_support[i] - c_support[i] * x[i + 1];
    }

    return x;
}

void saveResultsToFile(const string& filename, const vector<double>& x, const vector<double>& y) {
    ofstream outfile(filename);
    outfile << std::fixed << std::setprecision(6);
    for (size_t i = 0; i < x.size(); ++i) {
        outfile << x[i] << " " << y[i] << "\n";
    }
    outfile.close();
    std::cout << "Results saved to " << filename << std::endl;
}

int main() {
    int N = 100;
    double x0 = -1.0;
    double xk = 4.0;
    double h = (xk - x0) / N;


    vector<double> a(N + 1, 0.0);
    vector<double> b(N + 1, 0.0);
    vector<double> c(N + 1, 0.0);
    vector<double> d(N + 1, 0.0);

    b[0] = 1.5 - (1.94 / h);
    c[0] = 1.94 / h;
    d[0] = 2.31;

    for (int i = 1; i < N; i++) {
        double xi = x0 + i * h;

        a[i] = 1.0 / (h * h) + exp(-xi * xi) / (2.0 * h);
        b[i] = -2.0 / (h * h) + cos(xi);
        c[i] = 1.0 / (h * h) - exp(-xi * xi) / (2.0 * h);
        d[i] = xi * xi;
    }


    a[N] = -1.0 / h;
    b[N] = 1.0 + (1.0 / h);
    d[N] = 0.0;


    vector<double> y = solveTridiagonal(N + 1, a, b, c, d);

    std::cout << std::fixed << std::setprecision(6);
    vector<double> x(N + 1);
    for (int i = 0; i <= N; ++i) {
        x[i] = x0 + i * h;
    }

    saveResultsToFile("tridiagonal_solution.txt", x, y);

    std::cout << std::fixed << std::setprecision(6);
    for (int i = 0; i <= N; ++i) {
        std::cout << "x = " << x[i] << ", y = " << y[i] << std::endl;
    }

    return 0;
}