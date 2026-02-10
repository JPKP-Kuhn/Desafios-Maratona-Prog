#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  char c; cin >> c;
  if (c >= 48 && c <=57){
    cout << "IS DIGIT\n";
  } else {
    cout << "ALPHA\n";
    if (c >= 65 && c <=90){
      cout << "IS CAPITAL\n";
    } else {
      cout << "IS SMALL\n";
    }
  }

  return 0;
}

