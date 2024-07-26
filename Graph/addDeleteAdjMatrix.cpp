#include <iostream>
#include <vector>

using namespace std;

// Function to create an adjacency matrix for a directed graph
vector<vector<int>> createAdjacencyMatrixDirected(int n) {
    return vector<vector<int>>(n, vector<int>(n, 0));
}

// Function to add an edge to the adjacency matrix for a directed graph
void addEdgeDirected(vector<vector<int>>& adjMatrix, int u, int v) {
    adjMatrix[u][v] = 1;
}

// Function to delete an edge from the adjacency matrix for a directed graph
void deleteEdgeDirected(vector<vector<int>>& adjMatrix, int u, int v) {
    adjMatrix[u][v] = 0;
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
    int n; // Number of nodes
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<vector<int>> adjMatrix = createAdjacencyMatrixDirected(n);

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add an edge\n";
        cout << "2. Delete an edge\n";
        cout << "3. Display adjacency matrix\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 4) {
            cout << "Exiting program.\n";
            break;
        }

        int u, v;
        switch (choice) {
            case 1:
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                addEdgeDirected(adjMatrix, u, v);
                break;
            case 2:
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                deleteEdgeDirected(adjMatrix, u, v);
                break;
            case 3:
                cout << "Adjacency Matrix:\n";
                printAdjacencyMatrix(adjMatrix);
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
