#include "../include/Graph.h"

int main()
{
    int vertices, roads;

    cout << "=========================================\n";
    cout << " SMART WASTE COLLECTION SYSTEM\n";
    cout << "=========================================\n";

    cout << "\nEnter Number of Waste Bins: ";
    cin >> vertices;

    Graph city(vertices);

    cout << "\nEnter Number of Roads: ";
    cin >> roads;

    cout << "\nEnter Source Destination Distance\n";

    for(int i = 0; i < roads; i++)
    {
        int source, destination, distance;

        cin >> source >> destination >> distance;

        city.addEdge(source, destination, distance);
    }

    city.displayGraph();
    city.BFS(1);
    city.DFS(1);
    city.optimizeRoute(1);
    
    DijkstraResult result = city.dijkstra(1);

    cout << "\n===== Shortest Path Report =====\n";

    for (int i = 1; i <= city.getVertices(); i++)
    {
        cout << "Bin " << i << " : ";

        if (result.distance[i] == INT_MAX)
        {
            cout << "Not Reachable\n";
            continue;
        }

        cout << result.distance[i] << " km\n";

        cout << "Route : ";
        city.printPath(result.parent, i);
        cout << "\n\n";
    }

    return 0;
}