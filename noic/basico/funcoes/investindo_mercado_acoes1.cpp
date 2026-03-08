#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll n, k;
ll solve(ll x){
  if (x<=k) return 1;
  return solve(x/2) + solve((x+1)/2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while(cin >> n >> k && n && k){
    ll c=1LL;
    if (n>k){
      c = solve(n);
    }
    cout << c << '\n';
  }

  return 0;
}

