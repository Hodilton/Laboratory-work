#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

class Graph {
public:
    Graph(const std::vector<std::vector<int>>& matrix);

private:
    std::vector<std::vector<int>> adjacencyMatrix;
    int n;

public:
    bool isValidMatrix() const;

    bool isSimple() const;

    bool isNullGraph() const;

    int maxDegree() const;

    bool hasLeafVertices() const;

    void printMatrix() const;
};

#endif // GRAPH_H
