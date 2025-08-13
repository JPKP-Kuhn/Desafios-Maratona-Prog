#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  deque<ll> v;
  for (ll i=0; i<n; i++){
    ll x; cin >> x;
    v.push_back(x);
  }

  ll c{};
  while(v.size() > 1){
    if (v.front() == v.back()){
      v.pop_front(); v.pop_back();
    } else if (v.front() > v.back()){
      c++;
      ll t = v.back(); v.pop_back();
      ll d = v.back(); v.pop_back();
      v.push_back(t+d);
    } else{
      c++;
      ll t = v.front(); v.pop_front();
      ll d = v.front(); v.pop_front();
      v.push_front(d+t);
    }
  }

  cout << c << '\n';
  return 0;
}

