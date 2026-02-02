#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  double x, y; cin >> x >> y;
  if (!x && !y) cout << "Origem\n";
  else if (!x && y) cout << "Eixo Y\n";
  else if (!y && x) cout << "Eixo X\n";
  else if (x>0 && y>0) cout << "Q1\n";
  else if (x<0 && y>0) cout << "Q2\n";
  else if (x<0 && y<0) cout << "Q3\n";
  else if (x>0 && y<0) cout << "Q4\n";

  return 0;
}

