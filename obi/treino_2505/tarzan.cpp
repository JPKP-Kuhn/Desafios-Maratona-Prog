#include <bits/stdc++.h>
using namespace std;

using ll = int;
using vll = vector<ll>;
using vb = vector<bool>;

struct point {
  ll x, y;
};

bool dist(point a, point b, ll d) {
  ll dx = a.x - b.x;
  ll dy = a.y - b.y;

  return dx * dx + dy * dy <= d * d;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n, d;
  cin >> n >> d;

  vector<point> v(n);

  for (point &p : v) {
    cin >> p.x >> p.y;
  }

  queue<ll> q;
  vb visited(n, false);
  q.push(0);
  visited[0] = true;

  while (!q.empty()) {
    ll a = q.front();
    q.pop();

    for (ll i{}; i < n; i++) {
      if (!visited[i] && dist(v[a], v[i], d)) {
        visited[i] = true;
        q.push(i);
      }
    }
  }

  for (bool b : visited) {
    if (!b) {
      cout << "N\n";
      return 0;
    }
  }
  cout << "S\n";

  return 0;
}
