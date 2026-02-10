#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  unordered_map<ll, ll> num;
  for (ll i{}; i<n; i++){
    ll x; cin >> x;
    num[x]++;
  }
  unordered_map<ll, ll>sec;
  for (ll i{}; i<n; i++){
    ll x; cin >> x;
    if (!num.count(x)){
      cout << "no\n";
      return 0;
    }
    sec[x]++;
  }
  for (auto &[k, v] : num){
    if (v != sec[k]){
      cout << "no\n";
      return 0;
    }
  }
  cout << "yes\n";

  return 0;
}

