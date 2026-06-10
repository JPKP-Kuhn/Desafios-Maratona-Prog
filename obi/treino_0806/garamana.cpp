#include <bits/stdc++.h>
#include <unordered_map>
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

int main() {
  _ string p, a;
  cin >> p >> a;
  if (p.length() != a.length()) {
    cout << "N\n";
    return 0;
  }
  string chave{};
  unordered_map<char, ll> freqp, freqa;
  for (ll i{}; i < p.length(); i++) {
    freqp[p[i]]++;
    freqa[a[i]]++;

    if (a[i] != '*') {
      chave += a[i];
    }
  }

  for (char c : a) {
    if (c != '*' && (freqp.count(c) == 0 || freqa[c] > freqp[c])) {
      cout << "N\n";
      return 0;
    }
  }

  if (chave.length() + freqa['*'] != p.length()) {
    cout << "N\n";
    return 0;
  }
  cout << "S\n";

  return 0;
}
