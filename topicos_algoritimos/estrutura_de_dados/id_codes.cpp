#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string test;
  cin >> test;
  while(test != "#"){
    if (next_permutation(test.begin(), test.end())){
      cout << test << '\n';
    } else {
      cout << "No Successor\n";
    }
    cin >> test;
  }

  return 0;
}

