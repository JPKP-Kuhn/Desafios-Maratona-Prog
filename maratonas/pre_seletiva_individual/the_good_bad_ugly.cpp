#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = unsigned long long;
using vll = vector<ll>;

int main() {
  _ string s;
  cin >> s;
  ll n;
  cin >> n;
  // a * 256³ + b * 256² + c * 256¹ + d
  ll d = n % 256;
  n /= 256;
  ll c = n % 256;
  n /= 256;
  ll b = n % 256;
  n /= 256;
  ll a = n % 256;
  n /= 256;

  ll ans{};

  ans = ans * 256 + d;
  ans = ans * 256 + c;
  ans = ans * 256 + b;
  ans = ans * 256 + a;
  cout << ans << '\n';

  return 0;
}
