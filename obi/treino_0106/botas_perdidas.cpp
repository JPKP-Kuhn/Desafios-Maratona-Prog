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
  while (cin >> n) {
    unordered_map<ll, string> tam_bot{};
    for (ll i = 30; i <= 60; i++) {
      tam_bot[i] = "";
    }

    for (ll i{}; i < n; i++) {
      ll num;
      cin >> num;
      char c;
      cin >> c;
      tam_bot[num] += c;
    }

    ll cont{};
    for (auto &[k, v] : tam_bot) {
      ll dir{}, esq{};
      for (char pe : v) {
        if (pe == 'E')
          esq++;
        else
          dir++;
      }
      cont += min(dir, esq);
    }
    cout << cont << '\n';
  }

  return 0;
}
