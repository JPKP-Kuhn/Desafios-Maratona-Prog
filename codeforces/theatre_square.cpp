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

  ll n, m, a;
  cin >> n >> m >> a;

  ll flag = (n + a -1)/a;
  ll wlag = (m + a - 1)/a;

  ll total = flag * wlag;
  cout << total << endl;
  return 0;
}

