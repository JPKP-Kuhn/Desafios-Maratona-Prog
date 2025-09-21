#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll a, b, c; cin >> a >> b >> c;
  if (a == b || a == c || b == c){
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}

