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
  ll maior{1}, tempmaior{1};

  for (ll i{}; i < s.size() - 1; i++) {
    if (s[i] == s[i + 1])
      tempmaior++;
    else {
      maior = max(maior, tempmaior);
      tempmaior = 1;
    }
  }

  if (s[s.size() - 2] == s[s.size() - 1])
    maior = max(maior, tempmaior);

  cout << maior << '\n';

  return 0;
}
