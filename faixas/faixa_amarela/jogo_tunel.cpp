#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using vpll = vector<pair<ll, ll>>;


ll n, m;
vll nx = {0, 1, 0, -1};
vll ny = {1, 0, -1, 0};
pair<ll, ll> pai;
pair<ll, ll> inicio;

void dfs(const vector<vector<string>> &mat, vector<vb> &vis, ll orientacao){
  for (ll i=0; i<4; i++){
    ll dx = inicio.first + nx[i];
    ll dy = inicio.second + ny[i];

    if (dx >= 0 && dx < n && dy >= 0 && dy < m){
      if (!vis[dx][dy]){
        if (mat[dx][dy] == "0"){
          pai.first = inicio.first; pai.second = inicio.second;
          inicio.first = dx; inicio.second = dy;
          vis[dx][dy] = true;

          if (dx == pai.first+1 && dy == pai.second){
            if (orientacao == 0){
              cout << "F ";
            } else if (orientacao == 1){
              cout << "R F ";
            } else if (orientacao == 3){
              cout << "L F ";
            }
            orientacao = 0;
          } else if (dx == pai.first && dy == pai.second+1){
            if (orientacao == 0){
              cout << "L F ";
            } else if (orientacao == 2){
              cout << "R F ";
            } else if (orientacao == 1){
              cout << "F ";
            }
            orientacao = 1;
          } else if (dx == pai.first && dy == pai.second-1){
            if (orientacao == 0){
              cout << "R F ";
            } else if (orientacao == 2){
              cout << "L F ";
            } else if (orientacao == 3){
              cout << "F ";
            }
            orientacao = 3;
          } else if (dx == pai.first-1 && dy == pai.second){
            if (orientacao == 1){
              cout << "L F ";
            } else if (orientacao == 2){
              cout << "F ";
            } else if (orientacao == 3){
              cout << "R F ";
            }
            orientacao = 2;
          }

          dfs(mat, vis, orientacao);
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin >> n >> m){
    vector<vector<string>> mat(n, vector<string>(m));
    vector<vb> vis(n, vb(m, false));
    ll orientacao{};

    for (ll i=0; i<n; i++){
      for (ll j=0; j<m; j++){
        cin >> mat[i][j];
        if (mat[i][j] == "X"){
          inicio.first = i; inicio.second = j;
          for (ll k=0; k<4; k++){
            ll dx = i + nx[k];
            ll dy = j + ny[k];
            if (dx >= 0 && dx < n && dy >= 0 && dy < m){
              if (mat[dx][dy] == "0"){
                if (dx == i+1 && dy==j){
                  orientacao = 0;
                } else if (dx == i && dy == j+1){
                  orientacao = 1;
                } else if (dx == i-1 && dy == j){
                  orientacao = 2;
                } else if (dx == i && dy == j-1){
                  orientacao = 3;
                }
              }
            }
          }
        }
      }
    }

    pai.first = -1; pai.second = -1;
    vis[inicio.first][inicio.second] = true;
    dfs(mat, vis, orientacao);
    cout << "E\n";
  }

  return 0;
}

