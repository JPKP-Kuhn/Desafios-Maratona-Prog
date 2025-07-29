#include <bits/stdc++.h>
#include <set>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, score{}; 
  cin >> n;
  vll deck(n);
  for (ll &x : deck) cin >> x;
  multiset<ll> discarded;

  for (ll i : deck){
    for (auto it = discarded.upper_bound(i); it != discarded.end(); ++it){
      score += *it + i;
    }
    discarded.insert(i);
  }
  cout << score << '\n';
  return 0;
}

