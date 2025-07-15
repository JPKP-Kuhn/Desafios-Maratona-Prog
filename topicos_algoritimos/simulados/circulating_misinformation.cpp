#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  cin.ignore();
  set<string> names;
  for (ll i=0; i<n; i++){
    string name;
    getline(cin, name);
    names.insert(name);
  }
  ll k{};
  for (ll i=0; i<n; i++){
    string name;
    getline(cin, name);
    if (names.find(name) == names.end()){
      k++;
    } else {
      names.erase(name);
    }
  }
  cout << k << '\n';
  for (string c : names){
    cout << c << '\n';
  }

  return 0;
}

