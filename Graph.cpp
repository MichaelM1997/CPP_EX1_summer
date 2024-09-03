// Graph.cpp
#include "Graph.hpp"
#include <sstream>

namespace ariel {

    void Graph::loadGraph(const std::vector<std::vector<int>>& matrix) {
        if (matrix.empty() || matrix.size() != matrix[0].size()) {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

        adjMatrix = matrix;
        numVertices = matrix.size();
        numEdges = 0;
        isDirected = false;

        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                if (adjMatrix[i][j] != 0) {
                    numEdges++;
                    if (adjMatrix[i][j] != adjMatrix[j][i]) {
                        isDirected = true;
                    }
                }
            }
        }

        if (!isDirected) {
            numEdges /= 2;
        }
    }

    std::string Graph::printGraph() {
    std::ostringstream oss;
    for (size_t row = 0; row < adjMatrix.size(); ++row) {
        oss << "[";
        for (size_t col = 0; col < adjMatrix[row].size(); ++col) {
            oss << adjMatrix[row][col];
            if (col < adjMatrix[row].size() - 1) {
                oss << ", ";
            }
        }
        oss << "]";
        if (row < adjMatrix.size() - 1) {
            oss << "\n";
        }
    }
    return oss.str();
}

    const std::vector<std::vector<int>>& Graph::getAdjMatrix() const {
        return adjMatrix;
    }

    size_t Graph::getNumVertices() const {
        return numVertices;
    }

    int Graph::getNumEdges() const {
        return numEdges;
    }

    bool Graph::isDirectedGraph() const {
        return isDirected;
    }

    Graph Graph::operator+(const Graph& other) const {
        if (numVertices != other.numVertices) {
            throw std::invalid_argument("Cannot add graphs of different sizes.");
        }

        Graph result;
        result.numVertices = numVertices;
        result.adjMatrix.resize(numVertices, std::vector<int>(numVertices, 0));

        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                result.adjMatrix[i][j] = adjMatrix[i][j] + other.adjMatrix[i][j];
                if (result.adjMatrix[i][j] != 0) {
                    result.numEdges++;
                }
            }
        }

        result.isDirected = isDirected || other.isDirected;
        return result;
    }

    Graph& Graph::operator+=(const Graph& other) {
        if (numVertices != other.numVertices) {
            throw std::invalid_argument("Cannot add graphs of different sizes.");
        }

        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                adjMatrix[i][j] += other.adjMatrix[i][j];
                if (adjMatrix[i][j] != 0 && other.adjMatrix[i][j] != 0) {
                    numEdges++;
                }
            }
        }

        isDirected = isDirected || other.isDirected;
        return *this;
    }

    Graph& Graph::operator++() { // pre increment
        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                if (adjMatrix[i][j] != 0) {
                    adjMatrix[i][j]++;
                }
            }
        }
        return *this;
    }

    Graph Graph::operator++(int) { // post increment
        Graph temp = *this;
        ++(*this);
        return temp;
    }

    Graph Graph::operator-() const { // unary minus
        Graph result;
        result.numVertices = numVertices;
        result.adjMatrix.resize(numVertices, std::vector<int>(numVertices, 0));

        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                result.adjMatrix[i][j] = -adjMatrix[i][j];
                if (result.adjMatrix[i][j] != 0) {
                    result.numEdges++;
                }
            }
        }

        result.isDirected = isDirected;
        return result;
    }

    Graph Graph::operator-(const Graph& other) const { // substruction
        if (numVertices != other.numVertices) {
            throw std::invalid_argument("Cannot subtract graphs of different sizes.");
        }

        Graph result;
        result.numVertices = numVertices;
        result.adjMatrix.resize(numVertices, std::vector<int>(numVertices, 0));

        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                result.adjMatrix[i][j] = adjMatrix[i][j] - other.adjMatrix[i][j];
                if (result.adjMatrix[i][j] != 0) {
                    result.numEdges++;
                }
            }
        }

        result.isDirected = isDirected || other.isDirected;
        return result;
    }

    Graph& Graph::operator-=(const Graph& other) {
        if (numVertices != other.numVertices) {
            throw std::invalid_argument("Cannot subtract graphs of different sizes.");
        }

        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                adjMatrix[i][j] -= other.adjMatrix[i][j];
                if (adjMatrix[i][j] == 0 && other.adjMatrix[i][j] != 0) {
                    numEdges--;
                }
            }
        }

        isDirected = isDirected || other.isDirected;
        return *this;
    }

    Graph& Graph::operator--() { // pre decrement 
        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                if (adjMatrix[i][j] != 0) {
                    adjMatrix[i][j]--;
                    if (adjMatrix[i][j] == 0) {
                        numEdges--;
                    }
                }
            }
        }
        return *this;
    }

    Graph Graph::operator--(int) { // post decrement
        Graph temp = *this;
        --(*this);
        return temp;
    }

    bool Graph::operator>(const Graph& other) const {
    if (numVertices != other.numVertices) {
        throw std::invalid_argument("Cannot compare graphs of different sizes.");
    }

    bool isGreater = false;
    for (size_t i = 0; i < numVertices; ++i) {
        for (size_t j = 0; j < numVertices; ++j) {
            if (adjMatrix[i][j] > other.adjMatrix[i][j]) {
                isGreater = true;
            } else if (adjMatrix[i][j] < other.adjMatrix[i][j]) {
                return false;
            }
        }
    }

    return isGreater;
}

    bool Graph::operator>=(const Graph& other) const {
        if (numVertices != other.numVertices) {
            throw std::invalid_argument("Cannot compare graphs of different sizes.");
        }

        return (*this > other) || (*this == other);
    }

    bool Graph::operator<(const Graph& other) const {
        if (numVertices != other.numVertices) {
            throw std::invalid_argument("Cannot compare graphs of different sizes.");
        }

        return !(*this >= other);
    }

    bool Graph::operator<=(const Graph& other) const {
        if (numVertices != other.numVertices) {
            throw std::invalid_argument("Cannot compare graphs of different sizes.");
        }

        return !(*this > other);
    }

    bool Graph::operator==(const Graph& other) const {
        if (numVertices != other.numVertices || numEdges != other.numEdges) {
            return false;
        }

        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                if (adjMatrix[i][j] != other.adjMatrix[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool Graph::operator!=(const Graph& other) const {
        return !(*this == other);
    }

    Graph& Graph::operator*=(int scalar) {
        if (scalar < 0) {
            throw std::invalid_argument("Scalar multiplication requires a non-negative scalar.");
        }

        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                adjMatrix[i][j] *= scalar;
                if (adjMatrix[i][j] == 0 && scalar != 0) {
                    numEdges--;
                }
            }
        }
        return *this;
    }

    Graph Graph::operator*(int scalar) const { // scalar multiplication
        if (scalar < 0) {
            throw std::invalid_argument("Scalar multiplication requires a non-negative scalar.");
        }

        Graph result = *this;
        result *= scalar;
        return result;
    }

    Graph Graph::operator*(const Graph& other) const { // graph multiplication
        if (numVertices != other.numVertices) {
            throw std::invalid_argument("Cannot multiply graphs of different sizes.");
        }

        Graph result;
        result.numVertices = numVertices;
        result.adjMatrix.resize(numVertices, std::vector<int>(numVertices, 0));

        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                for (size_t k = 0; k < numVertices; ++k) {
                    result.adjMatrix[i][j] += adjMatrix[i][k] * other.adjMatrix[k][j];
                }
                if (result.adjMatrix[i][j] != 0) {
                    result.numEdges++;
                }
            }
        }

        result.isDirected = isDirected || other.isDirected;
        return result;
    }

    std::ostream& operator<<(std::ostream& os, const Graph& graph) {
        os << "Graph with " << graph.numVertices << " vertices and " << graph.numEdges << " edges." << std::endl;
        os << "Adjacency Matrix:" << std::endl;
        for (size_t i = 0; i < graph.numVertices; ++i) {
            for (size_t j = 0; j < graph.numVertices; ++j) {
                os << graph.adjMatrix[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

}