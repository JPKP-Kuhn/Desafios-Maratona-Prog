#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N, c{}; cin >> N;
  string s; cin >> s;
  char a = s[0];
  for (ll i=1; i<s.size(); i++){
    if (s[i] == a) c++;
    else a = s[i];
  }

  cout << c << '\n';

  return 0;
}

