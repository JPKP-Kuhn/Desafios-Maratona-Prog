#include <bits/stdc++.h>
#include <limits>
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

bool anagram(string a, string b) {
  string na{}, nb{};
  for (char c : a) {
    if (c != ' ')
      na += c;
  }

  for (char c : b) {
    if (c != ' ') {
      nb += c;
    }
  }

  sort(all(na));
  sort(all(nb));

  return na == nb;
}

int main() {
  _ ll n;
  bool primeiro = true;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  string vazio;
  getline(cin, vazio);
  while (n--) {
    vector<string> v;
    string line;
    while (getline(cin, line) && !line.empty())
      v.pb(line);
    sort(all(v));

    if (!primeiro)
      cout << '\n';
    for (ll i{}; i < v.size(); i++) {
      for (ll j = i + 1; j < v.size(); j++) {
        if (anagram(v[i], v[j])) {
          cout << v[i] << " = " << v[j] << '\n';
        }
      }
    }
    primeiro = false;
  }

  return 0;
}
