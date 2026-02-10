#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

ll n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  vector<vll> mat(n, vll(n));
  unordered_map<ll, ll>soma_linhas{};
  unordered_map<ll, ll>soma_colunas{};
  for (ll i{}; i<n; i++){
    for (ll j{}; j<n; j++){
      cin >> mat[i][j];
      soma_linhas[i]+=mat[i][j];
      soma_colunas[j]+=mat[i][j];
    }
  }
  ll maior{};

  for (ll i{}; i<n; i++){
    for (ll j{}; j<n; j++){
      maior = max(maior, soma_linhas[i] + soma_colunas[j] - 2*mat[i][j]);
    }
  }
  cout << maior << '\n';

  return 0;
}

