#include <bits/stdc++.h>
using namespace std;

int main(){
  int a;

  for (;;){
    scanf("%d", &a);
    if (a == 0){break;}

    int mat[a][a];

    for (int i = 0; i < a; i++){
      for (int j = 0; j < a; j++){
        int dist_d = a - j - 1;
        int dist_e = j;
        int dist_c = i;
        int dist_b = a - i - 1;

        mat[i][j] = min({dist_d + 1, dist_b + 1, dist_e + 1, dist_c + 1});

      }
    }

    for (int i = 0; i < a; i++){
      printf("%3d", mat[i][0]);
      for (int j = 1; j < a; j++){
        printf(" %3d", mat[i][j]);
      }
      cout << "\n";
    }
    cout << "\n";
  }
  return 0;
}
