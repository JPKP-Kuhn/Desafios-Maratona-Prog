#include <bits/stdc++.h>
using namespace std;

// DFS function to mark all connected floor cells as visited
void dfs(vector<string>& mat, int i, int j, int n, int m) {
    // Check if current position is valid and is a floor
    if (i < 0 || i >= n || j < 0 || j >= m || mat[i][j] == '#') {
        return;
    }
    
    mat[i][j] = '#';
    
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    // Explore all four directions
    for (int d = 0; d < 4; d++) {
        int nx = i + dx[d];
        int ny = j + dy[d];
        dfs(mat, nx, ny, n, m);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> mat(n);
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    
    int rooms = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '.') {
                rooms++;
                
                // Use DFS to mark all connected floor tiles as visited
                dfs(mat, i, j, n, m);
            }
        }
    }
    
    cout << rooms << endl;
    
    return 0;
}
