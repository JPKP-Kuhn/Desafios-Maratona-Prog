#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
  pl f = make_pair(l1, r1), s = make_pair(l2, r2);
  pl maior = max(f, s);
  pl menor = min(f, s);
  if (maior.first > menor.second){
    cout << -1 << '\n';
  } else if (maior.first > menor.first && maior.second < menor.second) {
    cout << maior.first << ' ' << maior.second << '\n';
  } else {
    cout << maior.first << ' ' << menor.second  << '\n';
  }

  return 0;
}

