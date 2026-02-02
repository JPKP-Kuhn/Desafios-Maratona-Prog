#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  double x; cin >> x;
  if (x == (long long)x){
    cout << "int " << (long long)x << '\n';
  } else {
    cout << "float " << (long long)x << ' ' << x - (long long)x << '\n';
  }

  return 0;
}

