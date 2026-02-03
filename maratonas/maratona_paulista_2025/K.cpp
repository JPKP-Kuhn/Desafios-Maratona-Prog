#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;          // PD e inicialização de valor mínimo
const ll MOD = 998244353;

ll n,k;
vector<vll> dp;

ll knapsack(ll ind, ll s) {
  if (s < 0 || (ind == 0 && s)) return 0;
  if (s == 0) return 1;
  if (dp[ind][s] != -1) return dp[ind][s];

  ll sumAux{};
  if (ind != k) {
    sumAux += knapsack( ind, s-ind);
  }
  sumAux %= MOD;
  sumAux += knapsack(ind-1,  s);
  sumAux %= MOD;

  return dp[ind][s] = sumAux;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  dp.assign(n+1, vll(n+1, -1));

  cout << knapsack(n, n)%MOD << '\n';

  return 0;
}

