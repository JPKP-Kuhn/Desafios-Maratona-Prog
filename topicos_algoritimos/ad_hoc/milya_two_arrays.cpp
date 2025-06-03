#include <bits/stdc++.h>
#include <ios>
#include <vector>
#include <set>

using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t{};
  cin >> t;
  while (t--) {
    int n{};
    cin >> n;

    vll a(n);
    set<ll> aSet;

    vll b(n);
    set<ll> bSet;

    for (ll i=0;i<n;i++) {
      cin >> a[i];
      aSet.insert(a[i]);
    }

    for (ll i=0;i<n;i++) {
      cin >> b[i];
      bSet.insert(b[i]);
    }

    if (aSet.size() >= 2 && bSet.size() >= 2) {
      cout << "YES" << '\n';
    } else {

      vll c(n);
      set<ll> cSet;
      
      for (ll i=0;i<n;i++) {
        c[i] = a[i] + b[i];
        cSet.insert(c[i]);
      }

      int size = cSet.size();

      if (size < 3) {
        sort(a.begin(), a.end());
        vll d(n);
        set<ll> dSet;

        for (ll i=0;i<n;i++) {
          d[i] = a[i] + b[i];
          dSet.insert(d[i]);
        }

        size = dSet.size();
      }

      cout << (size >= 3 ? "YES" : "NO") << '\n';
    }
  }

  return 0;
}

