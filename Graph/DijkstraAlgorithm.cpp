#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void Dijkstra(const vector<vector<pair<int, int>>>& adjList, int start) {
    int n = adjList.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    pq.push({0, start});
    dist[start] = 0;
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        for (const auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
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
    
    adjList[0].push_back({1, 10});
    adjList[0].push_back({4, 3});
    adjList[1].push_back({2, 2});
    adjList[1].push_back({4, 4});
    adjList[2].push_back({3, 9});
    adjList[3].push_back({2, 7});
    adjList[4].push_back({1, 1});
    adjList[4].push_back({2, 8});
    
    cout << "Dijkstra's shortest paths from node 0:\n";
    Dijkstra(adjList, 0);
    
    return 0;
}
