#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m; cin >> n >> m;
  cin.ignore();
  vector<string> songs(n);
  for (ll i=0; i<n; i++){
    getline(cin, songs[i]);
  }

  ll cursor=0;
  for (ll i=0; i<m; i++){
    ll skip{}; cin >> skip;
    cursor += skip % n;
    if (cursor > n-1) cursor = cursor % n;

    cout << songs[cursor] << '\n'; cursor++;
  }

  return 0;
}

