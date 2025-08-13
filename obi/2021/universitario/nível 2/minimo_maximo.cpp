#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

bool check(ll s, ll n){
  ll soma{};
  while (n>0){
    soma += n%10;
    n/=10;
  }
  return (soma == s);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll s, a, b; cin >> s >> a >> b;
  ll maior{a}; ll menor{b};
  ll la = a; ll lb = b;
  while (a <= lb && b >= la){
    if (check(s,a)){
      menor = min(menor, a);
    }
    if (check(s, b)){
      maior = max(maior, b);
    }
    a++; b--;
  }

  cout << menor << '\n';
  cout << maior << '\n';
  return 0;
}

