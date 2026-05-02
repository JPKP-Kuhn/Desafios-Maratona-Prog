#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fr first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

int main() { _
    ll n, m; cin >> n >> m;
    vll v(n), seq(m); for (ll &x : v) cin >> x;
    for (ll &y : seq) cin >> y;
    vll freq(n+2);

    for (ll i{}; i<m-1; i++){
        ll a=seq[i], b=seq[i+1];
        ll r=min(a,b), l=max(a,b);
        freq[r]++;
        freq[l+1]--;
    }
    for (ll i{1}; i<=n; i++){
        freq[i] += freq[i-1];
    }
    for (ll i{1}; i<m-1; i++){
        freq[seq[i]]--;
    }
    vll ans(10);
    for (ll i=0;i<n; i++){
        ans[v[i]] += freq[i+1];
    }
    for (ll i : ans) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}

