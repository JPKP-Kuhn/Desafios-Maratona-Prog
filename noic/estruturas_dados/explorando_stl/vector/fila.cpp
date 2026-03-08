#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    vll v(n);
    unordered_map<ll, ll> cont;
    for (ll i{}; i<n; i++){
        ll x; cin >> x;
        v[i]=x;
        cont[x]++;
    }
    ll m; cin >> m;
    for (ll i{}; i<m; i++){
        ll x; cin >> x;
        cont[x]--;
    }
    bool f=true;
    for (ll i{}; i<n; i++){
        if (cont[v[i]]){
            if (f){
                cout << v[i];
                f=false;
            } else cout << ' ' << v[i];
        }
    }
    cout << '\n';

    return 0;
}

