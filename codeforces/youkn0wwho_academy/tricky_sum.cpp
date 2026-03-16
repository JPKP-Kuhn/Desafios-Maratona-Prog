#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t--){
        ll x; cin >> x;
        ll m = floor(log2(x));
        ll sa = (x*(1 + x))/2;

        for (ll i{}; i<=m; i++) {
            ll d = pow(2, i);
            sa -= 2*d;
        }
        cout << sa << '\n';

    }

    return 0;
}

