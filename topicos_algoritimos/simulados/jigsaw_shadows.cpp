#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vpll = vector<pair<ll, ll>>;

const double PI = 3.141592;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll angle, n;
  cin >> angle >> n;

  double shadow = 0.0;
  double angle_rad = angle * PI / 180.0;
  double tang = tan(angle_rad);

  vpll pos;
  while(n--){
    ll x, h;
    cin >> x >> h;
    pos.emplace_back(x, h);
  }

  sort(pos.begin(), pos.end());
  double last = -1e18;
  for (auto [x, h] : pos){
    double end = x + h/tang;
    if (end <= last) continue;
    if (x >= last){
      shadow += end - x;
    } else {
      shadow += end - last;
    }
    last = max(last, end);
  }

  cout << fixed << setprecision(10) << shadow << '\n';

  return 0;
}

