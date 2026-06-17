#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;

int main() {
  _ ll n;
  cin >> n;
  unordered_set<string> s;
  unordered_map<string, string> m;
  unordered_map<string, bool> lo;
  while (n--) {
    string op, name, senha;
    cin >> op >> name;
    if (op == "register") {
      cin >> senha;

      if (s.count(name) > 0) {
        cout << "fail: user already exists\n";
      } else {
        m[name] = senha;
        s.insert(name);
        cout << "success: new user added\n";
      }
    } else if (op == "login") {
      cin >> senha;
      if (s.count(name) == 0) {
        cout << "fail: no such user\n";
      } else if (senha != m[name]) {
        cout << "fail: incorrect password\n";
      } else if (lo[name]) {
        cout << "fail: already logged in\n";
      } else {
        lo[name] = true;
        cout << "success: user logged in\n";
      }
    } else if (op == "logout") {
      if (s.count(name) == 0) {
        cout << "fail: no such user\n";
      } else if (!lo[name]) {
        cout << "fail: already logged out\n";
      } else {
        lo[name] = false;
        cout << "success: user logged out\n";
      }
    }
  }

  return 0;
}
