#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll a, b, c, d; cin >> a >> b >> c >> d;
  ll p = a*b*c*d;
  string s = to_string(p);
  cout << s[s.size()-2] << s[s.size()-1] << '\n';

  return 0;
}

