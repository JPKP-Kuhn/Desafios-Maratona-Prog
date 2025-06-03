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

  ll n{};
  cin >> n;
  for (ll k=1;k<=n;k++) {
    ll fKnight = pow(k,2);
    ll sKnight = pow(k,2)-1;
    // Total de posições para duas peças ocuparem no tabuleiro
    ll totPossibles = (fKnight * sKnight)/2;

    ll qtd_2x3_areaInsideToTchessboard = (k-1)*(k-2);
    ll knightAttack = 4 * qtd_2x3_areaInsideToTchessboard;

    cout << totPossibles-knightAttack << '\n';
  }

  return 0;
}

