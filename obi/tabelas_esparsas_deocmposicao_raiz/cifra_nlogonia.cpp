#include <bits/stdc++.h>
#include <unordered_set>
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

set<char> vogais = {'a', 'e', 'i', 'o', 'u'};

char vog_prox(char l) {
  if (l > 'u' && l <= 'z') {
    return 'u';
  }
  char ce, cd;
  for (char a = l; a <= 'z'; a++) {
    if (vogais.count(a)) {
      cd = a;
      break;
    }
  }

  for (char a = l; a >= 'a'; a--) {
    if (vogais.count(a)) {
      ce = a;
      break;
    }
  }
  ll dd = (ll)cd - (ll)l;
  ll de = (ll)l - (ll)ce;

  return (de <= dd ? ce : cd);
}

int main() {
  _ string s;
  cin >> s;

  string ans{};
  for (char c : s) {
    if (vogais.count(c) == 0) {
      ans += c;

      char v = vog_prox(c);
      ans += v;

      if (c == 'z')
        ans += 'z';
      else if (c == 'v')
        ans += 'x';
      else if (c == 'x')
        ans += 'z';
      else
        for (char l = c + 1; l <= 'z'; l++) {
          if (vogais.count(l) == 0) {
            ans += l;
            break;
          }
        }
    } else {
      ans += c;
    }
  }

  cout << ans << '\n';

  return 0;
}
