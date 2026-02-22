#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s; cin >> s;
  map<char, ll>co;
  for (char c : s) co[c]++;
  for (auto &[k, v] : co){
    cout << k << " : " << v << '\n';
  }

  return 0;
}

