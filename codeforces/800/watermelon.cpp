#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
using ll = long long;

int main() {
  int w;
  scanf("%d", &w);
  w-=2;
  printf((w % 2 == 0 && w >= 2) ? "YES\n" : "NO\n");
  return 0;
}

