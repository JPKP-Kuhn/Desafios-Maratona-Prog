#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  vector<pair<ll, ll>> trens(n);
  vector<pair<ll, ll>> dinamites;
  for (auto &x : trens) cin >> x.first >> x.second;
  ll t{};
  while (!trens.empty()){
    t++;
    map<ll, ll> posicoes{};
    for (auto &p : trens){
      p.first+=p.second;
      posicoes[p.first]++;
    }
    bool dois = false;
    ll posd{};
    for (auto &[pos, freq] : posicoes){
      if (freq >= 2){
        dois = true;
        posd = pos;
        break;
      }
    }
    if (dois){
      dinamites.emplace_back(posd, t);
      trens.erase(remove_if(trens.begin(), trens.end(),
                            [posd](const pair<ll, ll> &p){
                            return p.first == posd;
                            }),
                  trens.end());
    } else {
      auto trem = trens.front();
      trens.erase(trens.begin());
      dinamites.emplace_back(trem.first, t);
    }
  }

  cout << dinamites.size() << '\n';
  for (auto p : dinamites){
    cout << p.first << ' ' << p.second << '\n';
  }

  return 0;
}

