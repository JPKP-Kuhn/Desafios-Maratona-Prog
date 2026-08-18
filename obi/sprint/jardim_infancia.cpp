#include <bits/stdc++.h>
using namespace std;
#define _                                                                                          \
    ios_base::sync_with_stdio(false);                                                              \
    cin.tie(NULL);                                                                                 \
    cout.tie(NULL);
#define fr first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

struct point {
    long long x, y;
};

int main() {
    _ vector<point> P(8);
    for (ll i{1}; i <= 7; i++) {
        point p;
        cin >> p.x >> p.y;
        P[i] = p;
    }

    // 1 -
    point u;
    u.x = P[2].x - P[1].x;
    u.y = P[2].y - P[1].y;

    point v;
    v.x = P[3].x - P[1].x;
    v.y = P[3].y - P[1].y;

    // cos o = uv/(|u| * |v|)
    ll es = u.x * v.x + u.y * v.y;
    if (es <= 0) {
        cout << "N\n";
        return 0;
    }

    // 2 -
    ll x1 = P[2].x - P[1].x;
    ll y1 = P[2].y - P[1].y;
    ll comp1 = x1 * x1 + y1 * y1;

    ll x2 = P[3].x - P[1].x;
    ll y2 = P[3].y - P[1].y;
    ll comp2 = x2 * x2 + y2 * y2;

    if (comp1 != comp2) {
        cout << "N\n";
        return 0;
    }

    // 3 - colineares
    point vu, vv, m;
    vu.x = P[3].x - P[2].x;
    vu.y = P[3].y - P[2].y;

    vv.x = P[5].x - P[4].x;
    vv.y = P[5].y - P[4].y;

    m.x = P[4].x - P[3].x;
    m.y = P[4].y - P[3].y;

    ll prod = vu.x * vv.y - vu.y * vv.x;
    ll prod2 = vu.x * m.y - vu.y * m.x;
    if (prod != 0 || prod2 != 0) {
        cout << "N\n";
        return 0;
    }

    // 4 - pontos médios

    if (P[2].x + P[3].x != P[4].x + P[5].x || P[2].y + P[3].y != P[4].y + P[5].y) {
        cout << "N\n";
        return 0;
    }

    // 5 - segmento maior
    ll di1, di2;
    ll fx, fy;
    fx = P[3].x - P[2].x;
    fy = P[3].y - P[2].y;
    di1 = fx * fx + fy * fy;

    ll vx, vy;
    vx = P[5].x - P[4].x;
    vy = P[5].y - P[4].y;
    di2 = vx * vx + vy * vy;

    if (di1 <= di2) {
        cout << "N\n";
        return 0;
    }

    // 6 - seg perpendiculares
    point ref, r1, r2;
    ref.x = P[3].x - P[2].x;
    ref.y = P[3].y - P[2].y;

    r1.x = P[6].x - P[4].x;
    r1.y = P[6].y - P[4].y;

    r2.x = P[7].x - P[5].x;
    r2.y = P[7].y - P[5].y;

    ll ep1 = ref.x * r1.x + ref.y * r1.y;
    ll ep2 = ref.x * r2.x + ref.y * r2.y;

    if (ep1 != 0 || ep2 != 0) {
        cout << "N\n";
        return 0;
    }

    // 7 - mesmo comp
    ll seg1, seg2;
    point pri, pro;
    pri.x = P[6].x - P[4].x;
    pri.y = P[6].y - P[4].y;

    pro.x = P[7].x - P[5].x;
    pro.y = P[7].y - P[5].y;

    seg1 = pri.x * pri.x + pri.y * pri.y;
    seg2 = pro.x * pro.x + pro.y * pro.y;

    if (seg1 != seg2) {
        cout << "N\n";
        return 0;
    }

    // 8 - reta
    point vf;
    vf.x = P[3].x - P[2].x;
    vf.y = P[3].y - P[2].y;

    point w;
    w.x = P[1].x - P[2].x;
    w.y = P[1].y - P[2].y;

    ll lP1 = vf.x * w.y - vf.y * w.x;

    point g;
    g.x = P[6].x - P[2].x;
    g.y = P[6].y - P[2].y;

    ll lP6 = vf.x * g.y - vf.y * g.x;

    if (lP1 * lP6 >= 0) {
        cout << "N\n";
        return 0;
    }

    cout << "S\n";

    return 0;
}
