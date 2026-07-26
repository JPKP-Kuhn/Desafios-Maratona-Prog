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

const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

bool maior(bitset<5000> &a, bitset<5000> &b, ll l) {
  for (ll i = l - 1; i >= 0; i--) {
    if (a[i] != b[i])
      return a[i] > b[i];
  }
  return false;
}

int main() {
  _ ll t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    // MSB 0
    ll k{-1};
    for (ll i{}; i < s.size(); i++)
      if (s[i] == '0') {
        k = i;
        break;
      }

    if (k != -1) {
      ll l = (ll)s.size() - k;
      string target = s.substr(k);
      bitset<5000> a(target);
      bitset<5000> b;
      bitset<5000> c;
      bitset<5000> best;
      bool first = true;
      ll l1, r1;
      for (ll i{}; i + l <= s.size(); i++) {
        string cand = s.substr(i, l);
        b = bitset<5000>(cand);
        c = a ^ b;
        if (first || maior(c, best, l)) {
          best = c;
          l1 = i;
          r1 = i + l;
          first = false;
        }
      }
      cout << 1 << ' ' << s.size() << ' ' << l1 + 1 << ' ' << r1 << '\n';
    } else {
      cout << 1 << ' ' << s.size() << ' ' << 1 << ' ' << 1 << '\n';
    }
  }

  return 0;
}
