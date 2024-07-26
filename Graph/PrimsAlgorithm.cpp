#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void Prim(const vector<vector<pair<int, int>>>& adjList) {
    int n = adjList.size();
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    pq.push({0, 0});
    key[0] = 0;
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        inMST[u] = true;
        
        for (const auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
    
    cout << "Minimum Spanning Tree Edges:\n";
    for (int i = 1; i < n; ++i) {
        cout << parent[i] << " -- " << i << " == " << key[i] << endl;
    }
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<pair<int, int>>> adjList(n);
    
    adjList[0].push_back({1, 2});
    adjList[0].push_back({3, 6});
    adjList[1].push_back({0, 2});
    adjList[1].push_back({2, 3});
    adjList[2].push_back({1, 3});
    adjList[2].push_back({3, 8});
    adjList[3].push_back({0, 6});
    adjList[3].push_back({2, 8});
    
    Prim(adjList);
    
    return 0;
}
