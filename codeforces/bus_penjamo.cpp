#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ll tests;
  cin >> tests;

  while (tests--) {
    ll families, rows;
    cin >> families >> rows;

    ll seats = 2 * rows;
    vll mem_families;

    ll x, people = 0;
    for (ll i = 0; i < families; i++) {
      cin >> x;
      people += x;
      mem_families.push_back(x);
    }

    ll happy = 0;
    ll used_rows = 0;

    // Formar todos os pares possíveis
    for (ll i = 0; i < families; i++) {
      ll pair = mem_families[i] / 2;
      pair = min(pair, rows - used_rows);

      happy += pair * 2;
      used_rows += pair;
      mem_families[i] -= pair * 2;
    }

    // Restantes individuais
    ll remaining_people = 0;
    for (ll i = 0; i < families; i++) {
      remaining_people += mem_families[i];
    }

    ll rem_rows = rows - used_rows;

    // Corrigido aqui: só 1 pessoa feliz por fileira vazia
    happy += min(remaining_people, rem_rows);

    cout << happy << endl;
  }
  return 0;
}

