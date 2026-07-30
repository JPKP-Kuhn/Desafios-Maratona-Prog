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

const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo

const ll K = 25;
ll st[K + 1][MAXN];
int main() {
  _ ll n, q;
  cin >> n >> q;

  for (ll i{}; i < n; i++) {
    cin >> st[0][i];
  }
  for (ll i = 1; i <= K; i++) {
    for (ll j{}; j + (1LL << i) <= n; j++) {
      st[i][j] = max(st[i - 1][j], st[i - 1][j + (1LL << (i - 1))]);
    }
  }

  ll cont{};
  ll lg[MAXN + 1];
  lg[1] = 0;
  for (ll i = 2; i <= MAXN; i++) {
    lg[i] = lg[i / 2] + 1;
  }
  while (q--) {
    ll a, b;
    cin >> a >> b;
    ll from = a - 1;
    ll l = min(a, b), r = max(a, b) - 2;

    if (l > r) {
      cont++;
      continue;
    }
    ll i = lg[r - l + 1];
    ll v = max(st[i][l], st[i][r - (1LL << i) + 1]);
    if (v <= st[0][from])
      cont++;
  }

  cout << cont << '\n';

  return 0;
}
