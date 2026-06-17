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
  _ string s;
  cin >> s;
  ll maior{}, temp{1};
  char l = s[0];

  for (ll i{1}; i < s.length(); i++) {
    if (s[i] == l)
      temp++;
    else {
      maior = max(maior, temp);
      temp = 1;
      l = s[i];
    }
  }

  maior = max(maior, temp);

  cout << maior << '\n';

  return 0;
}
