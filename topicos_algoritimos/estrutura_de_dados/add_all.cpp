#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;


ll n;
int main() {
  while (cin >> n && n != 0) {
    priority_queue<ll, vector<ll>, greater<ll>> somas;
    ll x;
    for (ll i = 0; i<n;i++) {
      cin >> x;
      somas.push(x);
    }

    ll tot_cost = 0;
    while (somas.size() > 1) {
      ll a = somas.top(); somas.pop();
      ll b = somas.top(); somas.pop();
      ll cost = a + b;
      tot_cost += cost;
      somas.push(cost);
    }
    cout << tot_cost << endl;
  }
  return 0;
}

