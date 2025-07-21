#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll h, w;
  cin >> h >> w;
  vector<vll> mat(h+1, vll(w+1, 0));
  vector<vll> prefix(h+1, vll(w+1, 0));
  for (ll i=1; i<h; i++){
    for (ll j=1; j<w; j++){
      cin >> mat[i][j];
      prefix[i][j] = mat[i][j] + prefix[i-1][j] + prefix[i][j-1] + prefix[i-1][j-1];
    }
  }

  ll q;
  cin >> q;
  while(q--){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll sum{};

    sum = prefix[c][d] - prefix[a-1][d] - prefix[c][b-1] - prefix[a-1][b-1];
    cout << sum << '\n';
  }

  return 0;
}

