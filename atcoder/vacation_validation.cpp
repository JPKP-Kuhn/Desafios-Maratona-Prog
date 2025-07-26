#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, l, r;
  cin >> n >> l >> r;
  l--; r--;
  string s;
  cin >> s;
  for (ll i=l; i<=r; i++){
    if (s[i] != 'o'){
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";

  return 0;
}

