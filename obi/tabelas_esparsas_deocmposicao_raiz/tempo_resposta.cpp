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

struct Pessoa {
  ll iR, tempo{};
  bool espera = false;
  bool participa = false;

  Pessoa() : espera{false}, participa{false}, tempo{}, iR{} {}
};
int main() {
  _ ll n;
  cin >> n;
  map<ll, Pessoa> amigo;
  for (ll i = 1; i <= n; i++)
    amigo[i] = Pessoa();

  ll tempoTotal{};
  ll delta = 1;
  bool primeiroEvento = true;
  for (ll i{}; i < n; i++) {
    char o;
    ll x;
    cin >> o >> x;

    if (o == 'T') {
      delta = x;
      continue;
    }

    if (!primeiroEvento)
      tempoTotal += delta;
    else
      primeiroEvento = false;

    delta = 1;

    if (o == 'R') {
      amigo[x].participa = true;
      amigo[x].espera = true;
      amigo[x].iR = tempoTotal;
    } else if (o == 'E') {
      amigo[x].espera = false;
      amigo[x].tempo += tempoTotal - amigo[x].iR;
    }
  }

  for (auto &[k, v] : amigo) {
    if (v.participa)
      cout << k << ' ' << (v.espera ? -1 : v.tempo) << '\n';
  }

  return 0;
}
