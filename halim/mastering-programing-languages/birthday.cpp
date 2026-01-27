#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using iii = tuple<ll, ll, ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  vector<iii> b;
  while(n--){
    ll d, m, y; cin >> d >> m >> y;
    b.emplace_back(m, d, -y);
  }
  sort(b.begin(), b.end());
  for (auto &[m, d, y] : b){
    cout << d << ' ' << m << ' ' << -y << '\n';
  }

  return 0;
}

