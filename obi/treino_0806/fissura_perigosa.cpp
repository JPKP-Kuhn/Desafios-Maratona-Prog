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

int main() {
  _ ll n, f;
  cin >> n >> f;

  vector<string> mat(n);
  for (string &x : mat)
    cin >> x;

  if (f >= mat[0][0] - '0') {
    mat[0][0] = '*';
    vll dx = {0, 1, 0, -1};
    vll dy = {1, 0, -1, 0};

    queue<pair<ll, ll>> q;
    q.push({0, 0});

    while (!q.empty()) {
      pair<ll, ll> p = q.front();
      q.pop();

      for (ll i{}; i < 4; i++) {
        ll nx = p.first + dx[i];
        ll ny = p.second + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
          if (mat[nx][ny] != '*') {
            if (f >= mat[nx][ny] - '0') {
              mat[nx][ny] = '*';
              q.push({nx, ny});
            }
          }
        }
      }
    }
  }

  for (string s : mat) {
    cout << s << '\n';
  }

  return 0;
}
