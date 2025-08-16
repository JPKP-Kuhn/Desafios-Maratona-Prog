#include <bits/stdc++.h>
#include <set>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  multiset<ll>bag;
  ll q; cin >> q;
  while(q--){
    ll x; cin >> x;
    switch (x) {
      case 1:
        ll y; cin >> y;
        bag.insert(y);
        break;
      case 2:
        cout << *bag.begin() << '\n';
        bag.erase(bag.begin());
        break;
    }
  }

  return 0;
}

