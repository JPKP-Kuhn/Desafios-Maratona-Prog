#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ll n{};
  vll valores;

  while(cin >> n){

    valores.push_back(n);

    ll size = valores.size();
    vll temp = valores;

    // Mediana
    if (size % 2 == 1) { // Tamanho ímpar de valores
      nth_element(temp.begin(), temp.begin()+size/2, temp.end()); // Apenas o elemento do meio estará na posição correta
      cout << temp[size/2] << '\n';
    } else {             // Tamanho par de valores
      nth_element(temp.begin(), temp.begin()+ size/2 - 1, temp.end());
      ll a = temp[size/2 - 1];
      nth_element(temp.begin(), temp.begin()+size/2, temp.end());
      ll b = temp[size/2];
      cout  << (a+b)/2 << '\n';
    }
  }

  return 0;
}

