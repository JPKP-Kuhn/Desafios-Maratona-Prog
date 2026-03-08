#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e6+10;

ll n;
ll bailarinas[MAXN], aux[MAXN];

ll merge_sort(ll ini, ll fim){
  if (ini >= fim) return 0;

  ll mid = (ini+fim)/2;
  ll inver = merge_sort(ini, mid) + merge_sort(mid+1, fim);

  // Ponteiros
  ll i=ini, j=mid+1, k=ini;
  // i - metade esquerda; j - metade direita; k - preencher vetor auxiliar

  while(i <= mid && j <= fim){
    // Elemento da esquerda não é maior, não há inversão
    if (bailarinas[i] <= bailarinas[j]){
      aux[k++] = bailarinas[i++];
    } else { // há inversão
      aux[k++] = bailarinas[j++];
      // Todos os elementos da esqueda de i até mid são maiores que bailarinas[j]
      // então somamos essa quantidade
      inver += (mid - i+1);
    }
  }
  // Copia o que sobrou da metade esquerda (se houver)
  while(i <= mid) aux[k++] = bailarinas[i++];

  // Copia o que sobrou da metade direita (se houver)
  while(j <= fim) aux[k++] = bailarinas[j++];

  // Cppia de volta para o vetor original
  for(ll t=ini; t<=fim; t++){
    bailarinas[t] = aux[t];
  }

  return inver;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (ll i{}; i<n; i++) {
    ll x; cin >> x;
    bailarinas[i] = x;
  }
  ll c = merge_sort(0, n-1);
  cout << c << '\n';

  return 0;
}

