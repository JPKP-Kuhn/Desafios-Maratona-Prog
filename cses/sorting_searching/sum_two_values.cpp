#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vpl = vector<pair<ll, ll>>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, x; cin >> n >> x;
  vpl v(n);
  for(ll i{}; i<n; i++){
    ll x; cin >> x;
    v[i].first = x;
    v[i].second=i;
  }
  sort(v.begin(), v.end());
  ll a{}, b=n-1;
  while(a < b){
    ll sum = v[a].first + v[b].first;
    if (sum == x){
      cout << v[a].second+1 << ' ' << v[b].second+1 << '\n';
      return 0;
    } else if (sum < x) {
      a++;
    } else if (sum > x){
      b--;
    }

  }
  cout << "IMPOSSIBLE\n";
  

  return 0;
}

