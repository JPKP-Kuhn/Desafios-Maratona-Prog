#include <bits/stdc++.h>
#include <tuple>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vpll = vector<pair<ll, ll>>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  while(cin >> n && n > 0){
    vector<tuple<ll, ll, ll>> blocks;
    // width, depth, height

    for (ll i=0; i<n; i++){
      ll y, x, z;
      cin >> y >> x >> z;

      blocks.emplace_back(min(x, y), max(x, y), z);
      blocks.emplace_back(min(x, z), max(x, z), y);
      blocks.emplace_back(min(y, z), max(y, z), x);
    }
    sort(blocks.begin(), blocks.end(), [](const tuple<ll, ll, ll>&a, const tuple<ll, ll, ll> &b){
      return get<0>(a) * get<1>(a) > get<0>(b) * get<1>(b);
    });

    ll m = blocks.size();
    vll dp(m);
    // dp[i] maior altura da torre terminada no bloco i
    ll h{};
    for (ll i=0; i<m; i++){
      dp[i] = get<2>(blocks[i]);

      for (ll j=0; j<i; j++){
        if (get<0>(blocks[i]) < get<0>(blocks[j]) && get<1>(blocks[i]) < get<1>(blocks[j])){
          dp[i] = max(dp[i], dp[j] + get<2>(blocks[i]));
        }
      }
      h = max(h, dp[i]);
    }

    cout << h << '\n';
  }

  return 0;
}

