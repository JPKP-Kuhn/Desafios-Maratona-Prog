#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
using vll = vector<ll>;

bool comp(string a, string b){
  return a.length() > b.length();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t; cin >> t;
  cin.ignore();
  while(t--){
    vector<string> words;
    string line;
    getline(cin, line);
    stringstream ss(line);
    string word;
    while (ss >> word){
      words.push_back(word);
    }

    stable_sort(words.begin(), words.end(), comp);

    for (size_t i=0; i<words.size(); ++i){
      cout << words[i];
      if (i < words.size()-1){
        cout << ' ';
      }
    }
    cout << '\n';
  }

  return 0;
}

