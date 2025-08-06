#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
using vll = vector<ll>;

string trim(string s){
  s.erase(s.find_last_not_of(" \r\n") + 1);
  return s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  cin.ignore();
  unordered_map<string, string> dicionario;
  for (ll i=0; i<n; i++){
    string l, w;
    getline(cin, l);
    getline(cin, w);

    dicionario[trim(l)] = w;
  }

  ll m; cin >> m;
  cin.ignore();
  for (ll i=0; i<m; i++){
    string nome, l;
    getline(cin, nome);
    getline(cin, l);
    cout << nome << '\n';
    cout << dicionario[trim(l)] << '\n';

    cout << '\n';
  }

  return 0;
}

