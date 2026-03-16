#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string n; cin >> n;

    ll c{};
    while(n.size()>1){
        ll sum{};
        c++;
        for (char c : n){
            sum += c-'0';
        }
        n = to_string(sum);
    }

    cout << c << '\n';

    return 0;
}

