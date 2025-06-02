#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m;
  while(cin >> n >> m && (m != 0 || n != 0)) {

    vector<vector<ll>> mat(m, vector<ll>(n));
    for (ll i=0;i<n;i++){
      for (ll j=0;j<m;j++) {
        cin >> mat[i][j];
      }
    }

    ll res {0};
    
    // Todo problema foi resolvido por pelo menos 1
    bool todos_problemas_resolvidos = true;
    for (ll j = 0; j<m; j++) {
      bool problema_resolvido = false;

      for (ll i=0; i < n;i++){
        if (mat[i][j] == 1) {
          problema_resolvido = true;
          break;
        }
      }
      if (!problema_resolvido){
        todos_problemas_resolvidos = false;
        break;
      }
    }

    if (todos_problemas_resolvidos) res++;

    // Nenhum problema foi resolvido por todos 
    bool nenhum_problema_resolvido_todos = true;
    for (ll j=0; j < m; j++) {
      bool todos_resolveram = true;
      for (ll i = 0; i<n; i++) {
        if (mat[i][j] == 0){
          todos_resolveram = false;
          break;
        }
      }

      if (todos_resolveram) {
        nenhum_problema_resolvido_todos = false;
        break;
      }
    }

    if (nenhum_problema_resolvido_todos) res++;

    // Todo particpiante resolveu pelo menos 1 problema
    bool todos_resolveram_um = true;
    for (ll i=0;i<n;i++) {
      bool resolveu_todos = true;
      for (ll j = 0; j<m; j++) {
        if (mat[i][j] == 0){
          resolveu_todos = false;
          break;
        }
      }
      if (resolveu_todos) {
        nenhum_problema_resolvido_todos = false;
        break;
      }
    }
    if (nenhum_problema_resolvido_todos) res++;

    cout << res << endl;
  }

  return 0;
}

