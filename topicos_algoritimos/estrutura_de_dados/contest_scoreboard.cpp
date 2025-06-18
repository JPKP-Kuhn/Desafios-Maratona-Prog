#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;          // PD e inicialização de valor mínimo

struct Contestant {
  int id;
  int solved = 0;
  int penalty = 0;
  bool submitted = false;
  int incorrect[10] = {0};
  bool solved_problem[10] = {false};
};

bool compare(const Contestant& a, const Contestant& b) {
  if (a.solved != b.solved) return a.solved > b.solved;
  if (a.penalty != b.penalty) return a.penalty < b.penalty;
  return a.id < b.id;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll test{};
  string line;
  getline(cin, line);
  test = stoi(line);
  getline(cin, line);

  while (test--){
    vector<Contestant> contestants(101);

    for (int i = 1; i<=100; i++){
      contestants[i].id = i;
    }

    while(getline(cin, line)){
      if (line.empty()) break;

      int contest, problem, time;
      char l;
      stringstream ss(line);
      ss >> contest >> problem >> time >> l;

      Contestant& c = contestants[contest];
      c.submitted = true;

      if (l == 'C'){
        if (!c.solved_problem[problem]){
          c.solved++;
          c.penalty += time + 20 * c.incorrect[problem];
          c.solved_problem[problem] = true;
        }
      } else if (l == 'I') {
        if (!c.solved_problem[problem]){
          c.incorrect[problem]++;
        }
      }
    }

    vector<Contestant> scoreboard;
    for (int i =1; i<=100; i++){
      if (contestants[i].submitted){
        scoreboard.push_back(contestants[i]);
      }
    }

    sort(scoreboard.begin(), scoreboard.end(), compare);

    for (auto& c : scoreboard){
      cout << c.id << ' ' << c.solved << ' ' << c.penalty << '\n';
    }
    if (test) cout << '\n';
  }

  return 0;
}

