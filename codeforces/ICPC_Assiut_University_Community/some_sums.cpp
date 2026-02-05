#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll n, a, b;
bool check(ll x){
  ll sum{};
  while(x>0){
    sum+=x%10;
    x/=10;
  }
  if (sum >= a && sum <= b) return true;
  else return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> a >> b;
  ll sum{};
  for (ll i=1; i<=n; i++){
    if (check(i)) sum+=i;
  }
  cout << sum << '\n';


  return 0;
}

