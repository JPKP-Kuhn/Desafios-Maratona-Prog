#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pl>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll c{}, n; cin >> n;
  vpll prereq(n+1);
  vector<vll> d(n+1);
  vb learn(n+1, false);

  queue<ll> q;

  for (ll i=1; i<=n; i++){
    ll a, b; cin >> a >> b;

    prereq[i] = {a, b};
    if (a == 0 && b == 0){
      learn[i] = true;
      q.push(i);
      c++;
    } else {
      if (a != 0) d[a].push_back(i);
      if (b != 0) d[b].push_back(i);
    }
  }

  while(!q.empty()){
    ll cur = q.front(); q.pop();

    for (ll h : d[cur]){
      if (!learn[h]){
        auto [a, b] = prereq[h];
        if ((a != 0 && learn[a]) || (b != 0 && learn[b])){
          learn[h] = true;
          q.push(h);
          c++;
        }
      }
    }
  }

  cout << c << '\n';
  return 0;
}

