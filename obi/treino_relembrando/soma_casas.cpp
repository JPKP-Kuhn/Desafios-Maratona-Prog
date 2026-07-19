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
  vll c(n);
  for (ll &x : c)
    cin >> x;
  ll k;
  cin >> k;

  for (ll i{}; i < n; i++) {
    ll x = k - c[i];

    ll l = i + 1, r = n - 1;
    while (l <= r) {
      ll mid = (l + r) / 2;

      if (c[mid] == x) {
        cout << c[i] << ' ' << c[mid] << '\n';
        return 0;
      } else if (c[mid] < x) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
  }

  return 0;
}
