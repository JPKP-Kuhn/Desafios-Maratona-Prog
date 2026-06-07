#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;

int main() {
  _ ll h, w, k;
  cin >> h >> w >> k;
  vector<string> mat(h);
  vector<vll> prefix(h + 1, vll(w + 1, 0));
  for (string &x : mat)
    cin >> x;
  for (ll i{}; i < h; i++) {
    for (ll j{}; j < w; j++) {
      prefix[i + 1][j + 1] = (mat[i][j] - '0') + prefix[i][j + 1] +
                             prefix[i + 1][j] - prefix[i][j];
    }
  }
  ll cont{};
  for (ll c1 = 0; c1 < h; c1++) {
    for (ll c2 = 0; c2 < w; c2++) {
      for (ll f1 = c1; f1 < h; f1++) {
        for (ll f2 = c2; f2 < w; f2++) {
          ll soma = prefix[f1 + 1][f2 + 1] - prefix[c1][f2 + 1] -
                    prefix[f1 + 1][c2] + prefix[c1][c2];
          if (soma == k)
            cont++;
        }
      }
    }
  }
  cout << cont << '\n';

  return 0;
}
