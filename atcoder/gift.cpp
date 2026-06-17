#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
#define fr first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

const double PI = 3.14159265358979323846;
const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

int main() {
  _ ll n;
  cin >> n;
  vector<vll> people(n + 1);

  for (ll i{1}; i <= n; i++) {
    ll k;
    cin >> k;
    while (k--) {
      ll a;
      cin >> a;
      people[a].push_back(i);
    }
  }

  for (ll i{1}; i <= n; i++) {
    cout << people[i].size() << ' ';
    for (ll p : people[i]) {
      cout << p << ' ';
    }
    cout << '\n';
  }

  return 0;
}
