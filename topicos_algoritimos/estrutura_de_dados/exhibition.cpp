#include <bits/stdc++.h>
#include <iomanip>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;          // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll k{};
  cin >> k;
  for (ll test = 1; test<=k; test++){
    // cahve é o tipo de selo e value é o conjunto de selos
    map<ll, set<ll>> selos;

    ll friends{};
    cin >> friends;
    for (ll i = 0; i < friends; i++){
      ll m{};
      cin >> m;
      for (ll j=0; j<m; j++){
        ll x{};
        cin >> x;
        selos[x].insert(i);
      }
    }
    vll pes_selos_unicos(friends, 0);
    ll tot_selos_unicos{};
    for (auto& pair : selos){
      set<ll>& pessoas = pair.second;
      if (pessoas.size() == 1){
        ll pessoa = *pessoas.begin();
        tot_selos_unicos++;
        pes_selos_unicos[pessoa]++;
      }
    }

    cout << "Case " << test << ": ";
    for (ll i=0; i<friends; i++){
      double percent = (double)pes_selos_unicos[i]/tot_selos_unicos * 100;
      cout << fixed << setprecision(6)<< percent << '%';
      if (i < friends-1) cout << ' ';
    }
    cout << '\n';
  }

  return 0;
}

