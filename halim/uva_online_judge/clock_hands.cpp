#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll h, m;
  while(scanf("%lld:%lld", &h, &m) && (h>0 && m>=0)){
    double angle{};
    if (m==0){
      angle = (h*30 > 180 ? 360-(h*30): h*30);
      cout << fixed << setprecision(3) << angle << '\n';
    } else {
      angle = abs(((30.0*h + 0.5*m) - 6.0*m));
      cout << fixed << setprecision(3) << (angle <= 180.0 ? angle : 360.0-angle) << '\n';
    }
  }

  return 0;
}

