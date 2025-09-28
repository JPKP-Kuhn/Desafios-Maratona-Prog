#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  ll x{};

  for (ll i=0; i<n; i++){
    string s{}; cin >> s;
    for (char c : s){
      if (c == '+'){
        x++; break;
      } else if (c == '-'){
        x--; break;
      }
    }
  }
  cout << x << '\n';

  return 0;
}

