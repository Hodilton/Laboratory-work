#include "graph.h"

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "Введите количество вершин графа: ";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "Количество вершин должно быть положительным.\n";
        return 1;
    }

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    std::cout << "Введите матрицу смежности (" << n << " строк по " << n << " чисел, 0 или 1):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    try {
        Graph g(matrix);

        std::cout << "\nМатрица смежности:\n";
        g.printMatrix();

        std::cout << "\nАнализ графа:\n";
        if (g.isSimple()) {
            std::cout << "- Граф является простым.\n";
        } else {
            std::cout << "- Граф НЕ является простым (есть петли или не симметричен).\n";
        }

        if (g.isNullGraph()) {
            std::cout << "- Граф является нуль-графом.\n";
        } else {
            std::cout << "- Граф НЕ является нуль-графом.\n";
        }

        std::cout << "- Максимальная степень вершины: " << g.maxDegree() << "\n";

        if (g.hasLeafVertices()) {
            std::cout << "- В графе есть висячие вершины.\n";
        } else {
            std::cout << "- В графе нет висячих вершин.\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
