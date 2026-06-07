#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
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

int main() {
  _ ll n, k, m;
  cin >> n >> k >> m;

  vpll color(n);
  for (ll i{}; i < n; i++) {
    ll c, v;
    cin >> c >> v;
    color[i] = {v, c};
  }
  vll fir, ext;
  sort(rall(color));

  unordered_map<ll, ll> cont;
  for (ll i{1}; i <= n; i++) {
    cont[i] = 0;
  }
  for (ll i{}; i < n; i++) {
    ll c = color[i].second;
    ll v = color[i].first;

    if (cont[c] == 0) {
      fir.push_back(v);
      cont[c]++;
    } else {
      ext.push_back(v);
    }
  }
  sort(rall(fir));

  ll valor{};
  for (ll i{}; i < fir.size(); i++) {
    if (i < m)
      valor += fir[i];
    else
      ext.push_back(fir[i]);
  }

  sort(rall(ext));
  for (ll i{}; i < k - m; i++) {
    valor += ext[i];
  }

  cout << valor << '\n';

  return 0;
}
