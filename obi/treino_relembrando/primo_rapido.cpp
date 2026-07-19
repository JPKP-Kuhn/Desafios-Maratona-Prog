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

bool primo(ll x) {
  if (x == 1)
    return false;
  if (x == 2)
    return true;
  if (x % 2 == 0)
    return false;

  for (ll i = 3; i * i < x; i += 2) {
    if (x % i == 0)
      return false;
  }
  return true;
}

int main() {
  _ ll n;
  cin >> n;
  while (n--) {
    ll p;
    cin >> p;

    cout << (primo(p) ? "Prime" : "Not Prime") << '\n';
  }

  return 0;
}
