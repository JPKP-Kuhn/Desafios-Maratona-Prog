#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n{};
  cin >> n;
  ll count{};
  for (ll i=1; i<=n+1;i++){
    count+=i;
  }
  cout << count << '\n';
  return 0;
}
