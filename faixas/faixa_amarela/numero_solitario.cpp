#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  while (cin >> n && n != 0){
    map<ll, ll> pares;
    for (ll i=0; i<n; i++){
      ll x;
      cin >> x;
      pares[x] += 1;
    }
    for (auto key = pares.begin(); key != pares.end(); ++key){
      if (key->second % 2 != 0){
        cout << key->first << '\n';
        return 0;
      }
    }

  }

  return 0;
}

