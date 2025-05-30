#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll maxn = pow(10, 5) + 10;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int c, g;
  cin >> c >> g;
  if (c == 1) {
    cout << "vivo e morto" << '\n';
  } else if (g == 1) {
    cout << "vivo" << '\n';
  } else if (g == 0) {
    cout << "morto" << '\n';
  }
  return 0;
}

