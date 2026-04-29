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
    unordered_map<ll, ll> forca = {
        {4, 0},
        {5, 1},
        {6, 2},
        {7, 3},
        {12, 4},
        {11, 5},
        {13, 6},
        {1, 7},
        {2, 8},
        {3, 9}
    };
    ll n; cin >> n;
    ll va{}, vb{};
    while(n--){
        vll adal(3), bern(3);
        for (ll &x : adal) cin >> x;
        for (ll &y : bern) cin >> y;
        ll lva{}, lvb{};
        // sort(all(adal), [&](ll a, ll b){
        //         return forca[a] < forca[b];
        //         });
        // sort(all(bern), [&](ll a, ll b){
        //        return forca[a] < forca[b];
        //         });
        for (ll i{}; i<3; i++){
            ll fa = forca[adal[i]], fb = forca[bern[i]];
            if (fa >= fb) lva++;
            else lvb++;
        }
        if (lva >= lvb) va++;
        else vb++;
    }
    cout << va << ' ' << vb << '\n';

    return 0;
}

