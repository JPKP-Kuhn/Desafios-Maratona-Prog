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
  _ ll n, k;
  cin >> n >> k;
  vll m(k);
  ll maior{};
  for (ll i{}; i < k; i++) {
    cin >> m[i];
    maior = max(maior, m[i]);
  }
  ll l = 1, b = maior;

  ll ans{};
  while (l <= b) {
    ll mid = (l + b) / 2;

    ll soma{};
    for (ll i{}; i < k; i++)
      soma += m[i] / mid;

    if (soma >= n) {
      ans = mid;
      l = mid + 1;
    } else {
      b = mid - 1;
    }
  }

  cout << ans << '\n';
  return 0;
}
