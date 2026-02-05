#include <bits/stdc++.h>
#include <deque>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  deque<ll> de;
  for (ll i{}; i<n; i++){
    ll x; cin >> x;
    if (x==0) de.pop_back();
    else de.push_back(x);
  }
  ll sum{};
  while(!de.empty()){
    sum+=de.front();
    de.pop_front();
  }
  cout << sum << '\n';

  return 0;
}

