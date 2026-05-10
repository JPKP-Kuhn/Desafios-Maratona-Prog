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

ll pai[MAXN];

ll find(ll x) {
  if (pai[x] == x)
    return x;
  return pai[x] = find(pai[x]);
}

ll peso[MAXN];
void join(ll a, ll b) {
  a = find(a);
  b = find(b);

  if (a == b)
    return;

  if (peso[a] < peso[b]) {
    pai[a] = b;
  } else if (peso[a] > peso[b]) {
    pai[b] = a;
  } else if (peso[a] == peso[b]) {
    pai[a] = b;
    peso[b]++;
  }
}

int main() {
  _ ll n, m;
  cin >> n >> m;
  for (ll i = 1; i <= n; i++)
    pai[i] = i;

  while (m--) {
    ll a, b;
    cin >> a >> b;
    join(a, b);
  }
  ll c{};
  for (ll i = 1; i <= n; i++)
    if (find(i) == i)
      c++;

  cout << c << '\n';

  return 0;
}
