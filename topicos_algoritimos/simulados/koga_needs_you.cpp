#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  getline(cin, s);
  if (s.find("Luxray") != string::npos){
    cout << "Torterra, eu escolho voce!\n";
  } else if (s.find("Staraptor") != string::npos){
    cout << "Luxray, eu escolho voce!\n";
  } else if (s.find("Torterra") != string::npos){
    cout << "Staraptor, eu escolho voce!\n";
  }

  return 0;
}

