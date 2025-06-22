#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;          // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n{};
  cin >> n;
  vll station(n);
  for (ll i =0; i<n; i++){
    station[i] = i;
  }

  vll distances(n-1);
  for (ll i=0; i<n-1;i++){
    cin >> distances[i];
  }

  for (ll i=0; i<n-1; i++){
    ll soma{};
    cout << distances[i] << ' ';
    for (ll j=i+1; j<n-1; j++){
      soma += distances[j];
      cout << distances[i] + soma << ' ';
    }
    cout << '\n';
  }
  return 0;
}

