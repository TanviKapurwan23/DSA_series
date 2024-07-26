#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFSUtil(int v, vector<bool>& visited, const vector<vector<int>>& adjList) {
    stack<int> s;
    s.push(v);
    
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        
        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";
            
            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
}

void DFS(const vector<vector<int>>& adjList, int start) {
    vector<bool> visited(adjList.size(), false);
    DFSUtil(start, visited, adjList);
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> adjList(n);
    
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(3);
    adjList[2].push_back(3);
    adjList[3].push_back(4);

    cout << "DFS starting from node 0: ";
    DFS(adjList, 0);
    
    return 0;
}
