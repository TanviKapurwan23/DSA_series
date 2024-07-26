#include <iostream>
#include <vector>

using namespace std;

// Function to create an adjacency matrix for an undirected graph
vector<vector<int>> createAdjacencyMatrixUndirected(int n, const vector<pair<int, int>>& edges) {
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    
    for (int i = 0; i < edges.size(); ++i) {
        int u = edges[i].first;
        int v = edges[i].second;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
    
    return adjMatrix;
}

// Function to create an adjacency matrix for a directed graph
vector<vector<int>> createAdjacencyMatrixDirected(int n, const vector<pair<int, int>>& edges) {
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    
    for (int i = 0; i < edges.size(); ++i) {
        int u = edges[i].first;
        int v = edges[i].second;
        adjMatrix[u][v] = 1;
    }
    
    return adjMatrix;
}

// Function to print the adjacency matrix
void printAdjacencyMatrix(const vector<vector<int>>& adjMatrix) {
    int n = adjMatrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice;
    
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Create and display adjacency matrix for an undirected graph\n";
        cout << "2. Create and display adjacency matrix for a directed graph\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 3) {
            cout << "Exiting program.\n";
            break;
        }

        int n; // Number of nodes
        cout << "Enter the number of nodes: ";
        cin >> n;

        vector<pair<int, int>> edges;
        int e; // Number of edges
        cout << "Enter the number of edges: ";
        cin >> e;
        cout << "Enter each edge in the format (u v):\n";
        for (int i = 0; i < e; ++i) {
            int u, v;
            cin >> u >> v;
            edges.emplace_back(u, v);
        }

        switch (choice) {
            case 1: {
                vector<vector<int>> adjMatrix = createAdjacencyMatrixUndirected(n, edges);
                cout << "Undirected Graph Adjacency Matrix:\n";
                printAdjacencyMatrix(adjMatrix);
                break;
            }
            case 2: {
                vector<vector<int>> adjMatrix = createAdjacencyMatrixDirected(n, edges);
                cout << "Directed Graph Adjacency Matrix:\n";
                printAdjacencyMatrix(adjMatrix);
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    
    return 0;
}
