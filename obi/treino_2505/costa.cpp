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

int main() {
  _ ll n, m;
  cin >> n >> m;
  vector<string> mat(n);

  queue<pl> pos;
  for (ll i{}; i < n; i++) {
    string x;
    cin >> x;
    mat[i] = x;
    for (ll j{}; j < m; j++) {
      if (x[j] == '#')
        pos.push({i, j});
    }
  }

  vll dx = {0, 1, 0, -1};
  vll dy = {1, 0, -1, 0};

  ll c{};
  while (!pos.empty()) {
    ll x = pos.front().first;
    ll y = pos.front().second;
    pos.pop();

    for (ll d{}; d < 4; d++) {
      ll nx = x + dx[d];
      ll ny = y + dy[d];

      if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if (mat[nx][ny] == '.') {
          c++;
          break;
        }
      } else {
        c++;
        break;
      }
    }
  }

  cout << c << '\n';

  return 0;
}
