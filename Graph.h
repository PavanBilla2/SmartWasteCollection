#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include "DijkstraResult.h"

using namespace std;

class Graph
{
private:
    int vertices;
    vector<vector<pair<int, int>>> adjacencyList;

public:
    // Constructor
    Graph(int vertices);

    // Graph Operations
    void addEdge(int source, int destination, int distance);
    void displayGraph();

    // Traversal Algorithms
    void BFS(int start);
    void DFS(int start);

    // Shortest Path
    // void dijkstra(int start);
    // Shortest Path Algorithm
    DijkstraResult dijkstra(int source);
    int getVertices() const;
    void optimizeRoute(int startNode);

// Print shortest path
    void printPath(vector<int>& parent, int destination);

private:
    // Helper function for DFS
    void DFSHelper(int current, vector<bool> &visited);
};

#endif