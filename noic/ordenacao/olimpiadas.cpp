#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m; cin >> n >> m;
  vll v(n); iota(v.begin(), v.end(), 1);
  unordered_map<ll, vll> mp;
  for (ll i=1; i<=n; i++) mp[i] = vll(3);

  while(m--){
    ll o, p, b; cin >> o >> p >> b;
    mp[o][0]++; mp[p][1]++; mp[b][2]++;
  }

  sort(v.begin(), v.end(), [&](ll a, ll b){
      if (mp[a][0] != mp[b][0]) return mp[a][0] > mp[b][0];
      if (mp[a][1] != mp[b][1]) return mp[a][1] > mp[b][1];
      if (mp[a][2] != mp[b][2]) return mp[a][2] > mp[b][2];
      return a < b;
      });

  for (ll i : v) cout << i << ' ';
  cout << '\n';

  return 0;
}

