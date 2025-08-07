#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll dp[30];

ll hanoi(ll n){
  ll v{};
  if (n==0) return dp[0];
  if (n<=-1) return 0;
  if (n==1) return dp[1];
  if (dp[n] != -1) return dp[n];
  dp[n] = hanoi(n-1) + hanoi(n-1)+1;
  return dp[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  ll teste{1};
  for (ll i=0; i<30; i++){
    dp[i] = -1;
  }
  dp[0] = 1;
  dp[1] = 3;
  while(cin >> n && n != 0){
    cout << "Teste " << teste << '\n';
    cout << hanoi(n-1) << '\n';
    cout << '\n';
    teste++;

  }

  return 0;
}

