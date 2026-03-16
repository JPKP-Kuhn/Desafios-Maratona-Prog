#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll s, t; cin >> s >> t;

    ll count{};
    for (ll a{}; a<=s; a++){
        for (ll b{}; b<=s; b++){
            for (ll c{}; c<=s; c++){
                if (a + b + c <= s && a * b * c <= t) count++;
            }
        }
    }
    cout << count << '\n';

    return 0;
}

