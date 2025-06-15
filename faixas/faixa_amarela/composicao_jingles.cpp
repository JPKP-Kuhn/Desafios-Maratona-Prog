#include <bits/stdc++.h>
#include <ios>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;          // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string composicao{};
  while (cin >> composicao && composicao != "*"){
    vector<string> jingles{};
    stringstream ss(composicao);
    string parte;

    while (getline(ss, parte, '/')){
      if (!parte.empty()){
        jingles.push_back(parte);
      }
    }

    vector<double> compassos{};
    for (ll i=0;i<jingles.size();i++){
      double valor{};
      for (ll j=0;j<jingles[i].length(); j++){
        if (jingles[i][j] == 'W') valor += 1.0;
        if (jingles[i][j] == 'H') valor += 0.5;
        if (jingles[i][j] == 'Q') valor += 0.25;
        if (jingles[i][j] == 'E') valor += 0.125;
        if (jingles[i][j] == 'S') valor += 0.0625;
        if (jingles[i][j] == 'T') valor += 0.03125;
        if (jingles[i][j] == 'X') valor += 0.015625;
      }
      compassos.push_back(valor);
    }

    ll count{};
    for (double k : compassos){
      if (k == 1.0) count++;
    }

    cout << count << '\n';
  }

  return 0;
}

