#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

const ll maxn = 200010;
ll n;
vector<ll> employers[maxn];
vector<ll> ns (maxn, 0);
vector<bool> visited (maxn, false);

ll dfs(ll node) {
  ll count = 0;

  visited[node] = true;

  for (ll i : employers[node]) {
    if (! visited[i]) {
      count += 1 + dfs(i);
    }
  }
  ns[node] = count;
  return count;
}

int main() {
  cin >> n;
  ll x;

  for (ll i = 2; i <= n;i++){
    cin >> x;
    x--;
    employers[x].push_back(i-1);
  }

  dfs(0);

  for (ll i = 0; i < n; i++) {
    cout << ns[i] << ' ';
  }
  cout << endl;
  

  return 0;
}

