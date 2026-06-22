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

using ll = int;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

const ll MAXN = 2e3 + 10; // Range seguro para vetores e arrays

int n;
int x[MAXN], y[MAXN];
int mx[MAXN];
int dp[MAXN][MAXN];

long long dist(ll i, ll j) {
  long long dx = x[i] - x[j];
  long long dy = y[i] - y[j];
  return (dx * dx + dy * dy);
}

int main() {
  _ cin >> n;

  for (ll i{1}; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  vpll par;

  for (ll i{}; i <= n; i++)
    for (ll j{1}; j <= n; j++)
      if (i != j)
        par.pb({i, j});

  sort(all(par), [](pl a, pl b) {
    return dist(a.first, a.second) < dist(b.first, b.second);
  });

  for (ll i{}; i < (int)par.size(); i++) {
    ll j{};
    for (j = i; j < (int)par.size() &&
                dist(par[i].fr, par[i].sc) == dist(par[j].fr, par[j].sc);
         j++) {
      ll u = par[j].fr, v = par[j].sc;

      dp[u][v] = 1 + mx[v];
    }

    for (j = i; j < (int)par.size() &&
                dist(par[i].fr, par[i].sc) == dist(par[j].fr, par[j].sc);
         j++) {
      ll u = par[j].fr, v = par[j].sc;
      mx[u] = max(mx[u], dp[u][v]);
    }
    i = j - 1;
  }
  ll ans{};
  for (ll i = 1; i <= n; i++)
    ans = max(ans, dp[0][i]);

  cout << ans << '\n';

  return 0;
}
