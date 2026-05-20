#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;

int main() {
  _ ll n;
  cin >> n;
  ll tot{}, fim{};
  for (ll i{}; i < n; i++) {
    ll x;
    cin >> x;

    if (x < fim) {
      tot += (x + 10) - fim;
    } else {
      tot += 10;
    }
    fim = x + 10;
  }

  cout << tot << '\n';
  return 0;
}
