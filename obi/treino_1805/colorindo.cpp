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

int main() {
  _ ll n, m, x, y, k;
  cin >> n >> m >> x >> y >> k;

  vector<vb> mat(n, vb(m, false));
  mat[n - x][m - y] = true;

  while (k--) {
    ll a, b;
    cin >> a >> b;

    mat[n - a][m - b] = true;
  }
  queue<pl> q;
  q.push({n - x, m - y});

  vll dx = {0, 1, 1, 1, 0, -1, -1, -1};
  vll dy = {1, 1, 0, -1, -1, -1, 0, 1};

  ll c{1};
  while (!q.empty()) {
    pl p = q.front();
    q.pop();

    for (ll d{}; d < 8; d++) {
      ll nx = p.first + dx[d];
      ll ny = p.second + dy[d];

      if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if (!mat[nx][ny]) {
          mat[nx][ny] = true;
          q.push({nx, ny});
          c++;
        }
      }
    }
  }

  // for (vb k : mat) {
  //   for (bool b : k) {
  //     cout << b << ' ';
  //   }
  //   cout << '\n';
  // }
  cout << c << '\n';

  return 0;
}
