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

// M_PI para número PI
const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

struct point {
  double x, y;
  point() { x = y = 0.0; }
  point(double _x, double _y) : x(_x), y(_y) {}
  bool operator<(point other) const {
    if (fabs(x - other.x) > EPS)
      return x < other.x;
    return y < other.y;
  };
};

int main() {
  _ ll j;
  ll teste{};
  while (cin >> j && j) {
    vector<pair<ll, string>> jogadores{};
    for (ll caso = 1; caso <= j; caso++) {
      string nome;
      cin >> nome;
      vll p(12);
      for (ll &x : p)
        cin >> x;
      sort(all(p));
      ll pontos{};
      for (ll i = 1; i < 11; i++) {
        pontos += p[i];
      }
      jogadores.pb({pontos, nome});
    }
    sort(jogadores.begin(), jogadores.end(),
         [](pair<ll, string> a, pair<ll, string> b) {
           if (a.first != b.first)
             return a.first > b.first;
           return a.second < b.second;
         });
    cout << "Teste " << ++teste << '\n';
    ll o = 1;
    cout << o << ' ' << jogadores[0].first << ' ' << jogadores[0].second
         << '\n';
    ll ant = jogadores[0].first;
    for (ll c{1}; c < jogadores.size(); c++) {
      auto &[p, n] = jogadores[c];
      if (p != ant) {
        ant = p;
        o = c + 1;
      }
      cout << o << ' ' << p << ' ' << n << '\n';
    }
    cout << '\n';
  }

  return 0;
}
