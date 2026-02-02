#include <iostream>

using namespace std;

int main(){
    int S, M; cin >> S >> M;
    // S = M*x + c
    // c = 2*x
    int x = S/(M+2);
    cout << 2*x << '\n';

    return 0;
}
