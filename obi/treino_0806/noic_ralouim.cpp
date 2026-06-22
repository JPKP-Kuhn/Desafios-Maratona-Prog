// OBI 2020 - Fase 1 - Turno B - Ralouim
// Complexidade: O(n² log n²)
// Escrito por Lúcio Figueiredo

#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef pair<int, int> pii;

const int maxn = 2e3 + 10;

int n;
int x[maxn], y[maxn];

int mx[maxn];

int dp[maxn][maxn];

// distância euclidiana entre as tendas i e j
int dist(int i, int j) {
  int dx = x[i] - x[j];
  int dy = y[i] - y[j];

  return (dx * dx + dy * dy);
}

// função auxiliar para ordenar os pares de tendas pela distância
bool comp(pii a, pii b) { return dist(a.ff, a.ss) < dist(b.ff, b.ss); }

int main(void) {
  scanf("%d", &n);

  for (int i = 1; i <= n; i++)
    scanf("%d %d", &x[i], &y[i]);

  // vector que guarda os pares de tendas ordenados pela distancia
  vector<pii> par;

  // inserimos os pares no vector
  for (int i = 0; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j)
        par.push_back({i, j});

  // em seguida, ordenamo-os
  sort(par.begin(), par.end(), comp);

  for (int i = 0; i < par.size(); i++) {
    // OBSERVAÇÃO: Caso existam pares de tendas com distância iguais, precisamos
    // calcular as suas dps ANTES de atualizar o vetor mx[]. Por isso,
    // utilizamos a variável j para iterar por tais pares. Após isso, usando o
    // mesmo for, atualizamos o vetor mx.

    int j;
    for (j = i; j < par.size() &&
                dist(par[i].ff, par[i].ss) == dist(par[j].ff, par[j].ss);
         j++) {
      int u = par[j].ff, v = par[j].ss;

      dp[u][v] = 1 + mx[v]; // cálculo da dp
    }

    for (j = i; j < par.size() &&
                dist(par[i].ff, par[i].ss) == dist(par[j].ff, par[j].ss);
         j++) {
      int u = par[j].ff, v = par[j].ss;

      mx[u] = max(mx[u], dp[u][v]); // atualizamos o vetor auxiliar mx
    }

    // A tenda j-1 foi a última tenda que iteramos, portanto, fazemos que i =
    // j-1 para que i se torne j na iteração seguinte
    i = j - 1;
  }

  // resposta final
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans = max(ans, dp[0][i]);

  printf("%d\n", ans);
}
