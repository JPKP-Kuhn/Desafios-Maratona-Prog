#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
#define fr first
#define sc second
#define pb push_back

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;

int main() {
  _ ll n;
  cin >> n;
  bool ans = true;
  unordered_map<ll, ll> freq;
  unordered_map<ll, ll> somas;

  vector<vll> mat(n, vll(n, 0));
  for (ll i{}; i < n; i++) {
    ll somaLinha{};
    for (ll j{}; j < n; j++) {
      ll x;
      cin >> x;
      if (freq.count(x) == 0)
        freq[x]++;
      else
        ans = false;

      if (ans) {
        mat[i][j] = x;
        somaLinha += x;
      }
    }
    somas[somaLinha]++;
  }

  if (ans) {
    for (ll i{}; i < n; i++) {
      ll somaColuna{};
      for (ll j{}; j < n; j++) {
        somaColuna += mat[j][i];
      }
      if (somas.count(somaColuna) == 0) {
        ans = false;
        break;
      }
    }
  }

  if (ans) {
    ll digp{}, digsec{};
    for (ll i{}; i < n; i++) {
      digp += mat[i][i];
      digsec += mat[i][n - i - 1];
    }

    if (digp != digsec) {
      ans = false;
    }
  }

  cout << (ans ? somas.begin()->first : 0) << '\n';

  return 0;
}
