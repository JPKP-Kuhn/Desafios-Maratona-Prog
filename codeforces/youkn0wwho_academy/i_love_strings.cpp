#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  while(n--){
    string s,t; cin >> s >> t;
    ll sl=s.size(), tl = t.size();
    if (sl < tl){
      for (ll i{}; i<sl; i++){
        cout << s[i] << t[i];
      }
      for (ll i=sl; i<tl; i++) cout << t[i];

      cout << '\n';
    } else {
      for (ll i{}; i<tl; i++){
        cout << s[i] << t[i];
      }
      for (ll i=tl; i<sl; i++) cout << s[i];

      cout << '\n';
    }
  }

  return 0;
}

