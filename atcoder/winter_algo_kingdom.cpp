#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll h, w, n;
  cin >> h >> w >> n;
  vector<vll> mat(h+2, vll(w+2, 0));
  for (ll i=0; i<n; i++){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; b--; c--; d--;

    mat[a][b] += 1;
    mat[c+1][b] -= 1;
    mat[a][d+1] -= 1;
    mat[c+1][d+1] += 1;
  }

  for (ll i=0; i<h; i++){
    for (ll j=1; j<w; j++){
      mat[i][j] += mat[i][j-1];
    }
  }

  for (ll j=0; j<w; j++){
    for (ll i=1; i<h; i++){
      mat[i][j] += mat[i-1][j];
    }
  }


  for (ll i=0; i<h; i++){
    for (ll j=0; j<w; j++){
      cout << mat[i][j] << ' ';
    }
    cout << '\n';
  }


  return 0;
}

