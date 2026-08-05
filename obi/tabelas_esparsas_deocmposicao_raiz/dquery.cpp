#include <bits/stdc++.h>
#include <cstring>
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

const ll MAXN = 1e6 + 10; // Range seguro para vetores e arrays

ll n, m;
ll a[MAXN], quant[MAXN];
ll ans{}, block;
void remove(ll idx) {
  ll v = a[idx];
  quant[v]--;
  if (quant[v] == 0)
    ans--;
}

void add(ll idx) {
  ll v = a[idx];
  if (quant[v] == 0)
    ans++;
  quant[v]++;
}
ll get_answer() { return ans; }

struct Query {
  ll l, r, idx;
  bool operator<(const Query &other) const {
    ll b1 = l / block, b2 = other.l / block;
    if (b1 != b2)
      return b1 < b2;

    if (b1 & 1)
      return r > other.r;

    return r < other.r;
  }
};

vll mo_s_algorithm(vector<Query> queries) {
  vll answers(queries.size());
  sort(all(queries));

  ll cur_l = 0, cur_r = -1;
  for (Query q : queries) {
    while (cur_l > q.l) {
      cur_l--;
      add(cur_l);
    }
    while (cur_r < q.r) {
      cur_r++;
      add(cur_r);
    }
    while (cur_l < q.l) {
      remove(cur_l);
      cur_l++;
    }
    while (cur_r > q.r) {
      remove(cur_r);
      cur_r--;
    }
    answers[q.idx] = get_answer();
  }
  return answers;
}

int main() {
  _ cin >> n;
  for (ll i{}; i < n; i++) {
    cin >> a[i];
  }
  memset(quant, 0, sizeof(quant));
  block = sqrt(n) + 1;
  cin >> m;

  vector<Query> queries(m);
  for (ll i{}; i < m; i++) {
    ll l, r;
    cin >> l >> r;
    queries[i] = {l - 1, r - 1, i};
  }
  vll final = mo_s_algorithm(queries);

  for (ll x : final)
    cout << x << '\n';

  return 0;
}
