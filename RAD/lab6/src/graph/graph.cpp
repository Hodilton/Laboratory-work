#include "graph.h"

#include <stdexcept>
#include <algorithm>

bool Graph::isValidMatrix() const {
    if (n <= 0)
        return false;

    for (const auto& row : adjacencyMatrix) {
        if (static_cast<int>(row.size()) != n)
            return false;

        for (int val : row) {
            if (val != 0 && val != 1)
                return false;
        }
    }

    return true;
}

Graph::Graph(const std::vector<std::vector<int>>& matrix) : adjacencyMatrix(matrix), n(matrix.size()) {
    if (!isValidMatrix()) {
        throw std::invalid_argument("Invalid adjacency matrix: must be square with 0/1 values.");
    }
}

bool Graph::isSimple() const {
    for (int i = 0; i < n; ++i) {
        if (adjacencyMatrix[i][i] != 0) {
            return false;
        }

        for (int j = 0; j < n; ++j) {
            if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) {
                return false;
            }
        }
    }

    return true;
}

bool Graph::isNullGraph() const {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adjacencyMatrix[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}

int Graph::maxDegree() const {
    int maxDeg = 0;
    for (int i = 0; i < n; ++i) {
        int degree = 0;

        for (int j = 0; j < n; ++j) {
            degree += adjacencyMatrix[i][j];
        }

        if (degree > maxDeg) {
            maxDeg = degree;
        }
    }

    return maxDeg;
}

bool Graph::hasLeafVertices() const {
    for (int i = 0; i < n; ++i) {
        int degree = 0;

        for (int j = 0; j < n; ++j) {
            degree += adjacencyMatrix[i][j];
        }

        if (degree == 1) {
            return true;
        }
    }

    return false;
}

void Graph::printMatrix() const {
    for (const auto& row : adjacencyMatrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}
