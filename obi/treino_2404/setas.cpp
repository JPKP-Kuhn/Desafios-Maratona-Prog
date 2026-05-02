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
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

ll n;
vector<string> mat;
vector<vll> state; // 0=unvisited, 1=vis, 2=safe, 3=usafe

pl next_pos(ll i, ll j) {
  char c = mat[i][j];
  if (c == '>')
    return {i, j + 1};
  else if (c == '<')
    return {i, j - 1};
  else if (c == 'V')
    return {i + 1, j};
  else if (c == 'A')
    return {i - 1, j};

  return {0, 0};
}

bool dfs(ll i, ll j) {
  if (i < 0 || i >= n || j < 0 || j >= n) {
    return false;
  }

  ll est = state[i][j];
  if (est == 1 || est == 2)
    return true;
  else if (est == 3)
    return false;

  state[i][j] = 1;
  auto [ni, nj] = next_pos(i, j);
  bool res = dfs(ni, nj);

  state[i][j] = (res ? 2 : 3);
  return res;
}

int main() {
  _ cin >> n;
  mat.resize(n);
  state.resize(n, vll(n, 0));
  for (ll i{}; i < n; i++)
    cin >> mat[i];

  ll ans{};
  for (ll i{}; i < n; i++) {
    for (ll j{}; j < n; j++) {
      if (dfs(i, j))
        ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
