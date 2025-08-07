#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string emoji(string s){
  if (s == "rest"){
    return "\U0001F60E"; //  -> SMILING FACE WITH SUNGLASSES (tem "face")
  } else if (s == "leg"){
    return "\U0001FA7F"; //  -> MECHANICAL LEG (tem "leg")
  } else if (s == "arm" || s == "biceps"){
    return "\U0001FA7E"; //  -> MECHANICAL ARM (tem "arm")
  } else {
    return "?"; // fallback
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;
  cin.ignore();

  vector<string> seq;
  for (ll i = 0; i < n; i++) {
    string s;
    getline(cin, s);
    if (s.find("leg") != string::npos){
      seq.push_back(emoji("leg"));
    } else if (s.find("rest") != string::npos){
      seq.push_back(emoji("rest"));
    } else if (s.find("arm") != string::npos || s.find("biceps") != string::npos){
      seq.push_back(emoji("arm"));
    } else {
      seq.push_back("?"); // fallback, shouldn't happen
    }
  }

  vector<string> calendar(31);
  for (ll i = 0; i < 31; i++) {
    calendar[i] = seq[i % seq.size()];
  }

  for (ll week = 0; week < 5; week++) {
    cout << (week + 1) << ' ';
    for (ll day = 0; day < 7; day++) {
      ll idx = week * 7 + day;
      if (idx < 31) {
        cout << calendar[idx];
      }
    }
    cout << '\n';
  }

  return 0;
}

