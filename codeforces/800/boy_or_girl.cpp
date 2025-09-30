#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  set<char> d;
  string s; cin >> s;
  for (char c : s) d.insert(c);

  if (d.size() % 2 == 0) cout << "CHAT WITH HER!\n";
  else cout << "IGNORE HIM!\n";

  return 0;
}

