#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;          // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;
  string server{};
  server.reserve(1000000);
  vector<string> pc(n+1);

  for (int i=1;i<=n; i++){
    pc[i].reserve(1000000);
  }
  ll comand, which_pc;
  string s;
  for (int i=0; i<q; i++){
    cin >> comand;
    if (comand == 1){
      cin >> which_pc;
      pc[which_pc] = server;
    } else if(comand == 2) {
      cin >> which_pc >> s;
      pc[which_pc] += s;
    } else {
      cin >> which_pc;
      server = move(pc[which_pc]);
      pc[which_pc] = server;
    }
  }
cout << server << '\n';

return 0;
}

