#include <bits/stdc++.h>
using namespace std;

int m{};
int fib(int n){
  m++;
  if (n==0) return 0;
  if (n==1) return 1;

  return fib(n-1) + fib(n-2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    m=0;
    int r = fib(n);
    cout << "fib(" << n << ") = " << m-1 << ' ';
    cout << "calls = " << r << '\n';
  }

  return 0;
}

