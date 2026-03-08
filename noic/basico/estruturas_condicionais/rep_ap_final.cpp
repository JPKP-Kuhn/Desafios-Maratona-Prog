#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  double n, m; cin >> n >> m;
  double media = (2*n + 3*m)/5;
  if (media >= 7.0) cout << "Aprovado\n";
  else if (media < 3.0) cout << "Reprovado\n";
  else cout << "Final\n";

  return 0;
}

