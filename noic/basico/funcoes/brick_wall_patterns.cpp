#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


ll fib(ll l, vll &dp){
  if (dp[l] != -1) return dp[l];
  else dp[l] = fib(l-1, dp) + fib(l-2, dp);

  return dp[l];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll l;
  while(cin >> l && l){
    if (l==1 || l==2 || l==3) cout << l << '\n';
    else {
      vll dp(51, -1);
      dp[0]=0; dp[1]=1; dp[2]=2; dp[3]=3;
      cout << fib(l, dp) << '\n';
    }
  }

  return 0;
}

