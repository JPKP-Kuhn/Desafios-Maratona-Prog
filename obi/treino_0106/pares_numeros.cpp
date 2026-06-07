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

int main() {
  _ ll n, mini, f;
  cin >> n >> mini >> f;
  vll v(n);
  for (ll &x : v)
    cin >> x;

  ll c{};
  for (ll i{}; i < n; i++) {
    for (ll j = i + 1; j < n; j++) {
      ll soma = v[i] + v[j];
      if (soma >= mini && soma <= f)
        c++;
    }
  }
  cout << c << '\n';

  return 0;
}
