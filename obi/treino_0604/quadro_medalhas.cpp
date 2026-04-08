#include <bits/stdc++.h>
#include <tuple>
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
    ll n; cin >> n;
    vector<pair<string, tuple<ll, ll, ll>>> pm;
    cin.ignore();
    while(n--){
        string s; getline(cin, s);
        stringstream ss(s);
        string pais; ll o, p, b;
        ss >> pais >> o >> p >> b;
        pm.pb({pais, {o, p, b}});
    }
    sort(all(pm), [](auto a, auto b){
            ll oa = get<0>(a.sc), ob = get<0>(b.sc);
            ll pa = get<1>(a.sc), pb = get<1>(b.sc);
            ll ba = get<2>(a.sc), bb = get<2>(b.sc);

            if (oa != ob) return oa > ob;
            else if (pa != pb) return pa > pb;
            else if (ba != bb) return ba > bb;
            return a.fr < b.fr;
            });

    for (auto [f, s] : pm){
        auto [o, p, b] = s;
        cout << f << ' ' << o << ' ' << p << ' ' << b << '\n';
    }

    return 0;
}

