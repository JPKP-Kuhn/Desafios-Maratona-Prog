#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll a, b, c;
  cin >> a >> b >> c;
  //vll valores = {a, b, c};
  //sort(valores.begin(), valores.end());

  ll conv1 = a * b;
  ll conv2 = conv1/c;

  if (conv2 == 1){
    cout << "S\n";
  } else{
    cout << "N\n";
  }
  return 0;
}

