#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f91(ll x){
  if (x<=100) return f91(f91(x+11));
  return x-10;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  while(cin >> n && n){
    ll r = f91(n);
    cout << "f91(" << n << ") = " << r << '\n';
  }

  return 0;
}

