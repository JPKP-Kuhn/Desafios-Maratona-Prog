#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  while(t--){
    string s; cin >> s;
    if (s.find("010") != string::npos || s.find("101") != string::npos){
      cout << "Good\n";
    } else {
      cout << "Bad\n";
    }
  }

  return 0;
}

