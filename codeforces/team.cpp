#include <bits/stdc++.h>
#include <sstream>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll maxn = pow(10, 5) + 10;

ll n;
int main() {
  cin >> n;

  vll quest[n];
  cin.ignore();
  for (ll i =0; i< n; i++) {
    string line;
    getline(cin, line);

    stringstream ss(line);
    ll num;
    while(ss >> num) {
      quest[i].push_back(num);
    }
  }

  ll sure = 0;
  for (ll i = 0; i < n; i++) {
    ll count = 0;
    for (ll j : quest[i]) {
      if (j == 1) count++;
    }
    if (count >= 2) sure++;
  }

  cout << sure << endl;
  return 0;
}

