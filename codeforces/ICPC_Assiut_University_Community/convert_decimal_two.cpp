#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll T; cin >> T;
  while(T--){
    ll x; cin >> x;
    bitset<32> b(x);
    ll ones = b.count();
    string num = string(ones, '1');
    cout << stoll(num, nullptr, 2) << '\n';
  }

  return 0;
}

