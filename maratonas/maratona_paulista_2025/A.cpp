#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll w, a, b, c;
  cin >> w >> a >> b >> c;

  if (a+b+c <= w) {
    cout << 'S' << '\n';
  } else {
    cout << 'N' << '\n';
  }

  return 0;
}

