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

using ll = long long;
using vll = vector<ll>;

int main() {
  _ ll t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    ll tam = s.size();
    ll inter = count(all(s), '?');
    ll uns = count(all(s), '1');
    ll zero = count(all(s), '0');

    ll l{}, r{tam - 1};
    if (uns > 0)
      for (ll i = tam - 1; i >= 0; i--) {
        if (s[i] == '1') {
          l = i;
          break;
        }
      }

    if (zero > 0)
      for (ll i{}; i < tam; i++) {
        if (s[i] == '0') {
          r = i;
          break;
        }
      }
    cout << r - l + 1 << '\n';
  }

  return 0;
}
