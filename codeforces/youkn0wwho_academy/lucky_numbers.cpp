#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

bool lucky(ll x){
  string s = to_string(x);
  for (char c : s){
    if (c != '4' && c != '7') 
      return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll a, b; cin >> a >> b;
  vll luc{};
  for (ll i=a; i<=b; i++){
    if (lucky(i)) luc.push_back(i);
  }
  if (luc.size() == 0) cout << -1 << '\n';
  else {
    for (ll i : luc) cout << i << ' ';
    cout << '\n';
  }

  return 0;
}

