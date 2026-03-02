#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string t; getline(cin, t);
  replace(t.begin(), t.end(), '.', ' ');
  vector<string> v;
  stringstream ss(t);
  string word;
  while(ss >> word){
    v.push_back(word);
  }
  sort(v.begin(), v.end());
  cout << v[0] << '\n';

  return 0;
}

