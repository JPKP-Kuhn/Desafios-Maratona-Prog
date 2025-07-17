#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, q;
  cin >> n >> q;
  vll v(n+1); // soma[0] = 0
  for (ll i=1; i<=n; i++){
    cin >> v[i];
    v[i] += v[i-1]; // Soma acumulada 
  }
  while(q--){
    ll a, b;
    cin >> a >> b;
    cout << v[b] - v[a-1] << '\n'; // soma de v[a] até v[b];
  }

  return 0;
}

