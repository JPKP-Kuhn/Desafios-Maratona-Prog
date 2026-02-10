#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, even{}, odd{}, pos{}, neg{}; cin >> n;
  for (ll i{}; i<n; ++i){
    ll x; cin >> x;
    if (x>0) pos++;
    else if (x<0) neg++;

    if (x%2==0) even++;
    else odd++;
  }
  cout << "Even: " << even << '\n';
  cout << "Odd: " << odd << '\n';
  cout << "Positive: " << pos << '\n';
  cout << "Negative: " << neg << '\n';

  return 0;
}

