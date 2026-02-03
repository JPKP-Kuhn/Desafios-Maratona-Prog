#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  while(t--){
    ll n, m; cin >> n >> m;
    if (n == m){
      cout << "=\n";
    } else if(n < m){
      cout << "<\n";
    } else if (n > m){
      cout << ">\n";
    }
  }

  return 0;
}

