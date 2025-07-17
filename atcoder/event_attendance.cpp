#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll d, n;
  cin >> d >> n;
  vll workers(d);
  vll delta(d+2, 0);
  for (ll i=0; i<n; i++){
    ll l, r;
    cin >> l >> r; l--; r--;
    delta[l] += 1;
    delta[r+1] -= 1;
  }

  workers[0] = delta[0];
  for (ll i =1; i<d; i++){
    workers[i] = workers[i-1] + delta[i];
  }
  for (ll i : workers){
    cout << i << '\n';
  }

  return 0;
}

