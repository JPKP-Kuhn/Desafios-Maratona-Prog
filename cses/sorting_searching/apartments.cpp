#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
 
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,m,k; cin >> n >> m >> k;
  vll ap(n), tm(m);
  for (ll &x : ap) cin >> x;
  for (ll &x : tm) cin >> x;
  sort(ap.begin(), ap.end());
  sort(tm.begin(), tm.end());

  ll c{}, i{}, j{};
  while (i < n && j < m){
    if (tm[j] < ap[i]-k)j++;
    else if (tm[j] > ap[i]+k)i++;
    else {
      c++; i++; j++;
    }

  }
  cout << c << '\n';

  return 0;
}
 
