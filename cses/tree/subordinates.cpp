#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 2 * pow(10, 5) + 10;
vll employers[MAXN];
vll subordinates(MAXN, 0);
vll visited (MAXN, false);

ll dfs(ll node) {
  ll count{};

  visited[node] = true;

  for (ll u : employers[node]) {
    if (!visited[u]){
      count += 1 + dfs(u);
    }
  }
  subordinates[node] = count;
  return count;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n{};
  cin >> n;

  ll x{};
  for (ll i = 2; i<=n; i++) {
    cin >> x; x--;
    employers[x].push_back(i-1);
  }

  dfs(0);

  for (ll i = 0; i < n; i++) {
    cout << subordinates[i] << ' ';
  }
  cout << endl;

  return 0;
}

