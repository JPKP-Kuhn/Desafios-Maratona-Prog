#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll maxn = pow(10, 5) + 10;

ll n;
int main() {
  scanf("%lld", &n);

  char s[n];
  char t[n];

  ll tot_aster = 0;
  for (ll i = 0; i < n; i++) {
    scanf(" %c", &s[i]);
    if (s[i] == '*') tot_aster++;
  }

  ll res_aster = 0;
  for (ll i = 0; i < n; i++) {
    scanf(" %c", &t[i]);
    if (t[i] == '*') res_aster++;
  }

  double taxa = (double) (tot_aster - res_aster)/tot_aster;

  printf("%.2f\n", taxa);

  return 0;
}

