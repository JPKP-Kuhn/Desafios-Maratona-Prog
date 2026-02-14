#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string monster; cin >> monster;
  string c = "RBL";
  sort(c.begin(), c.end());
  unordered_set<string> combo;
  do{
    combo.insert(c);
  } while(next_permutation(c.begin(), c.end()));

  string defense{};
  ll len = monster.length();
  for (ll i{}; i<len; i++){
    if (i < len-2){
      string test = monster.substr(i, 3);
      if (combo.count(test)){
        defense+='C'; i+=2;
        continue;
      }
    }
    if (monster[i]=='R') defense+='S';
    else if (monster[i]=='B') defense+='K';
    else defense+='H';
  }
  cout << defense << '\n';
  return 0;
}

