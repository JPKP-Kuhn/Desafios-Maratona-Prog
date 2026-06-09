#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
#define fr first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

struct Edge {
  string to, word;
  ll cost{};
};

struct State {
  ll dist;
  string lang;
  char last;

  bool operator>(const State &other) const { return dist > other.dist; }
};

ll idx(char c) {
  if (c == '#')
    return 26;
  return c - 'a';
}

const ll INF = 1e18 + 7;

int main() {
  _ ll m;
  while (cin >> m && m) {
    unordered_map<string, vector<Edge>> adj;
    unordered_map<string, vll> dist;
    string origem, destino;
    cin >> origem >> destino;

    if (origem == destino) {
      cout << 0 << '\n';
      for (ll i{}; i < m; i++) {
        string v, u, w;
        cin >> v >> u >> w;
      }
      continue;
    }
    for (ll i{}; i < m; i++) {
      string v, u, w;
      cin >> v >> u >> w;
      adj[v].push_back({u, w, (ll)w.size()});
      adj[u].push_back({v, w, (ll)w.size()});
    }

    dist[origem] = vector<ll>(27, INF);
    dist[destino] = vector<ll>(27, INF);
    for (auto &[lang, r] : adj)
      dist[lang] = vector<ll>(27, INF);
    dist[origem][26] = 0;

    priority_queue<State, vector<State>, greater<State>> fila;

    ll menor = INF;

    fila.push({0, origem, '#'});
    while (!fila.empty()) {
      State s = fila.top();
      fila.pop();
      ll d = s.dist;
      string lang = s.lang;
      char l = s.last;

      if (d != dist[lang][idx(l)])
        continue;

      for (Edge &e : adj[lang]) {
        char first = e.word[0];
        if (first == l)
          continue;

        ll nd = d + e.cost;
        ll nxt = idx(first);

        if (nd < dist[e.to][nxt]) {
          dist[e.to][nxt] = nd;
          fila.push({nd, e.to, first});
        }
      }
    }
    ll ans = INF;

    for (ll i{}; i < 27; i++) {
      ans = min(ans, dist[destino][i]);
    }
    if (ans == INF) {
      cout << "impossivel\n";
    } else {
      cout << ans << '\n';
    }
  }

  return 0;
}
