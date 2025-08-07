#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s, w; cin >> s >> w;
  string ans{};

  map<char, ll> fs, fw;

  for (char c : s) fs[c]++;
  for (char c : w) fw[c]++;

  for (char c = 'a'; c <= 'z'; c++){
    ll freq = max(fs[c], fw[c]);
    ans += string(freq, c);
  }


  cout << ans << '\n';

  return 0;
}

