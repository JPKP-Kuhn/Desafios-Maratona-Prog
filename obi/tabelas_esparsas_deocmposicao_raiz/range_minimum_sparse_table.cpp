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
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

const ll K = 25;
ll st[K + 1][MAXN];

int main() {
  _ ll n;
  cin >> n;
  for (ll i = 0; i < n; i++) {
    cin >> st[0][i];
  }

  for (ll i = 1; i <= K; i++) {
    for (ll j = 0; j + (1 << i) <= n; j++) {
      st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
  }
  ll q;
  cin >> q;
  ll lg[MAXN + 1];
  lg[1] = 0;
  for (ll i = 2; i <= MAXN; i++)
    lg[i] = lg[i / 2] + 1;
  while (q--) {
    ll l, r;
    cin >> l >> r;
    ll i = lg[r - l + 1];
    cout << min(st[i][l], st[i][r - (1 << i) + 1]) << '\n';
  }

  return 0;
}
