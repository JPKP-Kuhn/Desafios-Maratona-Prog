#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m;
  while(cin >> n >> m){
    if (n < m){
      cout << m-n << '\n';
    } else {
      cout << n-m << '\n';
    }
  }

  return 0;
}

