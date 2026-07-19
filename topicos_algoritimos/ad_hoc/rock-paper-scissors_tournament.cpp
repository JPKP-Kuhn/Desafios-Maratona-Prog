#include <bits/stdc++.h>
#include <iomanip>
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

const double PI = 3.14159265358979323846;
const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

int main() {
  _ ll n, k;
  bool pri = false;
  while (cin >> n && n) {
    cin >> k;
    vpll pwl(n + 1);
    for (ll i{}; i < k * n * (n - 1) / 2; i++) {
      ll p1, p2;
      string m1, m2;
      cin >> p1 >> m1 >> p2 >> m2;
      if (m1 == "rock") {
        if (m2 == "scissors") {
          pwl[p1].first++;
          pwl[p2].second++;
        } else if (m2 == "paper") {
          pwl[p2].first++;
          pwl[p1].second++;
        }
      } else if (m1 == "paper") {
        if (m2 == "rock") {
          pwl[p1].first++;
          pwl[p2].second++;
        } else if (m2 == "scissors") {
          pwl[p2].first++;
          pwl[p1].second++;
        }
      } else if (m1 == "scissors") {
        if (m2 == "paper") {
          pwl[p1].first++;
          pwl[p2].second++;
        } else if (m2 == "rock") {
          pwl[p2].first++;
          pwl[p1].second++;
        }
      }
    }

    map<ll, double> pa{};
    for (ll i = 1; i <= n; i++) {
      pa[i] = -1;
      if (!(pwl[i].first == 0 && pwl[i].second == 0))
        pa[i] = (double)pwl[i].first / (pwl[i].first + pwl[i].second);
    }

    if (pri) {
      cout << '\n';
    }
    for (auto &[k, v] : pa) {
      if (v == -1)
        cout << "-\n";
      else
        cout << fixed << setprecision(3) << v << '\n';
    }
    pri = true;
  }

  return 0;
}
