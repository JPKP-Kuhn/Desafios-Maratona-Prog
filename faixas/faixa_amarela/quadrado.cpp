#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using vpll = vector<pair<ll, ll>>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  vector<vll> mat(n, vll(n));
  for (ll i=0; i<n;i++){
    for (ll j=0; j<n; j++){
      cin >> mat[i][j];
    }
  }
  pair<ll, ll> cordErr{};
  ll somaErr{}, somaCorr{};
  map<ll, vll>somas{};
  for (ll i=0; i<n; i++){
    ll lSoma{};
    for (ll j=0; j<n; j++){
      lSoma += mat[i][j];
    }
    somas[lSoma].push_back(i);
  }

  for (auto &[soma, linha] : somas){
    if (linha.size() == 1){
      somaErr = soma;
      cordErr.first = linha[0];
    } else {
      somaCorr = soma;
    }
  }

  for (ll j=0; j<n; j++){
    ll cSoma{};
    for (ll i=0; i<n; i++){
      cSoma += mat[i][j];
    }
    if (cSoma == somaErr){
      cordErr.second = j;
      break;
    }
  }

  ll x = cordErr.first; ll y = cordErr.second;
  ll errado = mat[x][y];
  if (somaErr > somaCorr){
    mat[x][y] = errado - (somaErr - somaCorr);
  } else {
    mat[x][y] = errado + (somaCorr - somaErr);
  }

  cout << mat[x][y] << ' ' << errado << '\n';
  return 0;
}

