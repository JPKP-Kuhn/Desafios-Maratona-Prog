#include <bits/stdc++.h>
#include <ctime>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n{}, q{};
  cin >> n >> q;
  ll mat[n][n];

  for (ll i = 0; i < n; i++) {
    string linha{};
    cin >> linha;
    for (ll j = 0; j<n;j++) {
      mat[i][j] = linha[j] - '0';
    }
  }

  vll adx = {0, -1, -1, -1, 0, 1, 1, 1};
  vll ady = {-1, -1, 0, 1, 1, 1, 0, -1};

  while (q--) {
    ll next_mat[n][n];

    for (ll i=0;i<n;i++){
      for (ll j=0;j<n;j++){
        if (mat[i][j] == 0){
          ll cvivos{};
          for (ll k=0;k<8;k++){
            ll nx = i + adx[k];
            ll ny = j + ady[k];
            if ((0 <= nx && nx < n) && (0 <= ny && ny < n)){
              if (mat[nx][ny] == 1) cvivos++;
            }
          }

          if (cvivos == 3){
            next_mat[i][j] = 1;
          } else {
            next_mat[i][j] = 0;
          }
        } else { // célula viva
          ll cvivos{};
          for (ll k=0;k<8;k++){
            ll nx = i + adx[k];
            ll ny = j + ady[k];

            if ((0 <= nx && nx < n) && (0 <= ny && ny < n)){
              if (mat[nx][ny] == 1) cvivos++;
            }
          }
          if (cvivos < 2 || cvivos > 3){
            next_mat[i][j] = 0;
          } else {
            next_mat[i][j] = 1;
          }
        }
      }
    }
    for (ll i =0;i<n;i++) {
      for (ll j =0;j<n;j++) {
        mat[i][j] = next_mat[i][j];
      }
    }
  } 

  for (ll i=0;i<n;i++){
    for (ll j=0;j<n;j++){
      cout << mat[i][j];
    }
    cout << '\n';
  }

  return 0; 

}
