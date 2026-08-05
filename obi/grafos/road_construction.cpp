#include <bits/stdc++.h>
#include <utility>
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

ll n, m;
ll pai[MAXN];
ll componentes;
ll find(ll x) {
  if (pai[x] == x)
    return x;

  pai[x] = find(pai[x]);
  return pai[x];
}

ll tamanho[MAXN];
ll maior = 0;
void join(ll x, ll y) {
  x = find(x);
  y = find(y);

  if (x != y) {
    if (tamanho[x] < tamanho[y])
      swap(x, y);
    pai[y] = x;
    tamanho[x] += tamanho[y];
    maior = max(maior, tamanho[x]);
    componentes--;
  }
}

int main() {
  _ cin >> n >> m;
  componentes = n;
  for (ll i{1}; i <= n; i++) {
    pai[i] = i;
    tamanho[i] = 1;
  }

  while (m--) {
    ll a, b;
    cin >> a >> b;
    join(a, b);
    cout << componentes << ' ' << maior << '\n';
  }

  return 0;
}
