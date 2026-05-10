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
  _ ll c, f;
  ll teste{};
  while (cin >> c >> f) {
    if (c == 0 && f == 0)
      break;

    vll dp(c + 1, 0);
    for (ll i{}; i < f; i++) {
      ll n, d;
      cin >> n >> d;

      // máximo número de desculpes usando a capacidade j
      for (ll j = c; j >= n; j--) {
        dp[j] = max(dp[j], dp[j - n] + d);
      }
    }

    cout << "Teste " << ++teste << '\n';
    cout << dp[c] << "\n\n";
  }

  return 0;
}
