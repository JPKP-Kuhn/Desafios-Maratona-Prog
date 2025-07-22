#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const double EPS = 1e-9;
ll d(pair<ll, ll> &a, pair<ll, ll> &b){
  ll x = a.first - b.first;
  ll y = a.second - b.second;
  return sqrt(x * x + y * y);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<pair<ll, ll>> points(4);
  for (auto &x : points) cin >> x.first >> x.second;
  sort(points.begin(), points.end());
  do{
    ll d1 = d(points[0], points[1]);
    ll d2 = d(points[1], points[2]);
    ll d3 = d(points[2], points[3]);
    ll d4 = d(points[3], points[0]);

    ll diag1 = d(points[0], points[2]);
    ll diag2 = d(points[1], points[3]);
    if (d1 > 0 && d1 == d2 && d2 == d3 && d3 == d4 && diag1 == diag2){
      cout << "SIM\n";
      return 0;
    }
  } while(next_permutation(points.begin(), points.end()));
  cout << "NAO\n";
  return 0;
}

