#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin>>n;
  string w{};
  while(n--){
    char x; cin >> x;
    w.push_back(x);
  }
  ll c{};
  ll i{};
  while(i < (int)w.size()){
    if (w[i]=='1' && w[i+1]=='0' && w[i+2]=='0'){
      c++; i+=3;
    } else i++;
  }
  cout << c << '\n';

  return 0;
}

