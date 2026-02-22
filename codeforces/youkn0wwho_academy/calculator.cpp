#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll soma(string s, ll i){
  ll a = stoi(s.substr(0,i));
  ll b = stoi(s.substr(i+1));

  return a+b;
}

ll sub(string s, ll i){
  ll a = stoi(s.substr(0, i));
  ll b = stoi(s.substr(i+1));
  return a-b;
}

ll mult(string s, ll i){
  ll a = stoi(s.substr(0, i));
  ll b = stoi(s.substr(i+1));
  return a*b;
}

ll divi(string s, ll i){
  ll a = stoi(s.substr(0, i));
  ll b = stoi(s.substr(i+1));
  return a/b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s; cin >> s;
  for (ll i=0; i<(ll)s.size(); i++){
    if (s[i] == '+') {
      cout << soma(s, i) << '\n';
      break;
    } else if (s[i] == '-'){
      cout << sub(s, i) << '\n';
      break;
    } else if (s[i] == '*') {
      cout << mult(s, i) << '\n';
      break;
    } else if (s[i] == '/') {
      cout << divi(s, i) << '\n';
      break;
    }
  }

  return 0;
}

