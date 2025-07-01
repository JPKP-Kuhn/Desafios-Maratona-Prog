#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n{};
  cin >> n;
  vector<pair<ll, ll>> tarefas(n);
  ll c{};
  for (ll i=0; i<n; i++){
    ll a, b;
    cin >> a >> b;
    tarefas[i].first = a;
    tarefas[i].second = b;
    if (b > a) c++;
  }
  cout << c << '\n';

  return 0;
}

