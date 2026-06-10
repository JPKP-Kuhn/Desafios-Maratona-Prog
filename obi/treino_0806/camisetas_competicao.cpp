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
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

int main() {
  _ ll n;
  cin >> n;
  vll v(n);
  for (ll &x : v)
    cin >> x;

  unordered_map<ll, ll> tshirt;
  ll p, m;
  cin >> p >> m;
  tshirt[1] = p;
  tshirt[2] = m;

  ll um{}, dois{};
  for (ll i : v) {
    if (i == 1) {
      um++;
    } else {
      dois++;
    }

    if (um > tshirt[1] || dois > tshirt[2]) {
      cout << "N\n";
      return 0;
    }
  }
  cout << "S\n";

  return 0;
}
