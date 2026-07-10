#ifndef DIJKSTRA_RESULT_H
#define DIJKSTRA_RESULT_H

#include <vector>

using namespace std;

struct DijkstraResult
{
    vector<int> distance;
    vector<int> parent;
};

#endif