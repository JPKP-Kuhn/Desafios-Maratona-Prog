#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long;

// 2³¹ - 1
const unsigned long MOD = (1ULL<<31)-1;    // Valor comum para aritmética modular, números muito grandes

ll pr(ll base, ll exp){
  ll p{1};
  while(exp>0){
    if (exp & 1) // Se o bit atual é 1
      p = (p * base) % MOD;
    base = (base*base)%MOD;
    exp>>=1;
  }
  return p;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  cout << pr(3ULL, n) % MOD << '\n';

  return 0;
}

