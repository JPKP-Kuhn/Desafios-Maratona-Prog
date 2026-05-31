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

int main() {
  _ ll n;
  cin >> n;
  vector<vll> caixas(n);
  bool f = false;
  for (ll i{}; i < n; i++) {
    ll k;
    cin >> k;
    vll caixa(k);
    for (ll &x : caixa)
      cin >> x;

    ll diff = 0;
    for (ll d{}; d < k - 1; d++) {
      diff = caixa[d + 1] - caixa[d];
      if (diff < 0) {
        f = true;
      }
    }
    caixas[i] = caixa;
  }
  if (f) {
    cout << "NO\n";
    return 0;
  }

  sort(caixas.begin(), caixas.end(), [](const vll &a, const vll &b) {
    if (a[0] != b[0])
      return a[0] < b[0];
    return a.back() < b.back();
  });
  ll diff = 0;
  for (ll i{}; i < n - 1; i++) {
    for (ll j{}; j < caixas[i].size() - 1; j++) {
      diff = caixas[i][j + 1] - caixas[i][j];
      if (diff < 0) {
        cout << "NO\n";
        return 0;
      }
    }
    diff = caixas[i + 1][0] - caixas[i][caixas[i].size() - 1];
    if (diff < 0) {
      cout << "NO\n";
      return 0;
    }
  }

  for (ll i = n - 1; i < n; i++) {
    for (ll j{}; j < caixas[i].size() - 1; j++) {
      diff = caixas[i][j + 1] - caixas[i][j];
      if (diff < 0) {
        cout << "NO\n";
        return 0;
      }
    }
  }

  cout << "YES\n";
  return 0;
}
