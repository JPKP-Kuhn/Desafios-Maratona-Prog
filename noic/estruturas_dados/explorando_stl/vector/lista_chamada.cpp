#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k; cin >> n >> k;
    k--;
    vector<string> a(n);
    for (string &x : a) cin >> x;
    sort(a.begin(), a.end());
    cout << a[k] << '\n';

    return 0;
}

