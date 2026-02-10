#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

bool palindrome(vll &v){
  ll len = v.size();
  for (ll i{}; i<len/2; i++){
    if (v[i] != v[len-i-1]) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  vll v(n);
  for(ll &x: v) cin >> x;
  if (palindrome(v)) cout << "YES\n";
  else cout << "NO\n";

  return 0;
}

