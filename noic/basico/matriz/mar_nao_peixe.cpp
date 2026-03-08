#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  vector<vb> mat(101, vb(101, false));
  ll c{};
  while(n--){
    ll xi, xf, yi, yf; cin >> xi >> xf >> yi >> yf;
    for (ll i=xi; i<xf; i++){
      for (ll j=yi; j<yf; j++){
        if(!mat[i][j]){
          mat[i][j]=true; c++;
        }
      }
    }
  }
  cout << c << '\n';

  return 0;
}

