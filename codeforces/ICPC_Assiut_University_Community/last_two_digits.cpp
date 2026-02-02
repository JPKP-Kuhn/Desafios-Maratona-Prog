#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll a, b, c, d; cin >> a >> b >> c >> d;
  ll p = ((a%100) * (b%100) * (c%100) * (d%100))%100;
  string s = to_string(p);
  if ((int)s.size() < 2) cout << '0' << s << '\n';
  else cout << p << '\n';
 
  return 0;
}
