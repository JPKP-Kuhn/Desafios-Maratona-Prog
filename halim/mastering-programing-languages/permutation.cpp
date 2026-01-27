#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int p[10], N=10;
  for(int i{}; i<N; ++i) p[i]=i;
  do {
    for (int i{}; i<N; ++i) printf("%c ", 'A'+p[i]);
    printf("\n");
  }while (next_permutation(p, p+N));

  return 0;
}

