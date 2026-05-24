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

string solve(unordered_map<string, unordered_set<string>> &pp, string name,
             string presente) {
  if (pp[name].count(presente) != 0)
    return "Uhul! Seu amigo secreto vai adorar o/";

  return "Tente Novamente!";
}

bool digit(string sus) {
  set<char> s = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  if (s.count(sus[0]) != 0)
    return true;
  return false;
}

int main() {
  _ int n;
  while (cin >> n) {
    unordered_map<string, unordered_set<string>> pessoa_presentes;
    string nome, p1, p2, p3;

    for (ll i{}; i < n; i++) {
      cin >> nome >> p1 >> p2 >> p3;

      pessoa_presentes[nome].insert(p1);
      pessoa_presentes[nome].insert(p2);
      pessoa_presentes[nome].insert(p3);
    }

    string name, presente;
    string sus;
    bool ok = false;
    while (cin >> sus) {
      if (digit(sus)) {
        n = stoi(sus);
        ok = true;
        break;
      } else {
        name = sus;
        cin >> presente;

        cout << solve(pessoa_presentes, name, presente) << '\n';
      }
    }
    if (ok)
      continue;
  }

  return 0;
}
