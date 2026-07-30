#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
#define fr first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using ll = long long;
using vll = vector<ll>;

int main() {
  _ vll v(3);
  cin >> v[0] >> v[1] >> v[2];
  sort(all(v));
  cout << v[1] << '\n';

  return 0;
}
