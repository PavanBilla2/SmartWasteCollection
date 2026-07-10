#include "../include/Graph.h"

Graph::Graph(int vertices)
{
    this->vertices = vertices;

    adjacencyList.resize(vertices + 1);
}

void Graph::addEdge(int source, int destination, int distance)
{
    adjacencyList[source].push_back({destination, distance});

    adjacencyList[destination].push_back({source, distance});
}

void Graph::displayGraph()
{
    cout << "\nCity Road Network\n";
    cout << "-----------------------------\n";

    for (int i = 1; i <= vertices; i++)
    {
        cout << "Bin " << i << " -> ";

        for (auto neighbour : adjacencyList[i])
        {
            cout << "("
                 << neighbour.first
                 << ", "
                 << neighbour.second
                 << " km) ";
        }

        cout << endl;
    }
}

void Graph::BFS(int start)
{
    vector<bool> visited(vertices + 1, false);

    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "\n===== BFS Traversal =====\n";

    int visitedCount = 0;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        cout << current << " ";

        visitedCount++;

        for (auto neighbour : adjacencyList[current])
        {
            int next = neighbour.first;

            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    cout << endl;

    if (visitedCount == vertices)
        cout << "\nAll waste bins are reachable.\n";
    else
        cout << "\nWarning: Some waste bins are disconnected.\n";
}

void Graph::DFSHelper(int current, vector<bool>& visited)
{
    visited[current] = true;

    cout << current << " ";

    for (auto neighbour : adjacencyList[current])
    {
        int next = neighbour.first;

        if (!visited[next])
        {
            DFSHelper(next, visited);
        }
    }
}

void Graph::DFS(int start)
{
    vector<bool> visited(vertices + 1, false);

    cout << "\n===== DFS Traversal =====\n";

    DFSHelper(start, visited);

    cout << endl;

    bool connected = true;

    for (int i = 1; i <= vertices; i++)
    {
        if (!visited[i])
        {
            connected = false;
            break;
        }
    }

    if (connected)
        cout << "\nAll waste bins are reachable.\n";
    else
        cout << "\nWarning: Some waste bins are disconnected.\n";
}

DijkstraResult Graph::dijkstra(int source)
{
    vector<int> distance(vertices + 1, INT_MAX);

    vector<int> parent(vertices + 1, -1);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    distance[source] = 0;

    pq.push({0, source});

    while (!pq.empty())
    {
        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;

        pq.pop();

        if (currentDistance > distance[currentNode])
            continue;

        for (auto neighbour : adjacencyList[currentNode])
        {
            int next = neighbour.first;
            int edgeWeight = neighbour.second;

            if (distance[currentNode] + edgeWeight < distance[next])
            {
                distance[next] = distance[currentNode] + edgeWeight;

                parent[next] = currentNode;

                pq.push({distance[next], next});
            }
        }
    }

    DijkstraResult result;

    result.distance = distance;
    result.parent = parent;

    return result;
}

int Graph::getVertices() const
{
    return vertices;
}

void Graph::printPath(vector<int>& parent, int destination)
{
    if (destination == -1)
        return;

    if (parent[destination] != -1)
    {
        printPath(parent, parent[destination]);
        cout << " -> ";
    }

    cout << destination;
}

void Graph::optimizeRoute(int startNode)
{
    vector<bool> visited(vertices + 1, false);
    vector<int> route;

    int current = startNode;
    int totalDistance = 0;

    visited[current] = true;
    route.push_back(current);

    while (true)
    {
        DijkstraResult result = dijkstra(current);

        int nearest = -1;
        int minDistance = INT_MAX;

        for (int i = 1; i <= vertices; i++)
        {
            if (!visited[i] && result.distance[i] < minDistance)
            {
                minDistance = result.distance[i];
                nearest = i;
            }
        }

        if (nearest == -1)
            break;

        visited[nearest] = true;
        route.push_back(nearest);
        totalDistance += minDistance;

        current = nearest;
    }

    DijkstraResult check = dijkstra(startNode);

    for (int i = 1; i <= vertices; i++)
    {
        if (check.distance[i] == INT_MAX)
        {
            cout << "\nERROR: Some waste bins are unreachable.\n";
            cout << "Route optimization cannot continue.\n";
            return;
        }
    }

    cout << "\n========== SMART WASTE COLLECTION ==========\n";
    cout << "Starting Bin : " << startNode << "\n\n";

    cout << "Optimized Route : ";

    for (int i = 0; i < route.size(); i++)
    {
        cout << route[i];

        if (i != route.size() - 1)
            cout << " -> ";
    }

    cout << "\n\n";

    // Return truck to depot
    DijkstraResult returnPath = dijkstra(current);

    if (returnPath.distance[startNode] != INT_MAX)
    {
        totalDistance += returnPath.distance[startNode];
        route.push_back(startNode);
    }

    cout << "\n========== COLLECTION REPORT ==========\n\n";

    cout << "Starting Depot      : Bin " << startNode << "\n";

    cout << "Optimized Route     : ";

    for (int i = 0; i < route.size(); i++)
    {
        cout << route[i];

        if (i != route.size() - 1)
            cout << " -> ";
    }

    cout << "\n";

    cout << "Total Distance      : " << totalDistance << " km\n";
    cout << "Waste Bins Covered  : " << vertices << "\n";
    cout << "Route Stops         : " << route.size() << "\n";
    cout << "Estimated Fuel      : " << totalDistance * 0.10 << " Litres\n";
    cout << "Estimated Time      : " << totalDistance * 2 << " Minutes\n";
    cout << "Collection Status   : SUCCESS\n";

    cout << "============================================\n";

    cout << "\n========== COLLECTION SIMULATION ==========\n\n";

    for (int i = 0; i < route.size(); i++)
    {
        if (i == 0)
        {
            cout << "Truck started from Depot (Bin "
                << route[i] << ")\n";
        }
        else
        {
            cout << "Moving to Bin "
                << route[i] << "...\n";

            cout << "Waste Collected Successfully.\n\n";
        }
    }

    cout << "Returning to Depot (Bin "
        << startNode
        << ")...\n\n";

    cout << "Collection Completed Successfully.\n";
}