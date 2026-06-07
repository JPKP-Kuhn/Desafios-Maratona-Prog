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

const ll INF = 1e18 + 5; // PD e inicialização de valor mínimo

int main() {
  _ ll n;
  cin >> n;

  double menor = INF;

  while (n--) {
    double p;
    cin >> p;
    ll g;
    cin >> g;

    menor = min(menor, 1000 * p / g);

    // g = p
    // 1000 = x
  }

  cout << fixed << setprecision(2) << menor << '\n';

  return 0;
}
