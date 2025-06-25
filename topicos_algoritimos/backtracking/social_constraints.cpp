#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iterator>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

ll n, m;
ll a, b, c;
ll possivel{};

bool verificaRestricao(vll& group, vector<tuple<ll, ll, ll>> restricoes){
  for (auto & [a, b, c] : restricoes){
    auto it_a = find(group.begin(), group.end(), a);
    auto it_b = find(group.begin(), group.end(), b);
    ll dist_ab = abs(distance(it_a, it_b));
    if (c > 0){
      if (dist_ab > c){
        return false;
      }
    } else {
      if (dist_ab < abs(c)){
        return false;
      }
    }
  }
  return true;
}

void backtrack(vll& group, vector<tuple<ll, ll, ll>> restricoes){
  do{
    if (verificaRestricao(group, restricoes)){
      possivel++;
    }
  } while (next_permutation(group.begin(), group.end()));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n >> m){
    if (n == 0 && m == 0) break;
    vll group(n);
    possivel = 0;
    vector<tuple<ll, ll, ll>> restricoes;
    for (ll i=0; i<n; i++){
      group[i] = i;
    }
    for (ll i=0; i<m; i++){
      cin >> a >> b >> c;
      restricoes.push_back({a, b, c});
    }
    backtrack(group, restricoes);
    cout << possivel << '\n';
  }
  return 0;
}

