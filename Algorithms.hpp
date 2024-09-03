// 318410941
// michaelmorali@gmail.com

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#pragma once
#include "Graph.hpp"
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <algorithm>
#include <climits>


namespace ariel {

    class Algorithms{

    private:
        

    public:
        static void bfs(const Graph& g, size_t start, std::vector<int>& dist, std::vector<int>& prev);
        static bool dfs(const std::vector<std::vector<int>>& adjMatrix, size_t u, std::vector<bool>& visited, std::vector<bool>& inStack);
        static bool bfsBipartite(const Graph& g, size_t start, std::vector<int>& color, std::vector<int>& setA, std::vector<int>& setB);
        static bool bellmanFord(const Graph& g, std::vector<int>& dist);
        static void dijkstra(const Graph& g, size_t start, std::vector<int>& dist, std::vector<int>& prev);
        static std::string isConnected(const Graph& g);

        static std::string shortestPath(const Graph& g, int start_i, int end_i);
        static std::string isContainsCycle(const Graph& g);
        static std::string isBipartite(const Graph& g);
        static std::string negativeCycle(const Graph& g);
    };
}
#endif