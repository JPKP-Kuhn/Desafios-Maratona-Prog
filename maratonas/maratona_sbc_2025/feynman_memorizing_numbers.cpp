#include <bits/stdc++.h>
#include <ios>
#include <map>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n{};
  cin >> n;
  vll numbers(n);
  for (ll i = 0; i < n; i++) {
    cin >> numbers[i];
  }

  vector<map<ll, ll>> dp(5);
  dp[0][0] = 1;

  for (ll x : numbers) {
      for (ll k = 3; k >= 0; k--) {
        for (auto &[soma, qtd] : dp[k]) {
          dp[k + 1][soma + x] += qtd;
        }
      }
    }

  ll queries{};
  while (queries--) {
    ll qi{};
    cin >> qi;

    cout << dp[4][qi] << '\n';
  }

  return 0;
}

