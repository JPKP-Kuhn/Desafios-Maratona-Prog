#include <bits/stdc++.h>
using namespace std;

const int N = 112345;
// nó da esquerda são o dobro no vetor, nó da direita dobro+1, raíz em 1
int t[4 * N];

int query(int id, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr)
    return t[id];
  if (qr < l || r < ql)
    return 0;
  int m = (l + r) / 2;

  // nó esquerdo + nó direito
  return query(2 * id, l, m, ql, qr) + query(2 * id + 1, m + 1, r, ql, qr);
}

void update(int id, int l, int r, int p, int x) {
  if (l == r) {
    t[id] = x;
  } else {
    int m = (l + r) / 2;
    if (p <= m)
      update(2 * id, l, m, p, x);
    else
      update(2 * id + 1, m + 1, r, p, x);
    t[id] = t[2 * id] + t[2 * id + 1];
  }
}

void update_intervalo(int id, int l, int r, int ql, int qr, int x) {
  if (ql <= l && r <= qr) {
    t[id] += x;
    return;
  }
  if (qr < l || r < ql)
    return;

  int m = (r + l) / 2;
  update_intervalo(2 * id, l, m, ql, qr, x);
  update_intervalo(2 * id + 1, m + 1, r, ql, qr, x);
}

int query_ponto(int id, int l, int r, int p) {
  int m = (l + r) / 2;
  if (p <= m) {
    return t[id] + query_ponto(2 * id, l, m, p);
  } else {
    return t[id] + query_ponto(2 * id + 1, m + 1, r, p);
  }
}

int main() { return 0; }
