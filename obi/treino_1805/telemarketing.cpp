#include <bits/stdc++.h>
#include <queue>
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
  _ ll n, l;
  cin >> n >> l;

  vll vendedores(n, 0);
  priority_queue<pl, vpll, greater<pl>> vt;

  for (ll i{}; i < n; i++) {
    vt.push({0, i});
  }

  while (l--) {
    ll t;
    cin >> t;

    ll id = vt.top().second;
    ll tempo = vt.top().first;
    vt.pop();

    vt.push({tempo + t, id});
    vendedores[id]++;
  }

  for (ll i = 0; i < n; i++) {
    cout << i + 1 << ' ' << vendedores[i] << '\n';
  }

  return 0;
}
