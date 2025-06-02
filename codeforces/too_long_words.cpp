#include <bits/stdc++.h>
#include <ios>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll maxn = pow(10, 5) + 10;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  while (n--) {
    string w;
    cin >> w;

    if (w.length() > 10) {
      string nw = "";
      nw += w[0];
      string count = to_string(w.length()-2);
      nw += count;
      nw += w[w.length()-1];
      cout << nw << endl;
    } else {
      cout << w << endl;
    }
  }

  return 0;
}

