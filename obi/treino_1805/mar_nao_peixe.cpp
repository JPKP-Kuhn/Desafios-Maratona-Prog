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
  vector<vb> mat(101, vb(101, false));
  ll c{};
  while (n--) {
    ll xi, xf, yi, yf;
    cin >> xi >> xf >> yi >> yf;
    for (ll i = xi; i < xf; i++) {
      for (ll j = yi; j < yf; j++) {
        if (!mat[i][j]) {
          mat[i][j] = true;
          c++;
        }
      }
    }
  }
  cout << c << '\n';

  return 0;
}
