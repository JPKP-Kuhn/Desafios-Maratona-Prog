#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m; cin >> n >> m;
  vector<vll> mat(n, vll(m));

  for (ll i{}; i<n; i++){
    for (ll j{}; j<m; j++){
      cin >> mat[i][j];
    }
  }

  for (vll &i : mat){
    reverse(i.begin(), i.end());
  }

  for (ll i{}; i<n; i++){
    for (ll j{}; j<m; j++){
      cout << mat[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}

