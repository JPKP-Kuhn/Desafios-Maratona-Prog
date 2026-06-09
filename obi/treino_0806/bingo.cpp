#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;

int main() {
  _
      // n cartelas com k números entre 1 e u
      ll n,
      k, u;
  cin >> n >> k >> u;

  vector<unordered_set<ll>> card(n);
  vll count(n, 0);

  for (ll i{}; i < n; i++) {
    for (ll j{}; j < k; j++) {
      ll x;
      cin >> x;
      card[i].insert(x);
    }
  }
  set<ll> ganha;
  bool ganhou = false;
  while (u--) {
    ll q;
    cin >> q;

    if (!ganhou) {
      for (ll i{}; i < n; i++) {
        if (card[i].count(q)) {
          count[i]++;
        }
      }
    }
    for (ll i{}; i < n; i++) {
      if (count[i] == k) {
        ganha.insert(i + 1);
        ganhou = true;
      }
    }
  }
  for (ll g : ganha) {
    cout << g << ' ';
  }
  cout << '\n';

  return 0;
}
