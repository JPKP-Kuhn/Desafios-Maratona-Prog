#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


string s;
bool palindrome(){
  for (ll i{}; i<s.size()/2; i++){
    if(s[i] != s[s.size() - i - 1]) return false;
  }

  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s;
  if (palindrome()) cout << "YES\n";
  else cout << "NO\n";

  return 0;
}

