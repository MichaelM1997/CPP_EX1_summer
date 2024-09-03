#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;
using namespace ariel;


TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g3.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");
}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {1, 0, 2},
        {1, 3, 1},
        {1, 0, 2}};
    CHECK(g4.printGraph() == "[1, 0, 2]\n[1, 3, 1]\n[1, 0, 2]");
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1},
        {0, 1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}


TEST_CASE("Test graph addition operator")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);
    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2, 0}, 
        {2, 0, 2}, 
        {0, 2, 0}};
    g2.loadGraph(graph2);
    Graph result = g1 + g2;
    CHECK(result.printGraph() == "[0, 3, 0]\n[3, 0, 3]\n[0, 3, 0]");
}

TEST_CASE("Test graph subtraction operator")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 3, 0}, 
        {3, 0, 3}, 
        {0, 3, 0}};
    g1.loadGraph(graph1);
    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}};
    g2.loadGraph(graph2);
    Graph result = g1 - g2;
    CHECK(result.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");
}

TEST_CASE("Test graph unary minus operator")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}};
    g1.loadGraph(graph1);
    Graph result = -g1;
    CHECK(result.printGraph() == "[0, -1, 0]\n[-1, 0, -1]\n[0, -1, 0]");
}

TEST_CASE("Test graph multiplication operator")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}};
    g1.loadGraph(graph1);
    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2, 0}, 
        {2, 0, 2}, 
        {0, 2, 0}};
    g2.loadGraph(graph2);
    Graph result = g1 * g2;
    CHECK(result.printGraph() == "[2, 0, 2]\n[0, 4, 0]\n[2, 0, 2]");
}

TEST_CASE("Test graph scalar multiplication operator")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}};
    g1.loadGraph(graph1);
    Graph result = g1 * 2;
    CHECK(result.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");
}

TEST_CASE("Test graph pre-increment operator")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}};
    g1.loadGraph(graph1);
    Graph result = ++g1;
    CHECK(result.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");
    CHECK(g1.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");
}

TEST_CASE("Test graph post-increment operator")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}};
    g1.loadGraph(graph1);
    Graph result = g1++;
    CHECK(result.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
    CHECK(g1.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");
}

TEST_CASE("Test graph pre-decrement operator")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 2, 0}, 
        {2, 0, 2}, 
        {0, 2, 0}};
    g1.loadGraph(graph1);
    Graph result = --g1;
    CHECK(result.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
    CHECK(g1.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
}

TEST_CASE("Test graph post-decrement operator")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 2, 0}, 
        {2, 0, 2}, 
        {0, 2, 0}};
    g1.loadGraph(graph1);
    Graph result = g1--;
    CHECK(result.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");
    CHECK(g1.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
}

TEST_CASE("Test graph equality operator")
{
    // two identical graphs
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}};
    g1.loadGraph(graph1);
    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}};
    g2.loadGraph(graph2);
    CHECK(g1 == g2);

    // two different graphs
    Graph g3;
    vector<vector<int>> graph3 = {
        {0, 2, 0}, 
        {2, 0, 2}, 
        {0, 2, 0}};
    g3.loadGraph(graph3);
    CHECK_FALSE(g1 == g3);
}

TEST_CASE("Test graph inequality operator")
{
    // two different graphs
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}};
    g1.loadGraph(graph1);
    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2, 0}, 
        {2, 0, 2}, 
        {0, 2, 0}};
    g2.loadGraph(graph2);
    CHECK(g1 != g2);

    // two identical graphs
    Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}};
    g3.loadGraph(graph3);
    CHECK_FALSE(g1 != g3);
}

TEST_CASE("Test graph comparison operators")
{
    // Greater than comparison 
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 2, 0}, 
        {2, 0, 2}, 
        {0, 2, 0}};
    g1.loadGraph(graph1);
    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}};
    g2.loadGraph(graph2);
    CHECK(g1 > g2);

    // Less than comparison 
    Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}};
    g3.loadGraph(graph3);
    Graph g4;
    vector<vector<int>> graph4 = {
        {0, 2, 0}, 
        {2, 0, 2}, 
        {0, 2, 0}};
    g4.loadGraph(graph4);
    CHECK(g3 < g4);

    // Greater than or equal to comparison 
    Graph g5;
    vector<vector<int>> graph5 = {
        {0, 2, 0}, 
        {2, 0, 2}, 
        {0, 2, 0}};
    g5.loadGraph(graph5);
    Graph g6;
    vector<vector<int>> graph6 = {
        {0, 2, 0}, 
        {2, 0, 2}, 
        {0, 2, 0}};
    g6.loadGraph(graph6);
    CHECK(g5 >= g6);
}