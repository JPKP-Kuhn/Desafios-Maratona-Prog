#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll mb = pow(10, 6) * 8;

ll m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> m;
  // 1 qubit -> 2 bits; 2 qubit -> 4bits ...
  // 2^qubit == bits;   
  m *= mb;

  double result = log(m) / log(2);
  cout << ceil(result) << '\n';


  return 0;
}

