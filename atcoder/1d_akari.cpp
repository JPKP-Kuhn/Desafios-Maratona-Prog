#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  string t = s;

  for (ll i=0; i<s.length(); i++){
    if (s[i] == '#') continue;
    for (ll j=i; j<s.length(); j++){
      if (s[j] == '#') break;
      if (j == i){
        t[j] = 'o';
      } else {
        t[j] = '.';
      }
      i = j;
    }
  }
  cout << t << '\n';

  return 0;
}

