#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack, const vector<vector<int>>& adjList) {
    visited[v] = true;
    
    for (int neighbor : adjList[v]) {
        if (!visited[neighbor]) {
            topologicalSortUtil(neighbor, visited, Stack, adjList);
        }
    }
    
    Stack.push(v);
}

void topologicalSort(const vector<vector<int>>& adjList) {
    stack<int> Stack;
    vector<bool> visited(adjList.size(), false);
    
    for (int i = 0; i < adjList.size(); ++i) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, Stack, adjList);
        }
    }
    
    cout << "Topological Sort:\n";
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << endl;
}

int main() {
    int n = 6; // Number of nodes
    vector<vector<int>> adjList(n);
    
    adjList[5].push_back(2);
    adjList[5].push_back(0);
    adjList[4].push_back(0);
    adjList[4].push_back(1);
    adjList[2].push_back(3);
    adjList[3].push_back(1);
    
    topologicalSort(adjList);
    
    return 0;
}
