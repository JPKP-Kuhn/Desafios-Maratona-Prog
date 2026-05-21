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

int main() {
  _ ll n, m;
  cin >> n >> m;
  vb pedras(n, false);
  while (m--) {
    ll p, d;
    cin >> p >> d;
    p--;
    for (ll i = p; i < n; i += d)
      pedras[i] = true;

    for (ll i = p; i >= 0; i -= d)
      pedras[i] = true;
  }

  for (bool b : pedras) {
    cout << (b ? 1 : 0) << '\n';
  }

  return 0;
}
