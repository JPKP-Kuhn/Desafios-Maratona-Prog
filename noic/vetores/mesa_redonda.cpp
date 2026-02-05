#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b; cin >> a >> b;
    int ca = a%3;
    int cb = b%3;

    if (cb == ca){
      cb = (cb+1)%3;
    }
    int c = 3 - ca - cb;
    cout << c << '\n';

    return 0;
}
