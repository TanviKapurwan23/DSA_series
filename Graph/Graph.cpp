#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class Graph {
private:
    unordered_map<string, unordered_set<string>> adjList;

public:
    // Add a vertex to the graph
    bool addVertex(const string& vertex) {
        if (adjList.count(vertex) == 0) {
            adjList[vertex] = unordered_set<string>();
            return true;
        }
        return false; // Vertex already exists
    }

    // Remove a vertex and all its edges from the graph
    bool removeVertex(const string& vertex) {
        if (adjList.count(vertex) == 0) {
            return false; // Vertex does not exist
        }
        // Remove all edges connected to this vertex
        for (const string& neighbor : adjList[vertex]) {
            adjList[neighbor].erase(vertex);
        }
        adjList.erase(vertex);
        return true;
    }

    // Add an edge between two vertices
    bool addEdge(const string& vertex1, const string& vertex2) {
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
            adjList[vertex1].insert(vertex2);
            adjList[vertex2].insert(vertex1);
            return true;
        }
        return false; // One or both vertices do not exist
    }

    // Remove an edge between two vertices
    bool removeEdge(const string& vertex1, const string& vertex2) {
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
            adjList[vertex1].erase(vertex2);
            adjList[vertex2].erase(vertex1);
            return true;
        }
        return false; // One or both vertices do not exist
    }

    // Print the adjacency list of the graph
    void printGraph() const {
        for (const auto& pair : adjList) {
            cout << pair.first << ": ";
            for (const auto& neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph;

    // Add vertices
    graph.addVertex("A");
    graph.addVertex("B");
    graph.addVertex("C");
    graph.addVertex("D");

    // Add edges
    graph.addEdge("A", "B");
    graph.addEdge("A", "C");
    graph.addEdge("B", "C");
    graph.addEdge("C", "D");

    // Print graph
    cout << "Graph after adding vertices and edges:" << endl;
    graph.printGraph();

    // Remove an edge
    graph.removeEdge("A", "C");

    // Print graph
    cout << "\nGraph after removing the edge A-C:" << endl;
    graph.printGraph();

    // Remove a vertex
    graph.removeVertex("C");

    // Print graph
    cout << "\nGraph after removing vertex C:" << endl;
    graph.printGraph();

    return 0;
}
