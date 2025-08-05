#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;

  vll novo;
  vll novos;
  while (n--){
    ll m; cin >> m;
    ll k{};

    for (ll i=0; i<m; i++){
      ll x;
      cin >> x;
      if (count(novo.begin(), novo.end(), x) == 0){
        novo.push_back(x);
        k++;
      }
    }
    novos.push_back(k);
  }
  cout << *max_element(novos.begin(), novos.end()) << '\n';

  return 0;
}

