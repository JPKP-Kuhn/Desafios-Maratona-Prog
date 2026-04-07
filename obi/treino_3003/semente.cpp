#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
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


// M_PI para número PI
const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo
const ll MOD = 1e9+7;    // Valor comum para aritmética modular, números muito grandes
const ll EPS = -1e9;     // Valor para comparar double

struct point {
    double x, y;
    point() {x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    };
};

int main() { _
    ll f, r; cin >> f >> r;
    ll c{};
    vll v(r); for(ll &x : v) cin >> x;
    ll d1 = v[0]-1;
    ll d2 = f-v[r-1];
    c = max(d1, d2);
    for (ll i{}; i < r-1; i++){
        ll d = v[i+1] - v[i];
        c = max(c, d/2);
    }

    cout << c << '\n';

    return 0;
}

