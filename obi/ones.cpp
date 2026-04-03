#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;

int main() { _
    ll n;
    while(cin >> n){
        ll resto = 1 % n;
        ll tam = 1;

        while(resto != 0){
            resto = (resto * 10 + 1) % n;
            tam++;
        }
        cout << tam << '\n';
    }

    return 0;
}

