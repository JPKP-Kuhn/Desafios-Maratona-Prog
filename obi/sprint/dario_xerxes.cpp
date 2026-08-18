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

int main() {
  _ ll n;
  cin >> n;

  ll da{}, xe{};
  while (n--) {
    ll d, x;
    cin >> d >> x;
    if (d == 0) {
      if (x == 1 || x == 2)
        da++;
      else
        xe++;
    } else if (d == 1) {
      if (x == 3 || x == 2)
        da++;
      else
        xe++;
    } else if (d == 2) {
      if (x == 3 || x == 4)
        da++;
      else
        xe++;
    } else if (d == 3) {
      if (x == 0 || x == 4)
        da++;
      else
        xe++;
    } else if (d == 4) {
      if (x == 1 || x == 0)
        da++;
      else
        xe++;
    }
  }

  cout << (da > xe ? "dario\n" : "xerxes\n");

  return 0;
}
