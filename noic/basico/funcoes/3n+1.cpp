#include <bits/stdc++.h>
using namespace std;

long long m{};
long long algo(long long x){
  m++;
  if (x==1) return x;
  else if (x%2==1){
    algo(3*x + 1);
  } else {
    algo(x/2);
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long ta, tb;
  while(cin >> ta >> tb){
    long long a=min(ta, tb), b=max(ta,tb);
    long long r{};
    for (long long i=a; i<=b; i++){
      algo(i);
      r=max(r, m);
      m=0;
    }

    cout << ta << ' ' <<  tb << ' ' << r << '\n';
  }

  return 0;
}

