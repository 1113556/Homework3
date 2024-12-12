//蔡宗修
//1113556
//12/9
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent an edge with a weight
struct Edge {
    int vertex, weight;
    Edge(int v, int w) : vertex(v), weight(w) {}
};

// Comparator for the priority queue (min-heap)
struct CompareEdge {
    bool operator()(Edge const& e1, Edge const& e2) {
        return e1.weight > e2.weight; // Min-heap based on edge weight
    }
};

// Function to compute the weight of the MST using Prim's algorithm
int primMST(int V, vector<vector<Edge>>& adj) {
    vector<bool> visited(V, false);  // To track visited nodes
    priority_queue<Edge, vector<Edge>, CompareEdge> pq;  // Min-heap for the edges
    int mstWeight = 0;  // Total weight of the MST

    // Start with vertex 0
    pq.push(Edge(0, 0));

    while (!pq.empty()) {
        Edge current = pq.top();
        pq.pop();

        // If the vertex is already visited, continue to the next edge
        if (visited[current.vertex]) {
            continue;
        }

        // Mark the vertex as visited
        visited[current.vertex] = true;
        mstWeight += current.weight;

        // Add all unvisited neighbors to the priority queue
        for (const Edge& neighbor : adj[current.vertex]) {
            if (!visited[neighbor.vertex]) {
                pq.push(neighbor);
            }
        }
    }

    return mstWeight;
}

int main() {
    int V, E;
    cout << "vertices: ";
    cin >> V;
    cout << " edges: ";
    cin >> E;

    // Initialize adjacency list
    vector<vector<Edge>> adj(V);

    cout << " weight :\n";
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back(Edge(v, weight));
        adj[v].push_back(Edge(u, weight));  // Since it's an undirected graph
    }

    // Compute the MST weight using Prim's algorithm
    int result = primMST(V, adj);

    cout << "Weight of the Minimum Spanning Tree: " << result << endl;

    return 0;
}
