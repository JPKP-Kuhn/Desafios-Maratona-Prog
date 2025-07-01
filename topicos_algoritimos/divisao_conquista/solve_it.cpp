#include <bits/stdc++.h>
#include <iomanip>
#include <ios>
using namespace std;
using lld = long double;

const lld EPS = 1e-9;

// Equação a ser resolvida
// p ∗ e−x + q ∗ sin(x) + r ∗ cos(x) + s ∗ tan(x) + t ∗ x2 + u = 0

lld p, q, r, s, t, u;
// Determinar x
double x;

// Minha função
lld f(lld x){
  return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2) + u; 
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> p >> q >> r >> s >> t >> u){
    // intervalo, 0 <= x <= 1
    lld a = 0.0, b = 1.0;
    // O teorema de Bolzano (valor intermediário) foi satisfeito? 
    // f(a0) * f(b0) < 0 -> existe troca de sinal no intervalo dado e, portanto
    // existe raiz nele.
    int bolzano_ok = (f(a)*f(b) > 0?0:1);
    if (!bolzano_ok) {
      cout << "No solution\n";
      continue;
    }
    if (fabs(f(a)) < EPS || fabs(f(b)) < EPS){
      cout << fixed << setprecision(4) << (f(a)==0 ? a : b) << '\n';
      continue;
    }

    // Método da bissecção
    // Busca binária
    while (b - a > EPS){
      lld pm = (a + b)/2.0;
      if (fabs(f(pm)) < EPS){
        break;
      }
      if (f(a)*f(pm) < 0){
        b = pm; // Solução está a esquerda
      } else {
        a = pm; // Solução está a direita
      }
    }
    cout << fixed << setprecision(4) << (a+b)/2.0 << '\n';
  }

  return 0;
}

