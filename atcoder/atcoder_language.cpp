#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s; cin >> s;
  if (s == "red"){
    cout << "SSS\n";
  } else if (s == "blue"){
    cout << "FFF\n";
  } else if (s == "green"){
    cout << "MMM\n";
  } else {
    cout << "Unknown\n";
  }

  return 0;
}

