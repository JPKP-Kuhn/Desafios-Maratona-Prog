#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;

bool rightBox (ll n, vector<vll>& casejewel) {
  for (ll i=0;i<n;i++){
    for (ll j=0;j<n-1;j++){
      if (casejewel[i][j] >= casejewel[i][j+1]) return false;
      if (casejewel[j][i] >= casejewel[j+1][i]) return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n{};
  cin >> n;
  vector<vll> casejewel(n, vll(n));

  for (ll i=0;i<n;i++){
    for (ll j=0;j<n;j++){
      cin >> casejewel[i][j];
    }
  }

  ll rotations{};
  while(!rightBox(n, casejewel) && rotations<4){

    // Rotates couterclockwise
    for (ll i = 0; i < n; i++) {
      for (ll j = i + 1; j < n; j++) {
        swap(casejewel[i][j], casejewel[j][i]);
      }
    }
    for (ll j = 0; j<n; j++) {
      for (ll i = 0; i<n/2;i++){
        swap(casejewel[i][j], casejewel[n - 1 - i][j]);
      }
    }

    rotations++;
  }

  cout << rotations << '\n';


  return 0;
}

