#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll a, b, c, d; cin >> a >> b >> c >> d;
  cout << (b*log(a) > d*log(c) ? "YES\n" : "NO\n");

  return 0;
}

