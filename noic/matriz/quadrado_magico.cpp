#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

bool magico(vector<vll> &mat){
  ll sl0{};
  for (ll i{}; i<3; i++){
    sl0+=mat[i][0];
  }

  ll sl1{};
  for (ll i{}; i<3; i++){
    sl1+=mat[i][1];
  }
  if (sl0 != sl1) return false;

  ll sl2{};
  for (ll i{}; i<3; i++){
    sl2+=mat[i][2];
  }
  if (sl0 != sl2) return false;

  ll cl0{}, cl1{}, cl2{};
  for (ll j{}; j<3; j++){
    cl0+=mat[0][j];
  }
  if (sl0 != cl0) return false;

  for (ll j{}; j<3; j++){
    cl1+=mat[1][j];
  }
  if (sl0 != cl1) return false;

  for (ll j{}; j<3; j++){
    cl2+=mat[2][j];
  }
  if (sl0 != cl2) return false;

  ll dg1{}, dg2{};
  for (ll i{}; i<3; i++){
    dg1+=mat[i][i];
  }
  if (sl0 != dg1) return false;

  for (ll i=0; i<3; i++){
    dg2+=mat[i][3-i-1];
  }
  if (sl0 != dg2) return false;

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<vll> mat(3, vll(3));
  for (ll i{}; i<3; i++){
    for (ll j{}; j<3; j++){
      cin >> mat[i][j];
    }
  }

  if (magico(mat)) cout << "SIM\n";
  else cout << "NAO\n";

  return 0;
}

