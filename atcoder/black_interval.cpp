#include <bits/stdc++.h>
#include <bitset>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 * 5 + 5;// Range seguro para vetores e arrays
const ll INF = 1e18+5;          // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n{}, q{};
  cin >> n >> q;
  bitset<MAXN>squares;
  vll queries(q);
  for (ll i=0; i<q; i++){
    cin >> queries[i];
  }

  ll intervalos{};
  // 0 representa branco e 1 representa preto
  for (ll i : queries){
    squares.flip(i);

    // Retorna quantos intervalos tem cada valor
    if (squares.test(i)){
      if (squares.test(i+1) && squares.test(i-1)){
        intervalos--;
      } else if (!squares.test(i+1) && !squares.test(i-1)){
        intervalos++;
      }
    } else {
      if (squares.test(i+1) && squares.test(i-1)){
        intervalos++;
      } else if (!squares.test(i+1) && !squares.test(i-1)){
        intervalos--;
      }
    }
  cout << intervalos << '\n';
}

  return 0;
}

