#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  ll at{};
  ll g_seq{};
  ll l_seq{};

  while(n--){
    ll x; cin >> x;

    if (x == at){
      l_seq++;
    } else {
      g_seq=max(g_seq, l_seq);
      at=x;
      l_seq=1;
    }
  }
  g_seq=max(g_seq, l_seq);
  cout << g_seq << '\n';

  return 0;
}

