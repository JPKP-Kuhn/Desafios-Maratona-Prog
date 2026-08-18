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

const double PI = 3.14159265358979323846;
const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

int main() {
  _ ll c, l;
  cin >> c >> l;
  vector<string> mat(c);
  vector<vector<bool>> vis(c, vector<bool>(l, false));
  pair<ll, ll> in;
  for (ll i{}; i < c; i++) {
    string s;
    cin >> s;
    mat[i] = s;
    for (ll j{}; j < l; j++) {
      if (s[j] == 'o') {
        in = {i, j};
      }
    }
  }

  queue<pair<ll, ll>> q;
  q.push(in);
  vis[in.first][in.second] = true;
  vll di = {0, 1, 0, -1};
  vll dj = {1, 0, -1, 0};

  pl fim;
  while (!q.empty()) {
    pl pos = q.front();
    fim = pos;
    vis[pos.first][pos.second] = true;
    q.pop();

    for (ll d{}; d < 4; d++) {
      ll nx = pos.first + di[d];
      ll ny = pos.second + dj[d];

      if (nx >= 0 && nx < c && ny >= 0 && ny < l && mat[nx][ny] == 'H' &&
          !vis[nx][ny]) {
        q.push({nx, ny});
      }
    }
  }
  cout << fim.first + 1 << ' ' << fim.second + 1 << '\n';
  return 0;
}
