#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll l;
  while(cin >> l && l){
    string s;
    int dx=1, dy{}, dz{};
    for (ll i{}; i<l-1; i++){
      cin >> s;
      if (s == "No") continue;

      int nx=dx, ny=dy, nz=dz;
      if (s == "+y") {
        ny=dx; nx=-dy; nz=dz;
      } else if (s == "-y") {
        ny=-dx; nx=dy; nz=dz;
      } else if (s == "+z") {
        nz=dx; nx=-dz; ny=dy;
      } else if (s == "-z"){
        nz=-dx; nx=dz; ny=dy;
      }
      dx = nx; dy=ny; dz=nz;
    }

    if (dx==1) cout << "+x\n";
    else if (dx==-1) cout << "-x\n";
    else if (dy==1) cout << "+y\n";
    else if (dy==-1) cout << "-y\n";
    else if (dz==1) cout << "+z\n";
    else if (dz==-1) cout << "-z\n";
  }
  return 0;
}

