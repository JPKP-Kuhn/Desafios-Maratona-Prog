#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;


int main() { _
    ll n, k; cin >> n >> k;
    vll v(n); for (ll &x : v) cin >> x;
    unordered_map<ll, ll>freq;
    freq[0]=1;

    ll soma{};
    ll c{};
    for (ll i{}; i<n; i++){
        soma += v[i];

        if (freq.count(soma-k))
            c += freq[soma-k];

        freq[soma]++;
    }

    cout << c << '\n';

    return 0;
}

