#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin >> t;
  while(t--){
    ll a, b, x, y, custo{};
    cin >> a >> b >> x >> y;

    if (b < a && (a^1) == b){
      cout << y << '\n';
      continue;
    } else if (b < a && a%2==0){
      cout << -1 << '\n';
      continue;
    } else if (a == b){
      cout << 0 << '\n';
    } 
    else {
      while (a < b){
        if (x<=y){
          a++;
          custo+=x;
        }
        else{
          if (a%2==0){
            a = (a^1);
            custo+=y;
          } else {
            a++;
            custo+=x;
          }
          if (a > b){
            custo = 0; break;
          }
        }
      }
      cout << (custo == 0 ? -1 : custo) << '\n';
    }
  }

  return 0;
}

