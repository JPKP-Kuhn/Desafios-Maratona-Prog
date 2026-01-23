#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s; cin >> s;
  vector<char> v = {'a', 'e', 'i', 'o', 'u', 'y'};
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  string sv{};
  for (char c : s){
    if (find(v.begin(), v.end(), c) != v.end()) continue;
    sv.push_back('.');
    sv.push_back(c);
  }
  cout << sv << '\n';

  return 0;
}

