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
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

// M_PI para número PI
const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

int main() {
  _ ll n;
  while (cin >> n && n) {
    vll h(n);
    for (ll &x : h)
      cin >> x;

    stack<ll> st;
    ll maior{};

    for (ll i{}; i <= n; i++) {
      ll alturaAtual = (i == n ? 0 : h[i]);

      while (!st.empty() && alturaAtual < h[st.top()]) {
        ll altura = h[st.top()];
        st.pop();

        ll largura = (st.empty() ? i : i - st.top() - 1);

        maior = max(maior, altura * largura);
      }

      st.push(i);
    }

    cout << maior << '\n';
  }
  return 0;
}
