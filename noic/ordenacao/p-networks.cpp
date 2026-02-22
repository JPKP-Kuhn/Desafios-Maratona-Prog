#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  while(cin >> n && n){
    unordered_set<ll> ordem;
    vll target(n);
    for (ll i{}; i<n; i++){
      ll x; cin >> x;
      ordem.insert(x);
      target[i] = x;
    }
    if ((ll)ordem.size() < n){
      cout << "No solution\n";
    } else {
      vll v(n); iota(v.begin(), v.end(), 1);
      vll ans;

      for (ll i{}; i<n; i++){
        ll pos=i;
        while(target[i] != v[pos]) pos++;

        while(pos > i){
          swap(v[pos], v[pos-1]);
          ans.push_back(pos);
          pos--;
        }
      }


      ll m = ans.size();
      cout << m << ' ';
      for (ll i=m-1; i>=0; i--) cout << ans[i] << ' ';
      cout << '\n';
    }
  }

  return 0;
}

