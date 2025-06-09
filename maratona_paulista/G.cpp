#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string e{};
  cin >> e;

  if (e[3] == 'S' && e[4] == 'P') {
    cout << 'S' << '\n';
    return 0;
  }
  if (e[3] == 'S' && e[4] == '?' || e[3] == '?' && e[4] == 'P') {
    cout << 'T' << '\n';
    return 0;
  }

  cout << 'N' << '\n';
  return 0;
}

