#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

bool all_even(vll &v){
  for (ll i{}; i<(int)v.size(); i++){
    if (v[i]%2==1) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  vll v(n);
  for (ll &x : v) cin >> x;
  ll c{};

  while(all_even(v)){
    c++;
    for (vll::iterator i=v.begin(); i<v.end(); i++){
      *i/=2;
    }
  }
  cout << c << '\n';

  return 0;
}

