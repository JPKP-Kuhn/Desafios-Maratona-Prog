#include <bits/stdc++.h>
#include <cctype>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s; cin >> s;
  vector<char>num;
  for (char c : s){
    if (isdigit(c)){
      num.push_back(c);
    }
  }
  sort(num.begin(), num.end());
  for (ll i=0; i<num.size(); i++){
    if (i != num.size()-1) cout << num[i] << '+';
    else cout << num[i];
  }
  cout << '\n';

return 0;
}

