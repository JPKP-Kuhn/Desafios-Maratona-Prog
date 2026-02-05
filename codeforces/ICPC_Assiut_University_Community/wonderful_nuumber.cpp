#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  if (n%2==0){
    cout << "NO\n";
  } else {
    uint32_t x = n;
    string s;
    while(x>0){
      s.push_back((x & 1) ? '1' : '0');
      x >>= 1;
    }
    bool f=true;
    ll len = s.size();
    for (ll i{}; i<len/2 + 1; i++){
      if (s[i] != s[len - i - 1]){
        f=false; break;
      }
    }
    cout << (f ? "YES" : "NO") << '\n';
  }

  return 0;
}

