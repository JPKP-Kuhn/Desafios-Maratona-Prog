#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t{};
  cin >> t;
  while (t--) {
    ll nFamily, rows;
    cin >> nFamily >> rows;

    ll seats = 2*rows;
    ll totPeople{};
    ll happy{};

    vll nPFamily(nFamily);
    for (ll i=0;i<nFamily;i++) {
      cin >> nPFamily[i];
      totPeople += nPFamily[i];
    }
    ll qtdTotal = totPeople;

    // Agora alocar cada pessoa nos assentos para ficarem felizes
    while(seats >= 2) {
      bool maisDeDois = false;
      for (ll i=0;i<nFamily;i++) {
        if (nPFamily[i]>1) {
          nPFamily[i]-=2;
          happy+=2;
          seats-=2; rows--;
          totPeople-=2;
          maisDeDois = true;
        }
      }
      if (!maisDeDois) break;
    }
    // Coube todos no ònibus
    // entrada: 3 3 e 2 2 2, assim todos já ocuparam; se for 4 5 e 1 1 2 2, são 10 assentos e sobrar 2 pessoas ainda, sendo 4 já ocupados, tem sobra
    if (totPeople <= seats/2) {
      cout << qtdTotal << '\n';
    } else { 
      happy += seats - totPeople;
      cout << happy << '\n';
    }
  }

  return 0;
}

