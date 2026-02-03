#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  ll j=1;
  for (ll i=n-1; i>=0; i--){
    cout << string(i, ' ') << string(j, '*') << '\n';
    j+=2;
  }

  return 0;
}

