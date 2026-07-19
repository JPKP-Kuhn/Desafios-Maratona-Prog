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

int main() {
  _ ll n, m;
  ll teste{};
  while (cin >> n >> m && n && m) {
    vll v(n);
    for (ll &x : v)
      cin >> x;
    ll maior = -INF;
    ll menor = INF;

    for (ll i{}; i + m <= n; i++) {
      ll soma{};
      for (ll j{i}; j - i < m && j < n; j++) {
        soma += v[j];
      }
      ll media = soma / m;
      maior = max(maior, media);
      menor = min(menor, media);
    }

    cout << "Teste " << ++teste << '\n';
    cout << menor << ' ' << maior << '\n';
    cout << '\n';
  }

  return 0;
}
