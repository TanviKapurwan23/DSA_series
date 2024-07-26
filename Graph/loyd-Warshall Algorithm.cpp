#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void FloydWarshall(vector<vector<int>>& dist) {
    int n = dist.size();
    
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int n = 4; // Number of nodes
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    
    dist[0][1] = 3;
    dist[0][2] = 7;
    dist[1][2] = 1;
    dist[1][3] = 2;
    dist[2][3] = 3;
    
    FloydWarshall(dist);
    
    cout << "Shortest distances between every pair of nodes:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
