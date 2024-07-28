/*
Depth First Search (DFS)
Algorithm Steps:

Start by pushing the starting node onto a stack.
Pop the top item from the stack and print it.
Push all its unvisited adjacent nodes onto the stack.
Repeat steps 2 and 3 until the stack is empty.

*/

#include <iostream>
#include <vector>
#include <list>

class Graph {
    int V;
    std::vector<std::list<int>> adj;

    void DFSUtil(int v, std::vector<bool>& visited) {
        visited[v] = true;
        std::cout << v << " ";

        for (auto i : adj[v])
            if (!visited[i])
                DFSUtil(i, visited);
    }

public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFS(int v) {
    std::vector<bool> visited(V, false);
    DFSUtil(v, visited);
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "Depth First Traversal starting from vertex 2:\n";
    g.DFS(2);

    return 0;
}
