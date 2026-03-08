#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    vll v;
    for (ll i{}; i<n; i++){
        ll x; cin >> x;
        if (x==0) v.pop_back();
        else v.push_back(x);
    }
    ll soma{};
    for (ll x : v){
        soma += x;
    }
    cout << soma << '\n';


    return 0;
}

