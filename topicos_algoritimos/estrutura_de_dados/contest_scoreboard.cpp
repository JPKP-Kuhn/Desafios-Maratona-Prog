#include <bits/stdc++.h>
#include <cstdio>
#include <ios>
#include <sstream>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;          // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll test{};
  cin >> test;
  cin.ignore();
  while (test--){
    
    // Number of problems solved / decreasing penalty time / increasing team number 
    vector<vector<int>> contestants (101, vector<int>(3, 0));

    // problemas resolvidos por cada time
    vector<vector<bool>> solved(101, vector<bool>(10, false));

    vector<vector<int>> wrong_puzzles(101, vector<int>(10, 0));

    vector<bool> participated(101, false);

    for (int i=1;i<101;i++){
      contestants[i][2] = i;
    }

    string line;
    getline(cin, line);

    while(getline(cin, line) && !line.empty()){
      istringstream iss(line);
      int contestant, problem, time;
      char l;

      iss >> contestant >> problem >> time >> l;
      participated[contestant] = true;

      if (l == 'C'){
        solved[contestant][problem] = true;
        contestants[contestant][0]++;
        contestants[contestant][1] += time + 20 * wrong_puzzles[contestant][problem];
      } else if (l == 'I'){
          wrong_puzzles[contestant][problem]++;
      }
    }

    vector<pair<int , pair<int, int>>> scoreboard;
    for (int i =0; i<100; i++){
      if (participated[i]){
        scoreboard.push_back(make_pair(contestants[i][0], make_pair(-contestants[i][1], contestants[i][2])));
      }
    }

    sort(scoreboard.rbegin(), scoreboard.rend());

    for (auto& i : scoreboard){
      cout << i.second.second << ' ' << i.first << ' ' << -i.second.first << '\n';
    }
  }

  return 0;
}

