#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string t, s; getline(cin, t); getline(cin, s);
  bool f=false;
  ll pos = t.find(s);
  while(t.find(s, pos) != string::npos){
    cout << t.find(s, pos) << '\n';
    pos = t.find(s, pos); pos++;
    f=true;
  }
  if (!f) cout << -1 << '\n';

  return 0;
}

