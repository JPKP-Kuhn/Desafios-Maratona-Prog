#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m; cin >> n >> m;
  vb pedras(n, false);

  for (ll i{}; i<m; i++){
    ll s, p; cin >> s >> p;
    ll g{};
    s--;
    g=s;
    pedras[s]=true;
    while(s>=0){
      pedras[s]=true;
      s-=p;
    }
    s=g;
    while(s<n){
      pedras[s]=true;
      s+=p;
    }
  }
  for (bool b : pedras){
    if (b) cout << 1 << '\n';
    else cout << 0 << '\n';
  }

  return 0;
}

