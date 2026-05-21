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

// M_PI para número PI
const ll MAXN = 1e6 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

// https://www.geeksforgeeks.org/dsa/prime-factorization-using-sieve-olog-n-multiple-queries/
ll spf[MAXN];

int main() {
  _ ll t;
  cin >> t;

  for (ll i{1}; i < MAXN; i++)
    spf[i] = i;

  for (ll i = 2; i * i < MAXN; i++) {
    if (spf[i] == i) {
      for (ll j = i * i; j < MAXN; j += i) {
        if (spf[j] == j)
          spf[j] = i;
      }
    }
  }

  while (t--) {
    ll n;
    cin >> n;
    vll v(n);
    bool inicial = true;
    cin >> v[0];
    for (ll i{1}; i < n; i++) {
      cin >> v[i];
      if (v[i - 1] > v[i]) {
        inicial = false;
      }
    }
    if (inicial) {
      cout << "Bob\n";
    } else {

      ll s{};
      for (ll x : v) {
        while (x > 1) {
          ll p = spf[x];
          ll c{};

          while (x % p == 0) {
            x /= p;
            c++;
          }
          s += (c - 1);
        }
      }
      cout << ((s % 2) ? "Alice\n" : "Bob\n");
    }
  }

  return 0;
}
