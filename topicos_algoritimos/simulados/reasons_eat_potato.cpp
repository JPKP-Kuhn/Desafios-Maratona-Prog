#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll a, b, c;
  cin >> a >> b >> c;

  if ((a ^ b ^ c) == 0){
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }

  return 0;
}

