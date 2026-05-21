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

// M_PI para número PI
const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

ll n, k, total;
vll v;

void solve(ll i, ll m, ll sz) {
  if (m > n)
    return;

  if (i == k) {
    if (sz > 0) {
      if (sz % 2 == 0)
        total -= n / m;
      else
        total += n / m;
    }
    return;
  }
  solve(i + 1, m * v[i], sz + 1);
  solve(i + 1, m, sz);
}

int main() {
  _ total = 0;
  cin >> n >> k;
  v.clear();
  v.resize(k);
  for (ll &x : v)
    cin >> x;

  solve(0, 1, 0);
  cout << n - total << '\n';

  return 0;
}
