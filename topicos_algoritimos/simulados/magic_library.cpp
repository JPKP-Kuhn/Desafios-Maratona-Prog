#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  string s;
  cin >> n >> s;
  string ord = s;
  sort(s.begin(), s.end());
  if (ord == s){
    cout << s << '\n';
    return 0;
  }
  ll idx, idy;
  for (ll i=0; i<n; i++){
    if (s[i] != ord[i]){
      idx = i;
      char letra = s[i];
      for (ll j=n-1; j>=idx; j--){
        if (ord[j] == letra){
          idy = j;
          swap(ord[idx], ord[idy]);
          cout << ord << '\n';
          return 0;
        }
      }
    }
  }
  return 0;
}

