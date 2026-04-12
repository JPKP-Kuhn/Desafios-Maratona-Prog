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
    unordered_map<ll, ll> a;
    for (ll i{}; i<n; i++){
        ll x; cin >> x;
        a[x]++;
    }
    vll b(m);
    for (ll i{}; i<m; i++){
        cin >> b[i];
    }

    bool f=false;
    ll num;
    unordered_map<ll, ll> somas;
    for (ll i : b){
        bool ok = false;
        if (a.count(i))
            ok = true;

        if (!ok){
            for (auto &[k, v] : somas){
                if (somas.count(i-k)){
                    ok = true; break;
                }
            }
        }

        if (!ok){
            num = i; f=true;
            break;
        }
        somas[i]++;
    }

    if (f) cout << num << '\n';
    else cout << "sim\n";

    return 0;
}

