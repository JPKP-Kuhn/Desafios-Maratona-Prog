#include <bits/stdc++.h>
#include <queue>
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

ll ans{}, n, m;

void bfs(ll x, ll y, vector<vb> &mat) {
  vll dx = {0, 1, 0, -1};
  vll dy = {1, 0, -1, 0};

  queue<pl> q;
  q.push({x, y});
  mat[x][y] = false;

  while (!q.empty()) {
    pl p = q.front();
    ll i = p.fr, j = p.sc;
    mat[i][j] = false;
    q.pop();

    for (ll d{}; d < 4; d++) {
      ll nx = i + dx[d];
      ll ny = j + dy[d];

      if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny]) {
        mat[nx][ny] = false;
        q.push({nx, ny});
      }
    }
  }
}

int main() {
  _ cin >> n >> m;
  vector<vb> mat(n, vb(m));
  for (ll i{}; i < n; i++) {
    string s;
    cin >> s;
    for (ll j{}; j < m; j++) {
      if (s[j] == '.')
        mat[i][j] = true;
    }
  }
  ll a; cin >> a;

  for (ll i{}; i < n; i++) {
    for (ll j{}; j < m; j++) {
      if (mat[i][j]) {
        bfs(i, j, mat);
        ans++;
      }
    }
  }
  cout << ans << '\n';

  return 0;
}
