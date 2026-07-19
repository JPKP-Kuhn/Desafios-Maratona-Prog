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
  vector<string> v(n);
  for (string &x : v)
    cin >> x;

  vector<string> ans;
  bool f = false;
  for (ll i{}; i < n - 1; i++) {
    ans.push_back(v[i]);
    if (v[i].size() == v[i + 1].size()) {
      for (ll j = (v[i][0] - '0' < 9 ? 0 : 1); j < v[i].size(); j++) {
        char maior = v[i][j] + 1;
        while (maior <= '9' && !f) {
          string co = maior + v[i].substr(1, v[i].size() - 1);
          if (stoi(co) > stoi(v[i + 1])) {
            ans.pop_back();
            f = true;
            ans.push_back(co);
            break;
          } else {
            maior += 1;
          }
        }
      }
    }
  }
  ans.push_back(v[v.size() - 1]);
  for (ll i = 0; i < v[v.size() - 1].size(); i++) {
    char c = v[v.size() - 1][i];
    int num = c - '0';
    while (num > 0) {
      num--;
      string co
    }
  }

  if (!f) {
    cout << "impossible\n";
  } else {
    for (string s : ans) {
      cout << s << ' ';
    }
    cout << '\n';
  }

  return 0;
}
