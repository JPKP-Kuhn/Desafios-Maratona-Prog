#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  vll number(n);
  for (ll &x : number) cin >> x;

  ll x;
  cin >> x;
  if (count(number.begin(), number.end(), x)){
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}

