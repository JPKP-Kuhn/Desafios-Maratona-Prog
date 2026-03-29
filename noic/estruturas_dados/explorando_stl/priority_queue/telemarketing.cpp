#include <bits/stdc++.h>
#include <functional>
#include <queue>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<pl, vpll, greater<pl>> vt;
    ll n, l; cin >> n >> l;
    vll tel_nl(n+1, 0);
    for (ll i{1}; i<=n; i++){
        vt.push({0, i});
        tel_nl[i]=0;
    }
    for (ll i{}; i<l; i++){
        ll t; cin >> t;

        ll ocu = vt.top().first;
        ll tel = vt.top().second;

        vt.pop();

        vt.push({t+ocu, tel});
        tel_nl[tel]++;
    }
    for (ll i=1; i<=n; i++){
        cout << i << ' ' << tel_nl[i] << '\n';
    }

    return 0;
}

