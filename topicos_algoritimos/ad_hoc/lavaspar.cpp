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

vector<string> word;

bool anagram(string original, string outra) {
  sort(all(original));
  sort(all(outra));
  return original == outra;
}

int main() {
  _ ll l, c;
  cin >> l >> c;
  vector<string> mat(l);
  vector<vector<pair<ll, set<string>>>> copia(
      l, vector<pair<ll, set<string>>>(c, {0, {}}));
  for (string &x : mat)
    cin >> x;

  ll w;
  cin >> w;
  while (w--) {
    string x;
    cin >> x;
    word.push_back(x);
  }
  ll especial{};

  for (ll p{}; p < word.size(); p++) {
    string vez = word[p];

    for (ll i{}; i < l; i++) {
      for (ll j{}; j < c; j++) {
        string lado{}, baixo{}, dig{}, digsec{};

        for (ll d{}; d < vez.size(); d++) {
          if (j + d < c) {
            lado += mat[i][j + d];
          }
          if (i + d < l) {
            baixo += mat[i + d][j];
          }

          if (i + d < l && j + d < c) {
            dig += mat[i + d][j + d];
          }

          if (i + d < l && j - d >= 0) {
            digsec += mat[i + d][j - d];
          }
        }

        if (anagram(vez, lado)) {
          for (ll k{}; k < vez.size(); k++) {
            copia[i][j + k].second.insert(vez);
            copia[i][j + k].first++;
          }
        }

        if (anagram(vez, baixo)) {
          for (ll k{}; k < vez.size(); k++) {
            copia[i + k][j].second.insert(vez);
            copia[i + k][j].first++;
          }
        }

        if (anagram(vez, dig)) {
          for (ll k{}; k < vez.size(); k++) {
            if (i + k < l && j + k < c) {
              copia[i + k][j + k].first++;
              copia[i + k][j + k].second.insert(vez);
            }
          }
        }

        if (anagram(vez, digsec)) {
          for (ll k{}; k < vez.size(); k++) {
            if (i + k < l && j - k >= 0) {
              copia[i + k][j - k].first++;
              copia[i + k][j - k].second.insert(vez);
            }
          }
        }
      }
    }
  }

  for (ll i{}; i < l; i++) {
    for (ll j{}; j < c; j++) {
      if (copia[i][j].first > 1 && copia[i][j].second.size() > 1)
        especial++;
    }
  }

  cout << especial << '\n';
  return 0;
}
