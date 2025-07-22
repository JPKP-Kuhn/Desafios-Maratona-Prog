#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> points(n);
  for (auto &x : points) cin >> x.first >> x.second;
  sort(points.begin(), points.end());
  for (ll i=0; i<n; i++){
    if (k >= points[i].first){
      k+=points[i].second;
    }
  }

  cout << k << '\n';
  return 0;
}

