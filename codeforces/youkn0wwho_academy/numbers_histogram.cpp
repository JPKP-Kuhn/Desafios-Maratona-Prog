#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  char s; cin >> s;
  ll n; cin >> n;
  while(n--){
    ll x; cin >> x;
    string p = string(x, s);
    cout << p << '\n';
  }

  return 0;
}

