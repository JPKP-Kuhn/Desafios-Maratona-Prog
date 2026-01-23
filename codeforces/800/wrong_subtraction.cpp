#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, k; cin >> n >> k;
  for (ll i=1; i<=k; i++){
    if (n%10==0) n /=10;
    else n--;
  }
  cout << n << '\n';

  return 0;
}

