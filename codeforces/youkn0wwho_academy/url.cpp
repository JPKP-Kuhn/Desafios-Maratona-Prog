#include <bits/stdc++.h>
#include <regex>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s, username, pwd, profile, role, key; cin >> s;
  smatch match;

  regex userp("username=([0-9A-Za-z_@?!]+)");
  regex pwdp("pwd=([0-9A-Za-z_@?!]+)");
  regex profp("profile=([0-9A-Za-z_@?!]+)");
  regex rolep("role=([0-9A-Za-z_@?!]+)");
  regex keyp("key=([0-9A-Za-z_@?!]+)");

  if (regex_search(s, match, userp)) username = match[1];
  if (regex_search(s, match, pwdp)) pwd = match[1];
  if (regex_search(s, match, profp)) profile = match[1];
  if (regex_search(s, match, rolep)) role = match[1];
  if (regex_search(s, match, keyp)) key = match[1];

  cout << "username: " << username << '\n';
  cout << "pwd: " << pwd << '\n';
  cout << "profile: " << profile << '\n';
  cout << "role: " << role << '\n';
  cout << "key: " << key << '\n';
  return 0;
}

