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

int main() {
  _ ll n;
  cin >> n;
  vll v(n);
  for (ll &x : v)
    cin >> x;
  sort(all(v));

  if (v[0] > 8) {
    cout << "N\n";
    return 0;
  } else {
    vll cima;
    for (ll i{}; i < n; i++) {
      if (v[i] <= 8) {
        cima.push_back(v[i]);
      } else {
        if (cima.empty()) {
          cout << "N\n";
          return 0;
        } else {
          ll c = cima[cima.size() - 1];
          if (v[i] - c > 8) {
            cout << "N\n";
            return 0;
          } else {
            cima.pop_back();
            cima.push_back(v[i]);
          }
        }
      }
    }
    cout << "S\n";
  }

  return 0;
}
