#include <bits/stdc++.h>
#include <ios>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 110;

ll parede[MAXN][MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll c{};
  cin >> c;
  ll testes = c;
  while (c--) {
    ll m, n, x, y;
    cin >> m >> n >> x >> y;
    x--; y--;

    vector<vector<bool>> visitado(m, vector<bool>(n));

    for (ll i=0;i<m;i++){
      for (ll j=0;j<n;j++){
        cin >> parede[i][j];
      }
    }

    ll soco = 10;
    parede[x][y] += soco;
    visitado[x][y] = true;

    queue<tuple<ll, ll, ll>> fila;
    fila.push(make_tuple(x, y, 0));

    vll adx = {0, -1, -1, -1, 0, 1, 1, 1};
    vll ady = {-1, -1, 0, 1, 1, 1, 0, -1};

    while(!fila.empty()){
      auto [cx, cy, dist] = fila.front();
      fila.pop();

      for (ll d = 0; d<8;d++){
        ll nx = adx[d] + cx;
        ll ny = ady[d] + cy;
        ll nova_dist = dist + 1;

        if (0 <= nx && nx < m && 0 <= ny && ny < n) {
          if (!visitado[nx][ny]){
            ll soco_atual = 10 - nova_dist;
            if (soco_atual > 0){
              parede[nx][ny] += soco_atual;
            } else {
              parede[nx][ny] += 1;
            }
            visitado[nx][ny] = true;
            fila.push(make_tuple(nx, ny, nova_dist));
          }
        }
      }
    }

    cout << "Parede " << testes-c << ':' << '\n';
    for (ll i=0;i<m;i++){
      for (ll j=0;j<n-1;j++){
        cout << parede[i][j] << ' ';
      }
      cout << parede[i][n-1];
      cout << '\n';
    }
  }

  return 0;
}

