#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

bool busca_binaria(const vll &v, const ll &x){
  ll a{}, b=v.size()-1;
  while (a<=b){
    ll mid = (a+b)/2;
    if (v[mid]==x) return true;
    else if (v[mid] < x)a=mid+1;
    else b=mid-1;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,q; cin >> n >> q;
  vll v(n);
  for(ll &x : v)cin >> x;
  sort(v.begin(), v.end());
  while(q--){
    ll x; cin >> x;
    if (busca_binaria(v, x)) cout << "found\n";
    else cout << "not found\n";
  }

  return 0;
}

