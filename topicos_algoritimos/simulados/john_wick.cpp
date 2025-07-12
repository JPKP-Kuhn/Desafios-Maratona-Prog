#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, time;
  cin >> n >> time;
  string corridor;
  cin >> corridor;
  ll limite = n-1;
  ll idx{};
  for (ll t=0; t<time; t++){
    if (idx+1 >= limite) break;

    if (corridor[idx+1] == '.'){
      swap(corridor[idx], corridor[idx+1]);
      idx++;
    } else if (corridor[idx+1] == 'o'){
      ll start = idx+1;
      ll end = start;
      while(end < limite && corridor[end] == 'o'){
        end++;
      }
      if (end < limite && corridor[end] == '.'){
        for (ll i=end-1; i>=idx; i--){
          swap(corridor[i], corridor[i+1]);
        }
        idx++;
      } else {
        break;
      }
    }
  }

  cout << corridor << '\n';

  return 0;
}

