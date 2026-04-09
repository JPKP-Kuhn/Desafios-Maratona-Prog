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


bool primo(ll x){
    if (x < 2) return false;
    if (x % 2 == 0) return x == 2;
    for (ll i=3; i*i <= x; i+=2) 
        if (x % i == 0) return false;

    return true;
}
int main() { _
    ll n; cin >> n;
    ll sv{};
    ll c=0;
    while(c < 10){
        if (primo(n)){
            c++; sv+=n;
        }
        n++;
    }
    cout << sv << " km/h\n";
    ll dist = 60 * 1e6;
    ll tempo = dist/sv;
    cout << tempo << " h / " << tempo/24 << " d\n";

    return 0;
}

