#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    set<ll> s;
    while(n--){
        ll x; cin >> x;
        s.insert(x);
    }

    cout << s.size() << '\n';
    return 0;
}

