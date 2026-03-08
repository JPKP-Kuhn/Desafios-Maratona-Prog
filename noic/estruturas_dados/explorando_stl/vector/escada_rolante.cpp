#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    ll tot{};
    ll desl{};
    for (ll i{}; i<n; i++){
        ll x; cin >> x;
        if (x < desl){
            tot += (x+10) - desl;
            desl = x + 10;
        } else{
            desl = x+10;
            tot+=10;
        }
    }

    cout << tot << '\n';

    return 0;
}

