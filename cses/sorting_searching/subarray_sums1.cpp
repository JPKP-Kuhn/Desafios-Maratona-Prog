#include <bits/stdc++.h>
using namespace std;
#define _                                                                                          \
    ios_base::sync_with_stdio(false);                                                              \
    cin.tie(NULL);                                                                                 \
    cout.tie(NULL);
#define fr first
#define sc second
#define pb push_back

using ll = long long;
using vll = vector<ll>;

int main() {
    _ ll n, x;
    cin >> n >> x;
    vll v(n);
    for (ll &s : v)
        cin >> s;
    ll c{}, i{}, j{-1}, soma{};
    // sliding window
    while (j < n - 1) {
        soma += v[++j];

        while (i < j && soma > x)
            soma -= v[i++];

        if (soma == x) {
            c++;
            soma -= v[i++];
        }
    }
    cout << c << '\n';

    return 0;
}
