#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while(t--){
    string d;
    cin >> d;
    ll menor{INF};
    for (char c : d){
      ll n = c - '0';
      if (n < menor){
        menor = n;
      }
    }
    cout << menor << '\n';
  }

  return 0;
}

