#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  while(cin >> n && n){
    ll c{};
    while(n>=3){
      ll d = floor(n/3); c+=d;
      n-=3*d;
      n+=d;
      if (n==2)n++;
    }
    cout << c << '\n';
  }

  return 0;
}

