#include <bits/stdc++.h>
#include <unordered_set>
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

int main() {
  _ ll n;
  cin >> n;
  vll v(n);
  for (ll &x : v)
    cin >> x;

  vpll eventos;
  for (ll i{}; i < n; i++) {
    eventos.push_back({v[i], i});
  }
  sort(eventos.rbegin(), eventos.rend());
  vb ativo(n, false);

  ll comp{}, ans{};

  for (auto &[h, i] : eventos) {
    bool l = i > 0 && ativo[i - 1];
    bool r = i + 1 < n && ativo[i + 1];

    if (!l && !r)
      comp++;
    else if (l && r)
      comp--;

    ativo[i] = true;

    ans = max(ans, comp);
  }

  cout << ans + 1 << '\n';

  return 0;
}
