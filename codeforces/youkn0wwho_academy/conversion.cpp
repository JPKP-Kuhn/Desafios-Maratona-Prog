#include <bits/stdc++.h>
#include <cctype>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string n; cin >> n;
  for (ll i{}; i<n.size(); i++){
    if (n[i]==',')n[i]=' ';
    if (n[i] >= 'A' && n[i] <= 'Z') n[i]=tolower(n[i]);
    else if (n[i] >= 'a' && n[i] <= 'z') n[i]=toupper(n[i]);
  }
  cout << n << '\n';

  return 0;
}

