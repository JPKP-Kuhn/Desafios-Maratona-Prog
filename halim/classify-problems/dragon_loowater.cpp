#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m;
  while(cin >> n >> m && n && m){
    vll head(n), knight(m);
    for (ll &x : head) cin >> x;
    for (ll &y : knight) cin >> y;

    sort(head.begin(), head.end());
    sort(knight.begin(), knight.end());

    if (n > m){
      cout << "Loowater is doomed!\n";
    } else {
      ll sum{};
      bool f{};
      for (ll h : head){
        auto it = lower_bound(knight.begin(), knight.end(), h);
        if (it == knight.end()){
          f = true; break;
        }
        sum+=*it;
        knight.erase(it);
      }
      if (f)
        cout << "Loowater is doomed!\n";
      else
       cout << sum << '\n';
    }
  }

  return 0;
}

