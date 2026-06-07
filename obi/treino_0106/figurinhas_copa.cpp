#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;

int main() {
  _ ll n, c, m;
  cin >> n >> c >> m;
  unordered_map<ll, bool> fig;
  for (ll i{1}; i <= n; i++)
    fig[i] = false;
  for (ll i{}; i < c; i++) {
    ll x;
    cin >> x;
    fig[x] = true;
  }
  unordered_set<ll> contado;

  ll cont{};
  while (m--) {
    ll x;
    cin >> x;

    if (fig[x]) {
      if (!contado.count(x)) {
        contado.insert(x);
        cont++;
      }
    }
  }

  ll sobra = c - cont;
  cout << (sobra > 0 ? sobra : 0) << '\n';
  return 0;
}
