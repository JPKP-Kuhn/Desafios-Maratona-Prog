#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s; cin >> s;
  ll cl{}, cr{};
  vector<string> b;
  string sb{};
  for (char c : s){
    sb+=c;
    if (c=='L') cl++;
    else cr++;

    if (cl == cr){
      b.push_back(sb);
      cl=0; cr=0;
      sb.clear();
    }
  }

  cout << b.size() << '\n';
  for (string a : b){
    cout << a << '\n';
  }

  return 0;
}

