#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;

bool pa(vll &v) {
  if (v.size() >= 2) {
    ll antes = v[1] - v[0];
    for (ll i = 1; i < v.size() - 1; i++) {
      ll soma = v[i + 1] - v[i];
      if (soma != antes)
        return false;
    }
    return true;
  }
  return false;
}

int main() {
  _ ll n;
  cin >> n;
  vll v(n);
  for (ll &x : v)
    cin >> x;

  if (pa(v)) {
    cout << 1 << '\n';
  } else {
    ll c{};
    ll r = v[1] - v[0];
    for (ll i{1}; i < v.size() - 1; i++) {
      ll soma = v[i + 1] - v[i];
      if (soma != r) {
        c++;
        i++;
        r = v[i + 1] - v[i];
      }
    }
    c++;

    cout << c << '\n';
  }

  return 0;
}
