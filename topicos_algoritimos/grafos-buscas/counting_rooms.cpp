#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vpll = vector<pair<ll, ll>>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo


ll n, m;

void bfs(ll i, ll j, vector<string> &building, vector<vector<bool>> &used){
  vll x = {0, 1, 0, -1};
  vll y = {1, 0, -1, 0};
  queue<pair<ll, ll>> q;
  q.push({i, j});

  while(!q.empty()){
    auto [hx, hy] = q.front();
    used[hx][hy] = true;
    q.pop();

    for (ll d=0; d<4; d++){
      ll nx = hx + x[d];
      ll ny = hy + y[d];

      if (nx >= 0 && nx < n && ny >=0 && ny < m){
        if (!used[nx][ny] && building[nx][ny] == '.'){
          q.push({nx, ny});
          used[nx][ny] = true;
        }
      }
    }
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  cin.ignore();
  vector<string> building(n);
  for (ll i=0; i<n; i++){
    getline(cin, building[i]);
  }

  ll rooms{};
  vector<vector<bool>> used(n, vector<bool>(m, false));
  for (ll i=0; i<n; i++){
    for (ll j=0; j<m; j++){
      if (building[i][j] == '.' && !used[i][j]){
        bfs(i, j, building, used);
        rooms++;
      }
    }
  }

  cout << rooms << '\n';
  return 0;
}

