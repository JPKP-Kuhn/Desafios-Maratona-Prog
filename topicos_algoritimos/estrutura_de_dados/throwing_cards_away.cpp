#include <bits/stdc++.h>
#include <cstdio>
#include <queue>
using namespace std;
using ll = long long;

int n;
int main() {
  for (;;) {
    scanf("%d", &n);
    if (n == 0) {break;}

    queue<int> cards;
    for (int i = 1; i <= n; i++) {
      cards.push(i);
    }

    queue<int> discarded;
    int c, d;
    while(cards.size() > 1) {
      c = cards.front();
      cards.pop();
      discarded.push(c);
      d = cards.front();
      cards.pop();
      cards.push(d);
    }

    printf("Discarded cards:");
    int s = discarded.size();
    for (int i = 0; i < s-1; i++){
        printf(" %d,", discarded.front());
        discarded.pop();
    }
    printf(" %d\n", discarded.front());
    printf("Remaining card: %d\n", cards.front());
  }
  return 0;
}

