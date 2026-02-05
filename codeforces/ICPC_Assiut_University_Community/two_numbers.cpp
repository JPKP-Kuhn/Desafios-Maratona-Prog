#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  double a, b; cin >> a >> b;
  double s = a/b;
  cout << "floor " << a << " / " << b << " = " << (int)s << '\n';
  cout << "ceil " << a << " / " << b << " = " << ceil(s) << '\n';
  cout << "round " << a << " / " << b << " = " << round(s) << '\n';

  return 0;
}

