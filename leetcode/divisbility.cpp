#include <bits/stdc++.h>
#include <string>
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
  string sumS = to_string(n);
  int sum{};
  int mult = 1;
  for (int i = 0; i < sumS.length(); i++){
    sum+=sumS[i]-'0';
    mult*=sumS[i]-'0';
  }
  cout << sum << '\n';
  cout << mult << '\n';


  int two = sum + mult;
  if (n % two == 0){
    cout << "Sim\n";
  } else {
    cout << "Não\n";
  }

  return 0;
}
