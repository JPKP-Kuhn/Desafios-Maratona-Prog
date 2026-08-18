#include <algorithm>
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
  _ string a, b;
  cin >> a >> b;
  ll ca = -1, cb = -1;

  for (ll i{}; i < a.size(); i++) {
    for (ll j{}; j < b.size(); j++) {
      if (a[i] == b[j]) {
        if (i + 1 > ca) {
          ca = i + 1;
          cb = j + 1;
        }

        if (j + 1 > cb) {
          ca = i + 1;
          cb = j + 1;
        }
      }
    }
  }

  cout << ca << ' ' << cb << '\n';

  return 0;
}
