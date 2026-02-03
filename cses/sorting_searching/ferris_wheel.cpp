#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, x, g{}; cin >> n >> x;
  vll w(n), rw(n);
  for (ll &x : w)cin >> x;
  sort(w.begin(), w.end());
  ll i{}, j{n-1};
  while (i<n && j>=0 && i<=j){
    if (w[i] + w[j] <= x){
      g++; i++; j--;
    } else if (w[i]>x){
      i++;
    } else if (w[j]>x){
      j--;
    } else {
      j--; g++;
    }
  }
  cout << g << '\n';

  return 0;
}

