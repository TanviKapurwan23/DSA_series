#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(const vector<vector<int>>& adjList, int start) {
    vector<bool> visited(adjList.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> adjList(n);
    
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(3);
    adjList[2].push_back(3);
    adjList[3].push_back(4);

    cout << "BFS starting from node 0: ";
    BFS(adjList, 0);
    
    return 0;
}
