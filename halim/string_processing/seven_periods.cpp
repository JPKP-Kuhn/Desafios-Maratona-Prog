#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s, r{};
  getline(cin, s);
  if (s.find(".......") == string::npos){
    r+=s;
    while(getline(cin, s) && s.find(".......") == string::npos){
      r+=' ';
      r+=s;
    }
    cout << r << '\n';
  }

  return 0;
}

