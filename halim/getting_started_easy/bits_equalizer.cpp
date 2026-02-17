#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll c; cin >> c;
  for (ll caso=1; caso<=c; caso++){
    string s, t; cin >> s >> t;
    ll inter{}, zerost{}, unst{}, zeross{}, unss{};
    for (char c : s){
      if (c=='?') inter++;
      else if (c=='1') unss++;
      else if (c=='0') zeross++;
    }
    for (char c : t) {
      if (c=='1') unst++;
      else if (c=='0') zerost++;
    }
    ll difz = zerost-zeross, difu = unst - unss;

    cout << "Case " << caso << ": ";
    if (difz + difu != inter) cout << -1 << '\n';
    else {
      cout << "certo\n";
    }
  }

  return 0;
}

