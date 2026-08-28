#include <bits/stdc++.h>
using namespace std;
#define _                                                                                          \
    ios_base::sync_with_stdio(false);                                                              \
    cin.tie(NULL);                                                                                 \
    cout.tie(NULL);
#define fr first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

int main() {
    _ ll n, x;
    cin >> n >> x;
    ll soma{};
    map<ll, ll> m{};
    m[0]++;
    ll c{};
    for (ll i{}; i < n; i++) {
        ll s;
        cin >> s;
        soma += s;
        c += m[soma - x];
        m[soma]++;
    }
    cout << c << '\n';

    return 0;
}
