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
  if (pai[x] == x) {
    return x;
  }
  pai[x] = find(pai[x]);
  return pai[x];
}

ll peso[MAXN];
void join(ll x, ll y) {
  x = find(x);
  y = find(y);

  if (x == y)
    return;

  if (peso[x] < peso[y])
    pai[x] = y;
  else if (peso[x] > peso[y])
    pai[y] = x;
  else if (peso[x] == peso[y]) {
    pai[x] = y;
    peso[y]++;
  }
}

int main() {
  _ ll n, b;
  cin >> n >> b;
  for (ll i{1}; i <= n; i++)
    pai[i] = i;
  while (b--) {
    char c;
    cin >> c;
    ll b1, b2;
    cin >> b1 >> b2;
    if (c == 'F') {
      join(b1, b2);
    } else {
      if (find(b1) == find(b2))
        cout << "S\n";
      else
        cout << "N\n";
    }
  }

  return 0;
}
