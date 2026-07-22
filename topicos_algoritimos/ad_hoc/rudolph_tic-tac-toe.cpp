#include <bits/stdc++.h>
#include <cstdio>
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

bool print_string(string s) {
  if (count(all(s), 'X') == 3) {
    cout << 'X';
    return true;
  } else if (count(all(s), 'O') == 3) {
    cout << 'O';
    return true;
  } else if (count(all(s), '+') == 3) {
    cout << '+';
    return true;
  }
  return false;
}

int main() {
  _ ll n;
  cin >> n;

  while (n--) {
    vector<string> mat(3);
    for (string &x : mat)
      cin >> x;

    string c1, c2, c3, d1, d2;
    for (ll i{}; i < 3; i++) {
      c1 += mat[i][0];
      c2 += mat[i][1];
      c3 += mat[i][2];

      d1 += mat[i][i];
      d2 += mat[i][3 - i - 1];
    }

    if (print_string(mat[0])) {
    } else if (print_string(mat[1])) {
    } else if (print_string(mat[2])) {
    } else if (print_string(c1)) {
    } else if (print_string(c2)) {
    } else if (print_string(c3)) {
    } else if (print_string(d1)) {
    } else if (print_string(d2)) {
    } else {
      cout << "DRAW";
    }
    cout << '\n';
  }

  return 0;
}
