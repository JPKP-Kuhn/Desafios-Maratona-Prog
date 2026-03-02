#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  while(t--){
    ll n, m, d; cin >> n >> m >> d;
    ll c{}, alt{};
    ll sp{};
    bool f=false;
    while (n--){
      if (!f){
        f = true;
        c++;
        sp = 0;
        alt = 0;
      } else {
        if (sp+m > d) {
          f = false; n++;
        }
        else {
          sp+=m; alt++;
        }
      }
    }
    cout << c << '\n';
  }

  return 0;
}

