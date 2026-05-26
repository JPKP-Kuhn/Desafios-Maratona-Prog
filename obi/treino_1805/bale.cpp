#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;

vll v;
ll n;
ll c;

void merge_sort(ll ini, ll fim) {
  if (ini == fim)
    return;

  ll mid = (ini + fim) >> 1;

  merge_sort(ini, mid);
  merge_sort(mid + 1, fim);

  vll temp;
  ll i = ini;
  ll j = mid + 1;

  while (i <= mid && j <= fim) {
    if (v[i] < v[j]) {
      temp.push_back(v[i++]);
    } else {
      c += (mid - i + 1);
      temp.push_back(v[j++]);
    }
  }

  while (i <= mid) {
    temp.push_back(v[i]);
    i++;
  }

  while (j <= fim) {
    temp.push_back(v[j]);
    j++;
  }

  for (ll k = ini; k <= fim; k++) {
    v[k] = temp[k - ini];
  }
}

int main() {
  _ cin >> n;
  v.resize(n);
  c = 0;
  for (ll &x : v)
    cin >> x;

  merge_sort(0, n - 1);
  cout << c << '\n';

  return 0;
}
