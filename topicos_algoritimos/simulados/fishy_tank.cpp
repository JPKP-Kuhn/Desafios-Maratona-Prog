#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

char tank[15][25];
string fish = "><>";
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;

  for (ll i=0; i<15; i++){
    for (ll j=0; j<25; j++){
      if (i == 0 && j == 0 || i == 0 && j == 24 || i == 14 && j == 0 || i == 14 && j == 24){
        tank[i][j] = 'o';
      } else if (j > 0 && j < 24 && (i == 0 || i == 14)){
        tank[i][j] = '-';
      } else if (i > 0 && i < 14 && (j == 0 || j == 24)){
        tank[i][j] = '|';
      } else {
        tank[i][j] = ' ';
      }
    }
  }

  ll peixes{};
  ll idx = 1;
  while(true){
    for (ll j=1; (j+2)<24; j+=3){
      tank[idx][j] = '>';
      tank[idx][j+1] = '<';
      tank[idx][j+2] = '>';
      peixes++;
      if (peixes == n){
        goto saida;
      } else if (peixes == 7){
        idx++;
      }
    }
  }

  saida:
    for (ll i=0; i<15; i++){
      for (ll j=0; j<25; j++){
        cout << tank[i][j];
      }
      cout << '\n';
    }

  return 0;
}

