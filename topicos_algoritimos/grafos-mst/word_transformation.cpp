#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

bool diff_one(const string &s, const string &e){
  if (s.length() != e.length()) return false;
  ll diff = 0;
  for (ll i = 0; i < s.length(); i++){
    if (s[i] != e[i]) diff++;
    if (diff > 1) return false;
  }
  return diff == 1;
}

ll bfs(const vector<vll>& adj, ll start, ll end){
  queue<ll> q;
  vll dist(adj.size(), -1);
  q.push(start);
  dist[start] = 0;
  while (!q.empty()){
    ll v = q.front();
    q.pop();
    if (v == end) return dist[v];
    for (ll u : adj[v]){
      if (dist[u] == -1){
        dist[u] = dist[v] + 1;
        q.push(u);
      }
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n;
  cin >> n;
  string blank;
  getline(cin, blank); // Consome o \n após o número

  while (n--) {
    vector<string> words;
    map<string, ll> word_idx;
    string word;

    while (cin >> word && word != "*") {
      word_idx[word] = words.size();
      words.push_back(word);
    }

    getline(cin, blank); 

    vector<vll> adj(words.size());
    for (ll i = 0; i < words.size(); i++) {
      for (ll j = i + 1; j < words.size(); j++) {
        if (diff_one(words[i], words[j])) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }

    string line;
    while (getline(cin, line) && !line.empty()) {
      stringstream ss(line);
      string s, e;
      ss >> s >> e;
      ll start = word_idx[s];
      ll end = word_idx[e];
      ll steps = bfs(adj, start, end);
      cout << s << ' ' << e << ' ' << steps << '\n';
    }

    if (n) cout << '\n'; 
  }

  return 0;
}

