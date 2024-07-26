#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

int find(int parent[], int i) {
    if (parent[i] == i) return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    
    if (xroot != yroot) {
        if (rank[xroot] < rank[yroot]) {
            parent[xroot] = yroot;
        } else if (rank[xroot] > rank[yroot]) {
            parent[yroot] = xroot;
        } else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }
}

void Kruskal(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end(), compareEdges);
    
    vector<Edge> result;
    int parent[n], rank[n];
    
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }
    
    for (const auto& edge : edges) {
        int x = find(parent, edge.u);
        int y = find(parent, edge.v);
        
        if (x != y) {
            result.push_back(edge);
            Union(parent, rank, x, y);
        }
    }
    
    cout << "Minimum Spanning Tree Edges:\n";
    for (const auto& edge : result) {
        cout << edge.u << " -- " << edge.v << " == " << edge.weight << endl;
    }
}

int main() {
    int n = 4; // Number of nodes
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    
    Kruskal(edges, n);
    
    return 0;
}
