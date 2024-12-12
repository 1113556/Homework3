//蔡宗修
//1113556
//12/9
#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS traversal
void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& dfsTraversal) {
    // Mark the node as visited
    visited[node] = true;
    // Add the node to the traversal list
    dfsTraversal.push_back(node);

    // Visit all the neighbors of the current node
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited, dfsTraversal);
        }
    }
}

// Main function
int main() {
    // Input number of vertices
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> adj(V);

    cout << "Enter adjacency list (use space to separate and -1 to end a list):\n";
    for (int i = 0; i < V; i++) {
        cout << "V " << i << ": ";
        int neighbor;
        while (cin >> neighbor && neighbor != -1) {
            adj[i].push_back(neighbor);
        }
    }

    // Create a visited array
    vector<bool> visited(V, false);

    // Vector to store the DFS traversal result
    vector<int> dfsTraversal;

    // Start DFS from vertex 0
    DFS(0, adj, visited, dfsTraversal);

    // Output the DFS traversal
    cout << "DFS Traversal: ";
    for (int node : dfsTraversal) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
