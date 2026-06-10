#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
#define fr first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

int main() {
  _ ll n, c;
  cin >> n >> c;

  vector<vll> chain(n + 1);
  set<ll> candidatos;
  for (ll i = 1; i <= n; i++)
    candidatos.insert(i);
  for (ll i{}; i < c; i++) {
    ll p, idx;
    cin >> p >> idx;
    vll v(idx);
    for (ll &x : v) {
      cin >> x;
      candidatos.erase(x);
    }

    chain[p] = v;
  }

  for (ll i : candidatos) {
    cout << i << '\n';
  }

  return 0;
}
