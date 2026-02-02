#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
using vll = vector<ll>;



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s; getline(cin, s);
  ll a, b, c;
  char op, g;
  stringstream ss(s);
  ss >> a >> op >> b >> g >> c;

  ll e{};
  if (op == '+') e = a+b;
  else if (op == '-') e = a-b;
  else if (op == '*') e = a*b;

  if (e == c) cout << "Yes\n";
  else cout << e << '\n';

  return 0;
}

