#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;

int main() {
  _ ll n;
  cin >> n;
  string s, b, c;
  cin >> s >> b >> c;
  string v{};
  for (char c : s) {
    if (c == '>') {
      v += 'R';
    } else if (c == '<') {
      v += 'L';
    }
  }

  // custo 1
  // comparar com RRRRLLLL e com LLLLRRRR

  ll mid = v.size() / 2;

  ll comp1{}, comp2{};
  for (ll i{}; i < mid; i++) {
    if (v[i] == 'R')
      comp1++;
    else
      comp2++;
  }
  for (ll i = mid; i < v.length(); i++) {
    if (v[i] == 'L')
      comp1++;
    else
      comp2++;
  }

  ll prim = min(v.length() - comp1, v.length() - comp2);

  // alternado
  // LRLRLR ou RLRLRLRL

  comp1 = 0;
  comp2 = 0;

  for (ll i{}; i < v.length(); i++) {
    if (i % 2 == 0) {
      if (v[i] == 'L')
        comp1++;
      else
        comp2++;
    } else {
      if (v[i] == 'R')
        comp1++;
      else
        comp2++;
    }
  }

  ll sec = min(v.length() - comp1, v.length() - comp2);

  cout << min(prim, sec) << '\n';

  return 0;
}
