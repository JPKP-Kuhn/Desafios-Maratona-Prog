#include <bits/stdc++.h>
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

// M_PI para número PI
const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

struct point {
  double x, y;
  point() { x = y = 0.0; }
  point(double _x, double _y) : x(_x), y(_y) {}
  bool operator<(point other) const {
    if (fabs(x - other.x) > EPS)
      return x < other.x;
    return y < other.y;
  };
};

vll v;

void merge_sort(ll left, ll right) {
  if (left == right)
    return;

  ll mid = (left + right) >> 1;

  merge_sort(left, mid);
  merge_sort(mid + 1, right);

  vll temp;
  ll i = left;
  ll j = mid + 1;

  while (i <= mid && j <= right) {
    if (v[i] < v[j]) {
      temp.push_back(v[i++]);
    } else {
      temp.push_back(v[j++]);
    }
  }

  while (i <= mid) {
    temp.push_back(v[i++]);
  }

  while (j <= right) {
    temp.push_back(v[j++]);
  }

  for (ll k = left; k <= right; k++) {
    v[k] = temp[k - left];
  }
}

int main() {
  _

      return 0;
}
