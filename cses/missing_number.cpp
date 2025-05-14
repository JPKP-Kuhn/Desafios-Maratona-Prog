#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n-1; i++){
    long long num;
    cin >> num;
    sum+=num;
  }

  long long soma = (n*(n+1))/2;

  cout << soma - sum << '\n';

  return 0;
}
