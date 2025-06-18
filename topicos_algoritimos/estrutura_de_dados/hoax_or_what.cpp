#include <bits/stdc++.h>
#include <ios>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;          // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll cases{};
  while (cin >> cases && cases != 0){
    multiset<ll> urn;
    ll cost{};

    for (ll day=0; day<cases; day++){
      ll bills{};
      cin >> bills;
      for (ll i=0; i<bills; i++){
        ll x;
        cin >> x;
        urn.insert(x);
      }
      if (urn.size() >= 2) {
        ll menor = *urn.begin();
        ll maior = *urn.rbegin();
        cost += maior-menor;

        urn.erase(urn.begin());
        urn.erase(prev(urn.end()));
      }
    }
    cout << cost << '\n';
  }

  return 0;
}

