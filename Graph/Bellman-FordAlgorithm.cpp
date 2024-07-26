#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void BellmanFord(const vector<vector<pair<int, int>>>& adjList, int start) {
    int n = adjList.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    
    for (int i = 1; i < n; ++i) {
        for (int u = 0; u < n; ++u) {
            for (const auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }
    
    // Check for negative-weight cycles
    for (int u = 0; u < n; ++u) {
        for (const auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                cout << "Graph contains negative weight cycle\n";
                return;
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << "Distance from " << start << " to " << i << " is " << dist[i] << endl;
    }
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<pair<int, int>>> adjList(n);
    
    adjList[0].push_back({1, -1});
    adjList[0].push_back({2, 4});
    adjList[1].push_back({2, 3});
    adjList[1].push_back({3, 2});
    adjList[1].push_back({4, 2});
    adjList[3].push_back({4, 3});
    adjList[4].push_back({3, -5});
    
    cout << "Bellman-Ford shortest paths from node 0:\n";
    BellmanFord(adjList, 0);
    
    return 0;
}
