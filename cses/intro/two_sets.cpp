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

const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

/*
 * 1 NO
 * 2 NO
 * 3 -> (1 2) (3)
 * 4 -> (4 1) (2 3)
 * 5 NO
 * 6 NO
 * 7 -> (1 2 4 7) (3 5 6)
 */

int main() {
  _ ll n;
  cin >> n;
  ll s = n * (n + 1) / 2;
  if (s & 1) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    // 1 2 3 4 5 6 7
    vll a, b;
    ll sa{}, sb{};
    for (ll i = n; i >= 1; i--) {
      if (a.empty()) {
        a.push_back(i);
        sa += i;
      } else if (b.empty()) {
        b.push_back(i);
        sb += i;
      } else if (sa > sb) {
        b.push_back(i);
        sb += i;
      } else {
        a.push_back(i);
        sa += i;
      }
    }
    sort(all(a));
    sort(all(b));
    cout << a.size() << '\n';
    for (ll x : a) {
      cout << x << ' ';
    }
    cout << '\n' << b.size() << '\n';
    for (ll y : b) {
      cout << y << ' ';
    }
    cout << '\n';
  }

  return 0;
}
