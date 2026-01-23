#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s; cin >> s;
  ll l{}, u{};
  for (char c : s){
    if (c >= 65 && c <=90){
      u++;
    } else l++;
  }
  if (l >= u){
    transform(s.begin(), s.end(), s.begin(), ::tolower);
  } else {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
  }
  cout << s << '\n';

  return 0;
}

