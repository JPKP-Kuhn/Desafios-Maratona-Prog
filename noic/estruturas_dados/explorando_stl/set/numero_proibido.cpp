#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    set<ll> pro;
    while(n--){
        ll x; cin >> x;
        pro.insert(x);
    }
    ll o;
    while(cin >> o){
        if (pro.find(o) != pro.end()) cout << "sim\n";
        else cout << "nao\n";
    }

    return 0;
}

