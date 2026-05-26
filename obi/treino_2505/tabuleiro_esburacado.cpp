#include <bits/stdc++.h>
#include <unordered_map>
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
  _ ll n;
  cin >> n;
  ll c{};

  ll mx = 4;
  ll my = 3;

  map<ll, ll> dx = {{1, 1},  {2, 2},  {3, 2},  {4, 1},
                    {5, -1}, {6, -2}, {7, -2}, {8, -1}};

  map<ll, ll> dy = {{1, 2},  {2, 1},  {3, -1}, {4, -2},
                    {5, -2}, {6, -1}, {7, 1},  {8, 2}};

  vll v(n);
  for (ll &x : v)
    cin >> x;

  for (ll i{}; i < n; i++) {
    ll entr = v[i];

    ll x = mx + dx[entr];
    ll y = my + dy[entr];

    c++;
    if ((x == 1 && y == 3) || (x == 2 && y == 3) || (x == 2 && y == 5) ||
        (x == 5 && y == 4)) {
      break;
    } else {
      mx = x;
      my = y;
    }
  }
  cout << c << '\n';
  return 0;
}
