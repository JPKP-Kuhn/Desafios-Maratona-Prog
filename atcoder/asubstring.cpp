#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  s.erase(s.begin(), s.begin()+a);
  s.erase(s.end() - b, s.end());
  cout << s << '\n';
  return 0;
}

