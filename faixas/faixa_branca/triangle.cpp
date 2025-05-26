#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll a, b, c;
  bool tri;
  vector<ll> triangulo;
  cin >> a >> b >> c;
  triangulo.push_back(a);
  triangulo.push_back(b);
  triangulo.push_back(c);

  sort(triangulo.begin(), triangulo.end());

  if (a + b > c && a + c > b && b + c > a) {
    tri = true;
  } else {
    cout << "Invalido" << endl;
  }

  if (tri) {
    cout << "Valido-";

    if (a != b && b != c) {
      cout << "Escaleno" << '\n';
    } else if (a == b && b == c) {
      cout << "Equilatero" << '\n';
    } else {
      cout << "Isoceles" << '\n';
    }

    if (pow(triangulo[0], 2) + pow(triangulo[1], 2) == pow(triangulo[2], 2)) {
      cout << "Retangulo: S" << '\n';
    } else {
      cout << "Retangulo: N" << '\n';
    }
  }


  return 0;
}

