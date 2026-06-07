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
  _ ll v, p;
  cin >> v >> p;

  ll r = v % p;
  if (r == 0) {
    ll q = v / p;
    for (ll i{}; i < p; i++) {
      cout << q << '\n';
    }
  } else {
    ll q = v / p;
    for (ll i{}; i < r; i++) {
      cout << q + 1 << '\n';
    }

    for (ll i{}; i < p - r; i++) {
      cout << q << '\n';
    }
  }

  return 0;
}
