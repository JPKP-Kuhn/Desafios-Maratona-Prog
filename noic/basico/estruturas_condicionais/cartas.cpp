#include <bits/stdc++.h>
using namespace std;

int main() {
  map<int, int>c;
  for (int i{}; i<3; ++i){
    int x; cin >> x;
    c[x]++;
  }
  for (auto &[k, v] : c) if (v==1) cout << k << '\n';

  return 0;
}

