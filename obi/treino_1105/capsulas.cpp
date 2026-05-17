#include <bits/stdc++.h>
#include <cmath>
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

/*
 * 3 12
 * 3 7 2
 * d/3 + d/7 + d/2 = 12
 * 4 + 2 + 7
 *
 * d/n1 + d/n2 + ... d/nn >= f
 *
 * 3 * 12 = 36
 * 2 * 12 = 24
 * 7 * 12 = 84
 */

int main() {
  _ ll n, f;
  cin >> n >> f;
  vll v(n);
  for (ll &x : v)
    cin >> x;

  // busca binária pela resposta
  ll low = 0;
  ll high = 1e8;
  ll dias{};
  while (low <= high) {
    ll mid = (low + high) / 2;

    ll moedas{};
    for (ll m : v) {
      moedas += mid / m;
    }

    if (moedas >= f) {
      dias = mid;
      high = mid - 1;
    } else
      low = mid + 1;
  }
  cout << dias << '\n';

  return 0;
}
