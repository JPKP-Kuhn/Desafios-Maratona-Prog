#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int test;
  cin >> test;
  while (test--){
    int seconds = 0;
    string screenS;
    string screenT;
    cin >> screenS >> screenT;
    
    int lenS = screenS.length();
    int lenT = screenT.length();
    
    for (int i = 1; i <= min(lenS, lenT); i++){
      if (screenS.substr(0, i) == screenT.substr(0, i)) seconds = i;
    }
    cout << lenS + lenT - max(seconds, 1) + 1 << '\n';
  }
  return 0;
}
