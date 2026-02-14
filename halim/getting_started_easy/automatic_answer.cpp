#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  while(t--){
    ll n; cin >> n;
    ll r = abs(((((((n*567)/9) + 7492) * 235)/47)-498)/10);
    cout << r%10 << '\n';
  }

  return 0;
}

