#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,i,j;
  while(cin >> n >> i >> j){
    i--; j--;
    ll r=1;
    while(i >> r != j >> r) r++;
    cout << r << '\n';
  }

  return 0;
}

