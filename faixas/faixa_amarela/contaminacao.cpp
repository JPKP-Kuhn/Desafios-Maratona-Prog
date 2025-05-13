#include <bits/stdc++.h>
using namespace std;
char mat[51][51];

int main() {
  int n, m;
  while (scanf("%d %d", &n, &m) == 2) {
    if (n == 0 && m == 0) {
      break;
    }
    
    for (int i = 0; i < n; i++) {
      scanf("%s", mat[i]);
    }
    
    int dx[4] = {-1, 0, 1, 0};  // Up, Left, Down, Right
    int dy[4] = {0, -1, 0, 1};
    
    queue<pair<int, int>> averificar;
    
    // Find all 'T' cells and add them to the queue
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mat[i][j] == 'T') {
          averificar.push({i, j});
        }
      }
    }

    while(!averificar.empty()){
      int x = averificar.front().first;
      int y = averificar.front().second;

      averificar.pop();

      for (int d = 0; d < 4; d++){
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m){

          if(mat[nx][ny] == 'A'){
            mat[nx][ny] = 'T';
            averificar.push({nx, ny});
          }
        }
      }
    }


    for (int i = 0; i < n; i++){
      printf("%s\n", mat[i]);
    }
    printf("\n");
  }
  return 0;
}
