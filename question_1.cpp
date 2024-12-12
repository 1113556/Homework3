#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to create and return adjacency list
vector<vector<int>> createAdjacencyList(int V, vector<pair<int, int>> edges) {
    vector<vector<int>> adjList(V);

    // Fill adjacency list
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;

        // Add each edge to both nodes (undirected graph)
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Sort adjacency lists for consistent output
    for (int i = 0; i < V; i++) {
        sort(adjList[i].begin(), adjList[i].end());
    }

    return adjList;
}

int main() {
    // Input number of nodes and edges
    int V, E;
    cout << "Enter number of nodes: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<pair<int, int>> edges(E);

    cout << "Enter edges (separate by space and enter):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    // Create adjacency list
    vector<vector<int>> adjList = createAdjacencyList(V, edges);

    // Output adjacency list
    cout << "List:\n";
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}
