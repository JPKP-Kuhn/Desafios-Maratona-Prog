#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;
// kattis problem wordcloud
// WIDTH ceil(9/16 * t * P) t characters and P  font size
// for each word w, compute:
// FONT P = 8 + ceil((40*(cw-4)) / (cmax-4)), cw occurencies of w and cwmax is the most frequent w
ll P_font(double cw, double cmax){
  return 8 + ceil((40* (cw-4)) / (cmax-4));
}

ll total_width(ll t, ll P){
  return ceil((9.0/16.0) * t * P);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll TNo{};
  while (1){
    ll W, N; cin >> W >> N;
    if (!W && !N) break;

    vector<pair<string, ll>> word_count(N);

    ll cmax{};
    for (ll i{}; i<N; i++){
      string s; ll c; cin >> s >> c;
      word_count[i]={s, c}; cmax=max(cmax, c);
    }
    ll mP{};
    ll ans{};
    ll rw{};
    bool f=true;
    // estrutura para encontra maior height na linha
    for (const auto& [k,v] : word_count){
      // cout << k << ' ' << v << '\n';
      ll P = P_font(v, cmax);
      ll width =  total_width(k.size(), P);
      // cout << "P: " << P << " mP: " << mP << " width: " << width << '\n';
      // cout << "rw: " << rw << '\n';
      if (rw+(f ? 0 : 10)+width <= W) {
        if (f) rw+=width;
        else rw+=width+10;
        f=false;
        mP = max(mP, P);
      }
      else { // fecha linha
        // cout << "fecha linha\n";
        // cout << "soma:" << mP << '\n';
        ans+=mP; mP=P; rw=width;
      }
    }
    ans+=mP;

    // The height of a given row is equal to the maximum font size of any word rendered in that row.
    cout << "CLOUD " << ++TNo << ": " << ans << '\n';
  }

  return 0;
}

