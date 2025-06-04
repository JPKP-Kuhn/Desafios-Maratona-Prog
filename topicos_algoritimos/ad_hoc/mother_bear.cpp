#include <bits/stdc++.h>
#include <cctype>
#include <ios>
#include <string>
using namespace std;
using ll = long long;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string phrase;
  while(getline(cin, phrase) && phrase != "DONE") {

    string result;
    for (char c : phrase) {
      if (!isspace(c) && !ispunct(c)) {
        result += tolower(c);
      } 
    }

    bool palindrome = true;

    for (ll i = 0, s = result.length(); i < s; i++) {
      if (result[i] != result[s-i-1]){
        palindrome = false;
        break;
      }
    }

    cout << (palindrome ? "You won't be eaten!" : "Uh oh..") << '\n';
  }

  return 0;
}

