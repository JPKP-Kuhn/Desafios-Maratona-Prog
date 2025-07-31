#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

string mai(string &s){
  string saida{};
  bool f = false;
  for (ll i=0; i<s.length(); i++){
    if (f){
      saida += s[i];
    } else{
      if (s[i] >= 'A' && s[i] <= 'Z'){
        f = true;
        saida += s[i];
      }
    }
  }

  return saida;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  cin.ignore();
  map<string, string> ord;
  for (ll i=0; i<n; i++){
    string name;
    getline(cin, name);
    ord[mai(name)] = name;
  }

  for (auto &[sob, nome] : ord){
    cout << nome << '\n';
  }

  return 0;
}

