#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll c; cin >> c;
  char o; cin >> o;
  vector<vector<double>> mat(12, vector<double>(12));
  for (ll i{}; i<12; i++){
    for (ll j{}; j<12; j++){
      cin >> mat[i][j];
    }
  }

  if (o == 'S'){
    double sum{};
    for (ll i{}; i<12; i++){
      sum += mat[i][c];
    }
    cout << fixed << setprecision(1) << sum << '\n';
  } else {
    double sum{};
    for (ll i{}; i<12; i++){
      sum+=mat[i][c];
    }
    double media = sum/12.0;
    cout << fixed << setprecision(1) << media << '\n';
  }

  return 0;
}

