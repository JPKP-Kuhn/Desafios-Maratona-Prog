#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m;
  while(cin >> n >> m && n>0 && m>0){
    ll a=min(n, m), b=max(n,m);
    ll sum = ((b-a+1) * (b+a))/2;
    for (ll i=a; i<=b; i++){
      cout << i << ' ';
    }
    cout << "sum =" << sum << '\n';
  }

  return 0;
}

