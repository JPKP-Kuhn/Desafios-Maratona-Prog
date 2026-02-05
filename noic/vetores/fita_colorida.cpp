#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll n;

ll dist_prox(ll i, vll &v){
  ll dd{}, de{};
  ll idx = i;

  bool fe=false;
  while(i >=0){
    if (v[i]!=0){
      de++; i--;
    } else {
      fe = true; break;
    }
  }
  if (!fe) de=100000;

  i = idx;
  bool fd = false;
  while(i<n){
    if (v[i]!=0){
      dd++; i++;
    } else{
      fd=true; break;
    }
  }
  if (!fd) dd=100000;
  return min(dd, de);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  vll q(n);
  for (ll &x : q) cin >> x;

  for (ll i{}; i<n; i++){
    if (q[i] == -1){
      ll dist = dist_prox(i, q);
      q[i] = min(dist, 9LL);
    }
  }
  for (ll f : q){
    cout << f << ' ';
  }
  cout << '\n';

  return 0;
}

