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
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = long long;
using vll = vector<ll>;

int main() {
  _ ll a, b, c;
  cin >> a >> b >> c;
  unordered_map<ll, ll> q;
  q[a]++;
  q[b]++;
  q[c]++;
  if (q[a] == 1) {
    cout << a;
  } else if (q[b] == 1)
    cout << b;
  else
    cout << c;

  cout << '\n';

  return 0;
}
