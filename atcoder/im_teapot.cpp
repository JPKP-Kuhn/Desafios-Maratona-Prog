#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  string s; cin >> s;
  if (s[n-1] == 'a' && s[n-2] == 'e' && s[n-3] == 't'){
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}

