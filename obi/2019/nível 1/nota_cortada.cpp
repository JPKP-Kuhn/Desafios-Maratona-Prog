#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;          // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int comp = 160;
  int alt = 70;
  int area = comp*alt;

  int b, t;
  cin >> b >> t;

  double trapezio = (double)((comp-b + comp-t)*alt)/2;

  double metade = (double) area/2;
  if (trapezio == metade){
    cout << 0 << '\n';
  } else if (trapezio > metade) {
    cout << 2 << '\n';
  } else {
    cout << 1 << '\n';
  }


  return 0;
}

