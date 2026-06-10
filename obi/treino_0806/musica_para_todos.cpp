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
  _ ll n, m, c;
  cin >> n >> m >> c;

  vll nxt(m + 1, 0);
  vb vis(m + 1, false);

  for (ll i{}; i < n; i++) {
    ll a, d;
    cin >> a >> d;
    if (nxt[d] == 0)
      nxt[d] = a;
  }

  ll curr = c;
  ll trocas{};

  while (nxt[curr] != 0) {
    if (vis[curr]) {
      cout << -1 << '\n';
      return 0;
    }

    vis[curr] = true;
    curr = nxt[curr];
    trocas++;
  }
  cout << trocas << '\n';

  return 0;
}
