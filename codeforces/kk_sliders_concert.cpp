#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, k, c{};
  cin >> n >> k;
  vll left(n), right(n);
  for (ll &x : right) cin >> x;
  for (ll &y : left) cin >> y;
  sort(right.begin(), right.end());
  sort(left.begin(), left.end());

  ll i{}, j{};
  while (i < n && j < n){
    ll custo = left[i] + right[j];
    if (custo <= k){
      k -= custo;
      c++; i++; j++;
    } else {
      if (left[i] > right[j]) j++;
      else i++;
    }
  }
  cout << c << '\n';

  return 0;
}

