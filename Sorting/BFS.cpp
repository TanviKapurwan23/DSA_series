/*
Breadth First Search (BFS)
Algorithm Steps:

Start by enqueueing the starting node onto a queue.
Dequeue a node from the queue and print it.
Enqueue all its unvisited adjacent nodes onto the queue.
Repeat steps 2 and 3 until the queue is empty.

*/

#include <iostream>
#include <vector>
#include <list>
#include <queue>

class Graph {
    int V;
    std::vector<std::list<int>> adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int s) {
    std::vector<bool> visited(V, false);
    std::queue<int> queue;

    visited[s] = true;
    queue.push(s);

    while (!queue.empty()) {
        s = queue.front();
        std::cout << s << " ";
        queue.pop();

        for (auto i : adj[s]) {
            if (!visited[i]) {
                visited[i] = true;
                queue.push(i);
            }
        }
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "Breadth First Traversal starting from vertex 2:\n";
    g.BFS(2);

    return 0;
}
