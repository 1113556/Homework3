//蔡宗修
//1113556
//12/9
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// Function to perform BFS traversal
vector<int> BFS(int V, vector<vector<int>>& adj) {
    vector<int> bfsTraversal;
    vector<bool> visited(V, false); // To track visited vertices

    queue<int> q; // Queue for BFS
    q.push(0);    // Start BFS from vertex 0
    visited[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        bfsTraversal.push_back(node);

        // Traverse neighbors in the order they appear in the adjacency list
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return bfsTraversal;
}

int main() {
    // Input number of vertices
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> adj(V);

    cout << "Enter adjacency list (use -1 to end a list):\n";
    for (int i = 0; i < V; i++) {
        cout << "V " << i << ": ";
        int neighbor;
        while (cin >> neighbor && neighbor != -1) {
            adj[i].push_back(neighbor);
        }
    }

    // Perform BFS traversal
    vector<int> result = BFS(V, adj);

    // Output BFS traversal
    cout << "BFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
